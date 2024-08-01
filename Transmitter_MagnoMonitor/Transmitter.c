//==============================================================================
// Title:		Simulator of a magnetic field measuring device.
// Description: The program simulates a device that measures and transmits a
//				magnetic induction in x, y, and z directions.
//==============================================================================

//-----------------------------------------------------------------------------
// Include files
//-----------------------------------------------------------------------------
#include <utility.h>
#include <rs232.h>
#include <ansi_c.h>
#include <cvirte.h>
#include <userint.h>
#include "Transmitter.h"
#include "ComConfigDLL.h"
//-----------------------------------------------------------------------------
// Defines
//-----------------------------------------------------------------------------
#define LEN 90000
#define TIME_INTERVAL 0.02
//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------
void CVICALLBACK ComCallback (int portNumber, int eventMask, void *callbackData);
static int CVICALLBACK ThreadSendData (void *functionData);
unsigned int Connected(int portNumber);
//-----------------------------------------------------------------------------
// Global variables
//-----------------------------------------------------------------------------
int panelHandle;
CmtThreadFunctionID threadFunctionId;
CmtThreadLockHandle lock;

double dataArray[LEN];
int volatile quitting;
double time_interval;

//-----------------------------------------------------------------------------
// Program entry-point
//-----------------------------------------------------------------------------
int main (int argc, char *argv[])
{
	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	if ((panelHandle = LoadPanel (0, "Transmitter.uir", PANEL)) < 0)
		return -1;

	// open file
	FILE *fp;
	fp = fopen ("Data.txt", "r");

	// read data from file
	for (int i = 0; i < LEN; i++)
		fscanf(fp, "%lf", dataArray + i);

	// close file
	fclose(fp);

	DisplayPanel (panelHandle);
	RunUserInterface ();
	CloseCVIRTE ();
	DiscardPanel (panelHandle);
	return 0;
}

int CVICALLBACK ConfigCallBack (int panel, int control, int event,
								void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// Perform configuration of the port
			DLLConfigPort();

			if(!comport || RS232Error)
				return 0; // Configuration wasn't performed  

			// Disable the Configure button
			SetCtrlAttribute (panelHandle, PANEL_COM_CONFIG, ATTR_DIMMED, 1);
			// Schedule the thread function to send data
			CmtScheduleThreadPoolFunction(DEFAULT_THREAD_POOL_HANDLE, ThreadSendData, 0, &threadFunctionId);
			// Create a new lock for synchronization
			CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &lock);
			break;
	}
	return 0;
}

static int CVICALLBACK ThreadSendData (void *functionData)
{
	// Install the communication callback for detecting a break signal
	InstallComCallback (comport, LWRS_BREAK , 0, 0 , ComCallback, 0);
	return 0;
}

void CVICALLBACK ComCallback (int portNo,int eventMask,void *callbackData)
{
	// Prepare packet for transmission
	int i;
	int numElements = 3;
	int dataSize = sizeof(double) * numElements;
	int packetSize = dataSize + 1;  // Include space for the checksum byte
	int numBytesSent;
	static int shift = 0;
	char packet[packetSize];
	char checksum;

	// Send data
	while(!quitting && Connected(comport))
	{
		// Lock protects from quitting the program while loop is running
		CmtGetLock (lock);

		// Copy double values to packet buffer
		memcpy(packet, dataArray + shift, dataSize);

		// Calculate checksum
		for (i = 0, checksum = 0; i < dataSize; i++)
			checksum ^= packet[i]; // XOR operation

		SetCtrlVal(panelHandle, PANEL_CHECKSUM, checksum);

		// Add checksum to the packet
		packet[dataSize] = checksum;

		// Send the packet over the communication channel
		numBytesSent = ComWrt(comport, packet, packetSize);
		
		// Update shift for the next packet
		shift += numElements;

		// Update UI elements
		SetCtrlVal(panelHandle, PANEL_NUM, numBytesSent);
		SetCtrlVal(panelHandle, PANEL_OUTPUT_QUE, GetOutQLen(comport));

		// LED blink to indicate data sent
		SetCtrlVal (panelHandle, PANEL_LED, 1);
		Delay(TIME_INTERVAL);
		SetCtrlVal (panelHandle, PANEL_LED, 0);
		Delay(TIME_INTERVAL);
	    ProcessSystemEvents ();
		
		CmtReleaseLock (lock);
	}
	return;
}

int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			quitting = 1;
			if (threadFunctionId)
			{
				// Wait for thread function Completion
				CmtWaitForThreadPoolFunctionCompletion (DEFAULT_THREAD_POOL_HANDLE,
														threadFunctionId, OPT_TP_PROCESS_EVENTS_WHILE_WAITING);
				// Release thread function
				CmtReleaseThreadPoolFunctionID (DEFAULT_THREAD_POOL_HANDLE, threadFunctionId);

				CmtDiscardLock (lock);
			}
			if (port_open)
			{
				FlushInQ (comport);
				FlushOutQ (comport);
				ProcessSystemEvents ();  
				RS232Error = CloseCom (comport);
				if (RS232Error) DisplayRS232Error ();
			}
			QuitUserInterface (0);
			break;
	}
	return 0;
}

// Function to check if the communication line is connected
unsigned int Connected(int portNumber)
{
	return (GetComLineStatus(portNumber) & kRS_DSR_ON);
}
