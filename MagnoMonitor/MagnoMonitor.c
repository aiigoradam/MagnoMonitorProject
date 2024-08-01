//==============================================================================
// Title:		Magnetic field monitor and analyzer.
// Description:	The program receives measured data of a magnetic field in three
//				different axes via RS-232 communication port and displays the
// 				data on a  3D graph, as well as calculating the magnitude and
//				displaying it on a chart in real-time. Once data acquisition
//				is complete, the  program calculates the Fourier transform of
//				the signal and displays the magnitude on a graph.
//==============================================================================

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include <cviauto.h>
#include "cw3dgrph.h"
#include <analysis.h>
#include <utility.h>
#include <rs232.h>
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include "MagnoMonitor.h"
#include "ComConfigDLL.h"

//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
#define NUM_ELEMENTS	3 								// x, y, z vector
#define DATA_SIZE 		(sizeof(double) * NUM_ELEMENTS) // size of x, y, z vector
#define PACKET_SIZE  	(DATA_SIZE + 1) 				// Include space for the checksum byte

#define NUM_VECTORS 					16
#define MAX_ITEMS_IN_QUEUE_READ_BLOCK 	(NUM_VECTORS * DATA_SIZE)
#define MAX_ITEMS_IN_QUEUE 				(1000 * MAX_ITEMS_IN_QUEUE_READ_BLOCK)

#define TIME_FORMAT_STRING	"%H:%M:%S"

//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------
void CVICALLBACK ComCallback (int portNumber, int eventMask, void *callbackData);
static int CVICALLBACK ReadDataThreadFunction (void *functionData);
void ToggleConnectLED();
static void CVICALLBACK ProcessDataFromQueueCallback(CmtTSQHandle queueHandle, unsigned int event, int value, void *callbackData);
void StripChartTimeAxis();
void VisualizeData();
void CalculateFourierTransform();
void FreeDataArrays();
void WriteToFile();

//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
int panelHandle;
int	tabHandle_LiveChart;
int tabHandle_3DGraph;
int tabHandle_FFT;
int plotHandleFFT;
int writeToFile;
char dirname[MAX_PATHNAME_LEN];
char pathname[MAX_PATHNAME_LEN];
char *dateTimeBuffer;
double startTime;
double deltaTime;
FILE *filehandle;
CmtThreadFunctionID threadFunctionId;
CmtThreadLockHandle lock;
CmtTSQHandle tsqHandle;
CAObjHandle graphHandle;
CAObjHandle plotHandle;
CAObjHandle plotsHandle;

double fs; // Sampling rate
double* x = NULL;
double* y = NULL;
double* z = NULL;
unsigned int shift; // The number of vectors received

//-----------------------------------------------------------------------------
// Program entry-point
//-----------------------------------------------------------------------------
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "MagnoMonitor.uir", PANEL)) < 0)
		return -1;

	// Get the panel handle associated with a tab page with GetPanelHandleFromTabPage
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 0, &tabHandle_LiveChart);
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 1, &tabHandle_3DGraph);
	GetPanelHandleFromTabPage (panelHandle, PANEL_TAB, 2, &tabHandle_FFT);

	// Get Handle of Graph and first Plot from the ActiveX control
	GetObjHandleFromActiveXCtrl (tabHandle_3DGraph, TABPANEL_2_3DGRAPH, &graphHandle);
	CW3DGraphLib__DCWGraph3DGetPlots (graphHandle, NULL, &plotsHandle);
	CW3DGraphLib_CWPlots3DItem (plotsHandle, NULL, CA_VariantInt(1), &plotHandle);

	// Display default directory and filename
	GetProjectDir (dirname);
	MakePathname (dirname, "DataFile.txt", pathname);
	SetCtrlVal (tabHandle_LiveChart, TABPANEL_PATH, pathname);

	DisplayPanel (panelHandle);

	// Bug: opening tab 1 (3D graph), while the program executes, may stop data acquisition
	// Temporary solution: Force open 3D graph, then go back to the default tab
	SetActiveTabPage (panelHandle, PANEL_TAB, 1);
	SetActiveTabPage (panelHandle, PANEL_TAB, 0);

	RunUserInterface ();
	DiscardPanel (panelHandle);
	return 0;
}

