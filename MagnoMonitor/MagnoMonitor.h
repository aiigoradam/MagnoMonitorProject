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
#define  PANEL_TAB                        2       /* control type: tab, callback function: (none) */
#define  PANEL_START                      3       /* control type: command, callback function: Start */
#define  PANEL_STOP                       4       /* control type: command, callback function: Stop */
#define  PANEL_WINDOW                     5       /* control type: numeric, callback function: (none) */
#define  PANEL_SR                         6       /* control type: numeric, callback function: (none) */
#define  PANEL_DECORATION_2               7       /* control type: deco, callback function: (none) */
#define  PANEL_CONNECT_LED                8       /* control type: LED, callback function: (none) */
#define  PANEL_WRITE_LED                  9       /* control type: LED, callback function: (none) */
#define  PANEL_WRITE_TO_FILE              10      /* control type: binary, callback function: ToggleWriteLED */
#define  PANEL_DECORATION_3               11      /* control type: deco, callback function: (none) */
#define  PANEL_DECORATION_4               12      /* control type: deco, callback function: (none) */
#define  PANEL_QUITBUTTON                 13      /* control type: command, callback function: QuitCallback */
#define  PANEL_COM_CONFIG                 14      /* control type: command, callback function: ConfigCallBack */
#define  PANEL_TEXTMSG                    15      /* control type: textMsg, callback function: (none) */
#define  PANEL_NUMERIC                    16      /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_STRIPCHART              2       /* control type: strip, callback function: (none) */
#define  TABPANEL_MAXB                    3       /* control type: numeric, callback function: (none) */
#define  TABPANEL_MINB                    4       /* control type: numeric, callback function: (none) */
#define  TABPANEL_MAG                     5       /* control type: numeric, callback function: (none) */
#define  TABPANEL_Z                       6       /* control type: numeric, callback function: (none) */
#define  TABPANEL_Y                       7       /* control type: numeric, callback function: (none) */
#define  TABPANEL_X                       8       /* control type: numeric, callback function: (none) */
#define  TABPANEL_PATH                    9       /* control type: string, callback function: (none) */
#define  TABPANEL_SELECT_FILE             10      /* control type: pictButton, callback function: SelectFileToWrite */
#define  TABPANEL_DECORATION_4            11      /* control type: deco, callback function: (none) */
#define  TABPANEL_DECORATION_5            12      /* control type: deco, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_2_TABLE                 2       /* control type: table, callback function: (none) */
#define  TABPANEL_2_3DGRAPH               3       /* control type: activeX, callback function: (none) */

     /* tab page panel controls */
#define  TABPANEL_3_GRAPH_FFT             2       /* control type: graph, callback function: (none) */
#define  TABPANEL_3_SCALESWITCH           3       /* control type: binary, callback function: ScaleToggle */
#define  TABPANEL_3_PLOT_FFT              4       /* control type: command, callback function: PlotFFT */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ConfigCallBack(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PlotFFT(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK QuitCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ScaleToggle(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SelectFileToWrite(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Start(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Stop(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ToggleWriteLED(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
