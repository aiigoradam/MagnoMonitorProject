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

#define  PANEL                            1
#define  PANEL_QUITBUTTON                 2       /* control type: command, callback function: QuitCallback */
#define  PANEL_NUM                        3       /* control type: numeric, callback function: (none) */
#define  PANEL_CHECKSUM                   4       /* control type: numeric, callback function: (none) */
#define  PANEL_OUTPUT_QUE                 5       /* control type: numeric, callback function: (none) */
#define  PANEL_LED                        6       /* control type: LED, callback function: (none) */
#define  PANEL_TEXTMSG                    7       /* control type: textMsg, callback function: (none) */
#define  PANEL_COM_CONFIG                 8       /* control type: command, callback function: ConfigCallBack */
#define  PANEL_SR                         9       /* control type: numeric, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ConfigCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