//-----------------------------------------------------------------------------
// Configure receiver com port
//-----------------------------------------------------------------------------
int CVICALLBACK ConfigCallBack (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// Perform configuration for the port
			DLLConfigPort();

			if(!comport || RS232Error)
				return 0;  // Configuration wasn't performed

			// Disable the Configure button
			SetCtrlAttribute (panelHandle, PANEL_COM_CONFIG, ATTR_DIMMED, 1);

			// Start the thread function to read data
			CmtScheduleThreadPoolFunction (DEFAULT_THREAD_POOL_HANDLE, ReadDataThreadFunction, 0, &threadFunctionId);

			// Create a new lock for synchronization
			CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &lock);

			// Creates a thread safe queue for use in the program
			CmtNewTSQ(MAX_ITEMS_IN_QUEUE, sizeof(char), 0, &tsqHandle);

			// Install the callback to read and process the data from the thread-safe queue.
			CmtInstallTSQCallback(tsqHandle, EVENT_TSQ_ITEMS_IN_QUEUE, MAX_ITEMS_IN_QUEUE_READ_BLOCK,
								  ProcessDataFromQueueCallback, NULL, CmtGetCurrentThreadID(), NULL);
			break;
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Start reading data and processing
//-----------------------------------------------------------------------------
int CVICALLBACK Start (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// Enable the stop button
			SetCtrlAttribute(panelHandle, PANEL_STOP, ATTR_DIMMED, 0);
			// Disable the start button
			SetCtrlAttribute(panelHandle, PANEL_START, ATTR_DIMMED, 1);
			// Disable the write toggle button
			SetCtrlAttribute(panelHandle, PANEL_WRITE_TO_FILE, ATTR_DIMMED, 1);
			// Disable the select file button
			SetCtrlAttribute(tabHandle_LiveChart, TABPANEL_SELECT_FILE, ATTR_DIMMED, 1);
			// Disable path text editing
			SetCtrlAttribute(tabHandle_LiveChart, TABPANEL_PATH, ATTR_NO_EDIT_TEXT , 1);
			// Disable the window and sample rate control
			SetCtrlAttribute(panelHandle, PANEL_WINDOW, ATTR_DIMMED, 1);
			SetCtrlAttribute(panelHandle, PANEL_SR, ATTR_DIMMED, 1);

			// Get the sampling rate of the signal
			GetCtrlVal(panelHandle, PANEL_SR, &fs);
			
			// Define the stip chart's time axis and the window
			StripChartTimeAxis();

			// Visual synchronization
			ProcessDrawEvents ();

			// Create file to write if needed
			WriteToFile();

			// Set DTR ON to establish connection
			ComSetEscape (comport, SETDTR);
			
			// Send break signal to start transmission
			ComBreak (comport, 25);
			break;
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Thread callback for data reading
//-----------------------------------------------------------------------------
static int CVICALLBACK ReadDataThreadFunction (void *functionData)
{
	if (GetComLineStatus (comport) & kRS_DSR_ON)
		ToggleConnectLED(); // Transmitter's com connection present
	
	// Minimum number of bytes the input queue must contain before sending the LWRS_RECEIVE.
	int notify_count = 25;
	
	InstallComCallback (comport, LWRS_DSR | LWRS_RECEIVE, notify_count, 0, ComCallback, 0);
	return 0;
}

//-----------------------------------------------------------------------------
// Com callback that runs inside it's own thread
//-----------------------------------------------------------------------------
void CVICALLBACK ComCallback (int portNumber, int eventMask, void *callbackData)
{
	char packet[PACKET_SIZE];
	double xyz_vector[NUM_ELEMENTS];
	double magnitude;
	static double min = 0.0;
	static double max = 0.0;
	static int n = 0;
	char checksum;
	int i;

	if (eventMask & LWRS_DSR)
		ToggleConnectLED(); // Transmitter's com connected

	if (eventMask & LWRS_RECEIVE)
	{
		CmtGetLock (lock);

		// Receive the packet over the communication channel
		ComRd(comport, packet, PACKET_SIZE);

		// Calculate checksum
		for (i = 0, checksum = 0; i < DATA_SIZE; i++)
			checksum ^= packet[i]; // XOR operation

		if (checksum == packet[DATA_SIZE])
		{
			// Checksum is valid

			// Extract x, y, z from the data in the packet
			memcpy(xyz_vector, packet, DATA_SIZE);

			// Display the data in numeric controls.
			SetCtrlVal(tabHandle_LiveChart, TABPANEL_X, xyz_vector[0]);
			SetCtrlVal(tabHandle_LiveChart, TABPANEL_Y, xyz_vector[1]);
			SetCtrlVal(tabHandle_LiveChart, TABPANEL_Z, xyz_vector[2]);

			// Calculate magnitude
			MatrixNorm (xyz_vector, 1, NUM_ELEMENTS, NORM_TYPE_2, &magnitude);

			// Update the strip chart and magnitude value
			PlotStripChartPoint(tabHandle_LiveChart, TABPANEL_STRIPCHART, magnitude);
			SetCtrlVal (tabHandle_LiveChart, TABPANEL_MAG, magnitude);

			// Calculate and display min and max magnitudes
			if (magnitude < min || min == 0.0)
				min = magnitude;
			if (magnitude > max || max == 0.0)
				max = magnitude;
			SetCtrlVal (tabHandle_LiveChart, TABPANEL_MINB, min);
			SetCtrlVal (tabHandle_LiveChart, TABPANEL_MAXB, max);

			// Write x, y, z values to a file
			if (writeToFile)
			{
				int bufferLen;
				double timef = startTime + n * deltaTime;

				// Format a given time into a string buffer according to the TIME_FORMAT_STRING.
				bufferLen = FormatDateTimeString (timef, TIME_FORMAT_STRING, NULL, 0);
				dateTimeBuffer = malloc (bufferLen + 1);
				FormatDateTimeString (timef, TIME_FORMAT_STRING, dateTimeBuffer, bufferLen + 1 );

				// Write data to the file
				fprintf(filehandle, "%s \t %.2f \t %.2f \t %.2f\n", dateTimeBuffer,
						xyz_vector[0], xyz_vector[1], xyz_vector[2]);

			}

			// Update and display the number of vectors received
			SetCtrlVal(panelHandle, PANEL_NUMERIC, n);
			n++;

			// Write the packet to the thread-safe queue for further processing
			CmtWriteTSQData(tsqHandle, packet, DATA_SIZE, TSQ_INFINITE_TIMEOUT, NULL);
		}
		else
		{
			// Checksum is invalid
			Stop(panelHandle, 1, 1, NULL, 1, 1);
			MessagePopup ("Error", "Invalid Checksum. Data lost.\n");
		}

		CmtReleaseLock (lock);
	}
}

//-----------------------------------------------------------------------------
// Read and Process data from the thread safe queue Callback function
//-----------------------------------------------------------------------------
static void CVICALLBACK ProcessDataFromQueueCallback(CmtTSQHandle queueHandle, unsigned int event,
		int value, void *callbackData)
{
	int i;
	int numItemsRead;
	char readBuffer[MAX_ITEMS_IN_QUEUE];
	int size;
	int readBuffer_shift;

	// Use a buffer to read the data from the thread-safe queue.
	numItemsRead = CmtReadTSQData(tsqHandle, readBuffer, MAX_ITEMS_IN_QUEUE_READ_BLOCK, 0, 0);

	if (numItemsRead == MAX_ITEMS_IN_QUEUE_READ_BLOCK)
	{
		// Resize the arrays to accommodate the new data
		size = (NUM_VECTORS + shift) * sizeof(double);
		x = (double*)realloc(x, size);
		y = (double*)realloc(y, size);
		z = (double*)realloc(z, size);

		for(i = 0; i < NUM_VECTORS; i++)
		{
			// Extract x, y, z values separately from the data in readBuffer
			readBuffer_shift = i * DATA_SIZE;
			memcpy(x + i + shift, readBuffer + readBuffer_shift, sizeof(double));
			memcpy(y + i + shift, readBuffer + readBuffer_shift + sizeof(double), sizeof(double));
			memcpy(z + i + shift, readBuffer + readBuffer_shift + 2 * sizeof(double), sizeof(double));
		}

		// Visualize the data
		VisualizeData();

		shift += NUM_VECTORS;
	}
	else
	{
		Stop(panelHandle, 1, 1, NULL, 1, 1);
		MessagePopup ("Error", "Failed to read from thread-safe queue.\n");
	}
}

//-----------------------------------------------------------------------------
// Visualize the data by plotting it as a 3D surface
//-----------------------------------------------------------------------------
void VisualizeData()
{
	static int tableRowsInserted = 0;
	VARIANT xVar, yVar, zVar;
	CA_VariantSetEmpty(&xVar);
	CA_VariantSetEmpty(&yVar);
	CA_VariantSetEmpty(&zVar);

	if (!tableRowsInserted)
	{
		InsertTableRows (tabHandle_3DGraph, TABPANEL_2_TABLE,-1, NUM_VECTORS, VAL_CELL_NUMERIC);
		tableRowsInserted = 1;
	}
	// Display vector values
	SetTableCellRangeVals (tabHandle_3DGraph, TABPANEL_2_TABLE, MakeRect (1, 1, NUM_VECTORS, 1), x + shift, VAL_ROW_MAJOR);
	SetTableCellRangeVals (tabHandle_3DGraph, TABPANEL_2_TABLE, MakeRect (1, 2, NUM_VECTORS, 1), y + shift, VAL_ROW_MAJOR);
	SetTableCellRangeVals (tabHandle_3DGraph, TABPANEL_2_TABLE, MakeRect (1, 3, NUM_VECTORS, 1), z + shift, VAL_ROW_MAJOR);

	// Create variants from the 1D arrays
	CA_VariantSet1DArray(&xVar, CAVT_DOUBLE, NUM_VECTORS, x + shift);
	CA_VariantSet1DArray(&yVar, CAVT_DOUBLE, NUM_VECTORS, y + shift);
	CA_VariantSet1DArray(&zVar, CAVT_DOUBLE, NUM_VECTORS, z + shift);

	// Plot x, y, and z as a 3D surface
	CW3DGraphLib__DCWGraph3DPlot3DMesh(graphHandle, NULL, xVar, yVar, zVar, CA_DEFAULT_VAL);

	// Clear the variants to release memory
	CA_VariantClear(&xVar);
	CA_VariantClear(&yVar);
	CA_VariantClear(&zVar);
}

//-----------------------------------------------------------------------------
// Define the stip chart's time axis and the window
//-----------------------------------------------------------------------------
void StripChartTimeAxis()
{
	int window;

	// Get the current system time
	GetCurrentDateTime(&startTime);
	// Set the charts start time according to the system time
	SetCtrlAttribute(tabHandle_LiveChart, TABPANEL_STRIPCHART, ATTR_XAXIS_OFFSET, startTime);

	// Calculate the time elapsed between consecutive measures
	deltaTime = 1.0 / fs;
	// Set the charts increment according to the sampling rate
	SetCtrlAttribute(tabHandle_LiveChart, TABPANEL_STRIPCHART, ATTR_XAXIS_GAIN, deltaTime);

	// Set the time window display of the strip chart
	GetCtrlVal(panelHandle, PANEL_WINDOW, &window);
	SetCtrlAttribute (tabHandle_LiveChart, TABPANEL_STRIPCHART, ATTR_POINTS_PER_SCREEN, (int)(window * fs));
}


//-----------------------------------------------------------------------------
// Stop the data acquisition, calculate and plot fft
//-----------------------------------------------------------------------------
int CVICALLBACK Stop (int panel, int control, int event,
					  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// Set DTR OFF to stop the transmission
			ComSetEscape (comport, CLRDTR);
			// Disable the stop button
			SetCtrlAttribute(panelHandle, PANEL_STOP, ATTR_DIMMED, 1);
			// Enable the PLOT FFT button
			SetCtrlAttribute(tabHandle_FFT, TABPANEL_3_PLOT_FFT, ATTR_DIMMED, 0);
			break;
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Cleanup the program and quit
//-----------------------------------------------------------------------------
int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if (threadFunctionId)
			{
				// Wait for thread function Completion
				CmtWaitForThreadPoolFunctionCompletion (DEFAULT_THREAD_POOL_HANDLE,
														threadFunctionId, OPT_TP_PROCESS_EVENTS_WHILE_WAITING);
				// Release thread function
				CmtReleaseThreadPoolFunctionID (DEFAULT_THREAD_POOL_HANDLE, threadFunctionId);
			}
			if (tsqHandle)
			{
				// Discare thread safe queue task
				CmtDiscardTSQ(tsqHandle);
			}
			if (port_open)
			{
				FlushInQ (comport);
				FlushOutQ (comport);
				ProcessSystemEvents ();
				RS232Error = CloseCom (comport);
				if (RS232Error) DisplayRS232Error ();
			}
			if (filehandle)
				fclose (filehandle);
			CmtDiscardLock (lock);
			CA_DiscardObjHandle (plotHandle);
			CA_DiscardObjHandle (plotsHandle);
			free(x);
			x = NULL;
			free(y);
			y = NULL;
			free(z);
			z = NULL;
			free(dateTimeBuffer);
			dateTimeBuffer = NULL;
			QuitUserInterface (0);
			break;
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Calculate and plot the Fourier Transform when data acquisition has finished
//-----------------------------------------------------------------------------
int CVICALLBACK PlotFFT (int panel, int control, int event,
						 void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(!shift) 
				return 0; // Not enough vectors for fft

			int i;
			int num_vectors = shift;
			double xfft_real[num_vectors], yfft_real[num_vectors], zfft_real[num_vectors];
			double xfft_imag[num_vectors], yfft_imag[num_vectors], zfft_imag[num_vectors];
			double 	freqArray[num_vectors];
			double 	xmagArray[num_vectors];
			double 	ymagArray[num_vectors];
			double 	zmagArray[num_vectors];
			double 	phaseArray[num_vectors];
			double 	matrix[NUM_ELEMENTS][num_vectors];
			double 	mag_matrix[num_vectors][NUM_ELEMENTS];
			double  magnitudeArray[num_vectors];
			double  df;

			// Apply window to the segment to reduce spectral leakage
			HamWin (x, num_vectors);
			HamWin (y, num_vectors);
			HamWin (z, num_vectors);

			// Calculate the FFT
			Copy1D (x, num_vectors, xfft_real);
			Copy1D (y, num_vectors, yfft_real);
			Copy1D (z, num_vectors, zfft_real);
			ReFFT (xfft_real, xfft_imag, num_vectors);
			ReFFT (yfft_real, yfft_imag, num_vectors);
			ReFFT (zfft_real, zfft_imag, num_vectors);
			ToPolar1D (xfft_real, xfft_imag, num_vectors, xmagArray, phaseArray);
			ToPolar1D (yfft_real, yfft_imag, num_vectors, ymagArray, phaseArray);
			ToPolar1D (zfft_real, zfft_imag, num_vectors, zmagArray, phaseArray);

			// Create a 2D array from 1D arrays x, y, and z
			memcpy(matrix[0], xmagArray, num_vectors * sizeof(double));
			memcpy(matrix[1], ymagArray, num_vectors * sizeof(double));
			memcpy(matrix[2], zmagArray, num_vectors * sizeof(double));
			Transpose (matrix, NUM_ELEMENTS, num_vectors, mag_matrix);

			MatrixNorm (mag_matrix[0], 1, NUM_ELEMENTS, NORM_TYPE_2, magnitudeArray);
			magnitudeArray[0] /= num_vectors; // Normalize DC
			df = fs/num_vectors; // Calculate frequency resolution 
			for(i = 0; i <= num_vectors/2; i++)
			{
				// Calculate magnitudes  
				MatrixNorm (mag_matrix[i + 1], 1, NUM_ELEMENTS, NORM_TYPE_2, magnitudeArray + i + 1); 
				// Normalize magnitudes
				magnitudeArray[i + 1] /= (num_vectors/2);
				// Calculate frequencies 
				freqArray[i] = i*df;
			}
			// Plot the FFT magnitude
			plotHandleFFT = PlotXY (tabHandle_FFT, TABPANEL_3_GRAPH_FFT, freqArray, magnitudeArray, num_vectors/2 + 1, VAL_DOUBLE,
									VAL_DOUBLE, VAL_FAT_LINE, VAL_EMPTY_SQUARE, VAL_SOLID, 1, VAL_RED);
			// Disable the PLOT FFT button
			SetCtrlAttribute(tabHandle_FFT, TABPANEL_3_PLOT_FFT, ATTR_DIMMED, 1);
			break;
	}
	return 0;
}


//-----------------------------------------------------------------------------
// Choose directory and filename to write
//-----------------------------------------------------------------------------
int CVICALLBACK SelectFileToWrite(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{

	switch (event)
	{
		case EVENT_COMMIT:
		{
			if (FileSelectPopupEx ("", "*.txt", "TXT Files (*.txt)",
								   "Name of File to Save", VAL_SELECT_BUTTON, 0, 1, pathname) > 0)
			{
				SetCtrlVal (tabHandle_LiveChart, TABPANEL_PATH, pathname);
			}
		}
	}
	return 0;
}

//-----------------------------------------------------------------------------
// Prepare file to write
//-----------------------------------------------------------------------------
void WriteToFile()
{
	GetCtrlVal (panelHandle, PANEL_WRITE_TO_FILE, &writeToFile);

	if (!writeToFile)
		return;

	filehandle = fopen (pathname, "w+");
	fprintf (filehandle, "MAGNETIC FIELD DATA \n\n");
	fprintf(filehandle, "Time \t\t x \t\t y\t\t z \n");
	fprintf (filehandle, "---------------------------------------------------------\n");
}

void ToggleConnectLED()
{
	static int led = 0;  // Initialize the variable only once

	led = !led;  // Toggle the value of led

	// Set the value of the Connect LED indicator
	SetCtrlVal(panelHandle, PANEL_CONNECT_LED, led);

	if (led)
	{
		// Enable the Start button
		SetCtrlAttribute(panelHandle, PANEL_START, ATTR_DIMMED, 0);
	}
	else
	{
		// No connetion. Disable Start and Stop buttons
		SetCtrlAttribute(panelHandle, PANEL_START, ATTR_DIMMED, 1);
		SetCtrlAttribute(panelHandle, PANEL_STOP, ATTR_DIMMED, 1);
	}
}

int CVICALLBACK ToggleWriteLED (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlVal(panelHandle, PANEL_WRITE_LED, writeToFile = !writeToFile);
			break;
	}
	return 0;
}

int CVICALLBACK ScaleToggle (int panel, int control, int event,
							 void *callbackData, int eventData1, int eventData2)
{
	static int sw = 0;
	switch (event)
	{
		case EVENT_COMMIT:
			// Get the current value of the switch
			GetCtrlVal (tabHandle_FFT, TABPANEL_3_SCALESWITCH, &sw);
			if (sw == 1)
				//  Set switch to LOG
				SetCtrlAttribute (tabHandle_FFT, TABPANEL_3_GRAPH_FFT, ATTR_YMAP_MODE, VAL_LOG);
			else
				// Set switch to LINEAR
				SetCtrlAttribute (tabHandle_FFT, TABPANEL_3_GRAPH_FFT, ATTR_YMAP_MODE, VAL_LINEAR);

			// Toggle the switch
			sw = !sw;
			break;
	}
	return 0;
}

