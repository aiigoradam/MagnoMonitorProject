/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  CONFIG                           1
#define  CONFIG_COMPORT                   2       /* control type: slide, callback function: (none) */
#define  CONFIG_BAUDRATE                  3       /* control type: slide, callback function: (none) */
#define  CONFIG_PARITY                    4       /* control type: slide, callback function: (none) */
#define  CONFIG_DATABITS                  5       /* control type: slide, callback function: (none) */
#define  CONFIG_STOPBITS                  6       /* control type: slide, callback function: (none) */
#define  CONFIG_INPUTQ                    7       /* control type: numeric, callback function: (none) */
#define  CONFIG_OUTPUTQ                   8       /* control type: numeric, callback function: (none) */
#define  CONFIG_CTSMODE                   9       /* control type: binary, callback function: (none) */
#define  CONFIG_XMODE                     10      /* control type: binary, callback function: (none) */
#define  CONFIG_TIMEOUT                   11      /* control type: numeric, callback function: (none) */
#define  CONFIG_CLOSECONFIG               12      /* control type: command, callback function: CloseConfigCallback */
#define  CONFIG_OUTQSIZE_MSG              13      /* control type: textMsg, callback function: (none) */
#define  CONFIG_TIMEOUT_MSG1              14      /* control type: textMsg, callback function: (none) */
#define  CONFIG_QUITBUTTON                15      /* control type: command, callback function: QuitCallback */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CloseConfigCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
