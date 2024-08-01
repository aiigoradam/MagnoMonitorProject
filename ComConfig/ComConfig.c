/*---------------------------------------------------------------------------*/
/* Include files                                                             */
/*---------------------------------------------------------------------------*/
#include <formatio.h>
#include <utility.h>
#include <rs232.h>
#include <userint.h>
#include <cvidef.h>
#include "ComConfig.h"
#include "ComConfigDLL.h"
//-----------------------------------------------------------------------------
// Prototypes
//-----------------------------------------------------------------------------
void SetConfigParms (void);
void GetConfigParms (void);
void DisplayRS232Error (void);

/*---------------------------------------------------------------------------*/
/* Module-globals                                                            */
/*---------------------------------------------------------------------------*/
int panel_handle;
int	config_handle;
int	baudrate;
int	portindex;
int	parity;
int	databits;
int	stopbits;
int	inputq;         
int	outputq;        
int	xmode;
int	ctsmode;
int	config_flag;
double timeout;
char devicename[30];

/*---------------------------------------------------------------------------*/
/* Export-globals                                                            */
/*---------------------------------------------------------------------------*/
int DLLEXPORT comport;
int DLLEXPORT port_open;
int DLLEXPORT RS232Error;

/*---------------------------------------------------------------------------*/
/* DLL entry-point to handle initializations.                                */
/*---------------------------------------------------------------------------*/
int DLLEXPORT DllMain (HINSTANCE hinstDLL, DWORD fdwReason,
					   LPVOID lpvReserved)
{
	if (fdwReason == DLL_PROCESS_ATTACH)
	{

		/* Place any initialization which needs to be done when the DLL */
		/* is loaded here. */
		if (InitCVIRTE (hinstDLL, 0, 0) == 0)
			return 0;
	}
	else if (fdwReason == DLL_PROCESS_DETACH)
	{

		/* Place any clean-up which needs to be done when the DLL */
		/* is unloaded here. */
		if (!CVIRTEHasBeenDetached ())
			CloseCVIRTE ();
	}

	/* Return 0 to abort if initialization fails */
	return 1;
}

/*---------------------------------------------------------------------------*/
/* This function, when called, will initialize and run a GUI for this DLL.   */
/* This GUI will not interfere with other user-interfaces maintained by the  */
/* caller.  This function will not return until the GUI is unloaded.         */
/*---------------------------------------------------------------------------*/
/*---------------------------------------------------------------------------*/
/* Let the user configure the port.                                          */
/*---------------------------------------------------------------------------*/
int DLLEXPORT DLLConfigPort (void)
{
	/* Note that we use LoadPanelEx rather than LoadPanel when our callback  */
	/* functions are not exported from a DLL.                                */
	if ((config_handle = LoadPanelEx (0, "ComConfig.uir", CONFIG, __CVIUserHInst)) < 0)
		return 0;
	InstallPopup (config_handle);

	/*  If user already has done configuration, then
		display those new parameters.  If entering
		configuration for 1st time, set config_flag
		and use default settings.
	*/
	if (config_flag)    /* Configuration done at least once.*/
		SetConfigParms ();
	else                /* 1st time.*/
		config_flag = 1;

	RunUserInterface ();

	/* Free resources for the UI and return success */
	DiscardPanel (config_handle);
	return 1;
}


/*---------------------------------------------------------------------------*/
/* Get the port configuration parameters.                                    */
/*---------------------------------------------------------------------------*/
void GetConfigParms (void)
{
	GetCtrlVal (config_handle, CONFIG_COMPORT, &comport);
	GetCtrlVal (config_handle, CONFIG_BAUDRATE, &baudrate);
	GetCtrlVal (config_handle, CONFIG_PARITY, &parity);
	GetCtrlVal (config_handle, CONFIG_DATABITS, &databits);
	GetCtrlVal (config_handle, CONFIG_STOPBITS, &stopbits);
	GetCtrlVal (config_handle, CONFIG_INPUTQ, &inputq);
	GetCtrlVal (config_handle, CONFIG_OUTPUTQ, &outputq);
	GetCtrlVal (config_handle, CONFIG_CTSMODE, &ctsmode);
	GetCtrlVal (config_handle, CONFIG_XMODE, &xmode);
	GetCtrlVal (config_handle, CONFIG_TIMEOUT, &timeout);
	GetCtrlIndex (config_handle, CONFIG_COMPORT, &portindex);
}

/*---------------------------------------------------------------------------*/
/* Set the port configuration parameters.                                    */
/*---------------------------------------------------------------------------*/
void SetConfigParms (void)
{
	SetCtrlVal (config_handle, CONFIG_COMPORT, comport);
	SetCtrlVal (config_handle, CONFIG_BAUDRATE, baudrate);
	SetCtrlVal (config_handle, CONFIG_PARITY, parity);
	SetCtrlVal (config_handle, CONFIG_DATABITS, databits);
	SetCtrlVal (config_handle, CONFIG_STOPBITS, stopbits);
	SetCtrlVal (config_handle, CONFIG_INPUTQ, inputq);
	SetCtrlVal (config_handle, CONFIG_OUTPUTQ, outputq);
	SetCtrlVal (config_handle, CONFIG_CTSMODE, ctsmode);
	SetCtrlVal (config_handle, CONFIG_XMODE, xmode);
	SetCtrlVal (config_handle, CONFIG_TIMEOUT, timeout);
	SetCtrlIndex (config_handle, CONFIG_COMPORT, portindex);
}

/*---------------------------------------------------------------------------*/
/* Display error information to the user.                                    */
/*---------------------------------------------------------------------------*/
void DLLEXPORT DisplayRS232Error (void)
{
	char* ErrorMessage;
	ErrorMessage = GetRS232ErrorString (RS232Error);
	MessagePopup ("RS232 Message", ErrorMessage);
}

/*---------------------------------------------------------------------------*/
/* close the configuration panel.                                            */
/*---------------------------------------------------------------------------*/
int CVICALLBACK CloseConfigCallback (int panel, int control, int event,
									 void *callbackData, int eventData1,
									 int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT :
			port_open = 0;  /* initialize flag to 0 - unopened */
			GetConfigParms ();
			DisableBreakOnLibraryErrors ();
			RS232Error = OpenComConfig (comport, devicename, baudrate, parity,
										databits, stopbits, inputq, outputq);
			EnableBreakOnLibraryErrors ();
			if (RS232Error) DisplayRS232Error ();
			if (RS232Error == 0)
			{
				port_open = 1;
				/* 	Make sure Serial buffers are empty */
				FlushInQ (comport);
				FlushOutQ (comport);
				GetCtrlVal (config_handle, CONFIG_XMODE, &xmode);
				SetXMode (comport, xmode);
				GetCtrlVal (config_handle, CONFIG_CTSMODE, &ctsmode);
				SetCTSMode (comport, ctsmode);
				GetCtrlVal (config_handle, CONFIG_TIMEOUT, &timeout);
				SetComTime (comport, timeout);
				QuitUserInterface (0);
			}
			break;
	}
	return 0;
}


int CVICALLBACK QuitCallback (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
