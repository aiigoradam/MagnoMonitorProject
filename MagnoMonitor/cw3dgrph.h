#ifndef _CW3DGRAPHLIB_H
#define _CW3DGRAPHLIB_H

#include <cviauto.h>

#ifdef __cplusplus
    extern "C" {
#endif
/* NICDBLD_BEGIN> Type Library Specific Types */

enum CW3DGraphLibEnum_CWGraph3DTrackModes
{
	CW3DGraphLibConst_cwG3DTrackPlotAreaEvents = 0,
	CW3DGraphLibConst_cwG3DTrackAllEvents = 1,
	CW3DGraphLibConst_cwG3DTrackCursors = 2,
	CW3DGraphLibConst_cwG3DTrackZoomPanRotate = 20,
	_CW3DGraphLib_CWGraph3DTrackModesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWKeyboardModes
{
	CW3DGraphLibConst_cwKeyboardNone = 0,
	CW3DGraphLibConst_cwKeyboardHandled = 1,
	_CW3DGraphLib_CWKeyboardModesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWGraph3DProjectionStyles
{
	CW3DGraphLibConst_cwOrthographic = 0,
	CW3DGraphLibConst_cwPerspective = 1,
	_CW3DGraphLib_CWGraph3DProjectionStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWGraph3DViewModes
{
	CW3DGraphLibConst_cwViewXYPlane = 0,
	CW3DGraphLibConst_cwViewXZPlane = 1,
	CW3DGraphLibConst_cwViewYZPlane = 2,
	CW3DGraphLibConst_cwViewUserDefined = 3,
	_CW3DGraphLib_CWGraph3DViewModesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWAxisTextOrientationStyle
{
	CW3DGraphLibConst_cwAxisTextFixed = 0,
	CW3DGraphLibConst_cwAxisTextFaceCamera = 1,
	_CW3DGraphLib_CWAxisTextOrientationStyleForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWValuePairLabels
{
	CW3DGraphLibConst_cwVPLabelNone = 0,
	CW3DGraphLibConst_cwVPLabelName = 1,
	CW3DGraphLibConst_cwVPLabelValue = 2,
	_CW3DGraphLib_CWValuePairLabelsForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWValuePairLocations
{
	CW3DGraphLibConst_cwVPLocationValue = 0,
	CW3DGraphLibConst_cwVPLocationIndex = 1,
	_CW3DGraphLib_CWValuePairLocationsForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWPlot3DStyles
{
	CW3DGraphLibConst_cwLine = 1,
	CW3DGraphLibConst_cwPoint = 2,
	CW3DGraphLibConst_cwLinePoint = 3,
	CW3DGraphLibConst_cwHiddenLine = 4,
	CW3DGraphLibConst_cwSurface = 5,
	CW3DGraphLibConst_cwSurfaceLine = 6,
	CW3DGraphLibConst_cwSurfaceNormal = 7,
	CW3DGraphLibConst_cwContourLine = 8,
	CW3DGraphLibConst_cwSurfaceContour = 9,
	_CW3DGraphLib_CWPlot3DStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWFillStyles
{
	CW3DGraphLibConst_cwFlat = 0,
	CW3DGraphLibConst_cwSmooth = 1,
	_CW3DGraphLib_CWFillStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CW3DLineStyles
{
	CW3DGraphLibConst_cwLine3DNone = 0,
	CW3DGraphLibConst_cwLine3DSolid = 1,
	CW3DGraphLibConst_cwLine3DDash = 4,
	CW3DGraphLibConst_cwLine3DDot = 5,
	CW3DGraphLibConst_cwLine3DDashDot = 6,
	_CW3DGraphLib_CW3DLineStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CW3DPointStyles
{
	CW3DGraphLibConst_cwPoint3DNone = 0,
	CW3DGraphLibConst_cwPoint3DEmptySquare = 1,
	CW3DGraphLibConst_cwPoint3DSolidSquare = 2,
	CW3DGraphLibConst_cwPoint3DAsterisk = 3,
	CW3DGraphLibConst_cwPoint3DSolidDiamond = 6,
	CW3DGraphLibConst_cwPoint3DEmptyCircle = 9,
	CW3DGraphLibConst_cwPoint3DSolidCircle = 10,
	CW3DGraphLibConst_cwPoint3DBoldX = 14,
	CW3DGraphLibConst_cwPoint3DWireframeSphere = 30,
	CW3DGraphLibConst_cwPoint3DSolidSphere = 31,
	CW3DGraphLibConst_cwPoint3DWireframeCube = 32,
	CW3DGraphLibConst_cwPoint3DSolidCube = 33,
	_CW3DGraphLib_CW3DPointStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWColorMapStyles
{
	CW3DGraphLibConst_cwNone = 0,
	CW3DGraphLibConst_cwShaded = 1,
	CW3DGraphLibConst_cwColorSpectrum = 2,
	CW3DGraphLibConst_cwGrayScale = 3,
	CW3DGraphLibConst_cwCustom = 4,
	_CW3DGraphLib_CWColorMapStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWCoordinateSystems
{
	CW3DGraphLibConst_cwCartesian = 0,
	CW3DGraphLibConst_cwCylindrical = 1,
	CW3DGraphLibConst_cwSpherical = 2,
	_CW3DGraphLib_CWCoordinateSystemsForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWBases
{
	CW3DGraphLibConst_cwZ = 0,
	CW3DGraphLibConst_cwY = 1,
	CW3DGraphLibConst_cwX = 2,
	CW3DGraphLibConst_cwMagnitude = 3,
	_CW3DGraphLib_CWBasesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWContourLabelOrientationStyle
{
	CW3DGraphLibConst_cwFixed = 0,
	CW3DGraphLibConst_cwAuto = 1,
	_CW3DGraphLib_CWContourLabelOrientationStyleForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWLightAttenuationStyles
{
	CW3DGraphLibConst_cwLightNone = 0,
	CW3DGraphLibConst_cwLinear = 1,
	CW3DGraphLibConst_cwQuadratic = 2,
	_CW3DGraphLib_CWLightAttenuationStylesForceSizeToFourBytes = 0xFFFFFFFF
};
enum CW3DGraphLibEnum_CWCursor3DSnapModes
{
	CW3DGraphLibConst_cwSnapFixed = 0,
	CW3DGraphLibConst_cwSnapNearestPlot = 1,
	CW3DGraphLibConst_cwSnapToPlot = 2,
	_CW3DGraphLib_CWCursor3DSnapModesForceSizeToFourBytes = 0xFFFFFFFF
};
typedef CAObjHandle CW3DGraphLibObj_Font;
typedef unsigned long CW3DGraphLibType_OLE_COLOR;
typedef CAObjHandle CW3DGraphLibObj_CWPlot3D;
typedef CAObjHandle CW3DGraphLibObj_CWPlots3D;
typedef CAObjHandle CW3DGraphLibObj_CWAxes3D;
typedef CAObjHandle CW3DGraphLibObj_Picture;
typedef CAObjHandle CW3DGraphLibObj_CWLights;
typedef CAObjHandle CW3DGraphLibObj_CWCursors3D;
typedef long CW3DGraphLibType_OLE_XPOS_PIXELS;
typedef long CW3DGraphLibType_OLE_YPOS_PIXELS;
typedef CAObjHandle CW3DGraphLibObj_CWAxis3D;
typedef CAObjHandle CW3DGraphLibObj_CWTicks3D;
typedef CAObjHandle CW3DGraphLibObj_CWLabels3D;
typedef CAObjHandle CW3DGraphLibObj_CWValuePairs;
typedef CAObjHandle CW3DGraphLibObj_CWValuePair;
typedef CAObjHandle CW3DGraphLibObj_CWContours;
typedef CAObjHandle CW3DGraphLibObj_CWContour;
typedef CAObjHandle CW3DGraphLibObj_CWLight;
typedef CAObjHandle CW3DGraphLibObj_CWCursor3D;
typedef CAObjHandle CW3DGraphLibObj_CWAxis3D_CI;
typedef CAObjHandle CW3DGraphLibObj_CWTicks3D_CI;
typedef CAObjHandle CW3DGraphLibObj_CWLabels3D_CI;
typedef unsigned long CW3DGraphLibType_OLE_COLOR;
typedef CAObjHandle CW3DGraphLibObj_Font;
typedef CAObjHandle CW3DGraphLibObj_CWValuePairs_CI;
typedef CAObjHandle CW3DGraphLibObj_CWValuePair_CI;
typedef CAObjHandle CW3DGraphLibObj_CWPlot3D_CI;
typedef CAObjHandle CW3DGraphLibObj_CWContours_CI;
typedef CAObjHandle CW3DGraphLibObj_CWContour_CI;
typedef CAObjHandle CW3DGraphLibObj_CWLight_CI;
typedef CAObjHandle CW3DGraphLibObj_CWCursor3D_CI;
typedef CAObjHandle CW3DGraphLibObj_CWPlots3D_CI;
typedef CAObjHandle CW3DGraphLibObj_CWAxes3D_CI;
typedef CAObjHandle CW3DGraphLibObj_Picture;
typedef CAObjHandle CW3DGraphLibObj_CWLights_CI;
typedef CAObjHandle CW3DGraphLibObj_CWCursors3D_CI;
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnDblClick_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             short  button,
                                                                             short  shift,
                                                                             CW3DGraphLibType_OLE_XPOS_PIXELS  x,
                                                                             CW3DGraphLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short  button,
                                                                           short  shift,
                                                                           CW3DGraphLibType_OLE_XPOS_PIXELS  x,
                                                                           CW3DGraphLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                             void *caCallbackData,
                                                                             short  button,
                                                                             short  shift,
                                                                             CW3DGraphLibType_OLE_XPOS_PIXELS  x,
                                                                             CW3DGraphLibType_OLE_YPOS_PIXELS  y);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnKeyDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                           void *caCallbackData,
                                                                           short *keyCode,
                                                                           short  shift);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnKeyPress_CallbackType) (CAObjHandle caServerObjHandle,
                                                                            void *caCallbackData,
                                                                            short *keyAscii);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnKeyUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                         void *caCallbackData,
                                                                         short *keyCode,
                                                                         short  shift);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPlotMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 short *button,
                                                                                 short *shift,
                                                                                 VARIANT *XData,
                                                                                 VARIANT *YData,
                                                                                 VARIANT *ZData,
                                                                                 short *plotIndex,
                                                                                 long *pointI,
                                                                                 long *pointJ);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPlotMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                 void *caCallbackData,
                                                                                 short *button,
                                                                                 short *shift,
                                                                                 VARIANT *XData,
                                                                                 VARIANT *YData,
                                                                                 VARIANT *ZData,
                                                                                 short *plotIndex,
                                                                                 long *pointI,
                                                                                 long *pointJ);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPlotMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                               void *caCallbackData,
                                                                               short *button,
                                                                               short *shift,
                                                                               VARIANT *XData,
                                                                               VARIANT *YData,
                                                                               VARIANT *ZData,
                                                                               short *plotIndex,
                                                                               long *pointI,
                                                                               long *pointJ);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPlotAreaMouseDown_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                     void *caCallbackData,
                                                                                     short *button,
                                                                                     short *shift,
                                                                                     VARIANT *XNear,
                                                                                     VARIANT *YNear,
                                                                                     VARIANT *ZNear,
                                                                                     VARIANT *XFar,
                                                                                     VARIANT *YFar,
                                                                                     VARIANT *ZFar);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPlotAreaMouseMove_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                     void *caCallbackData,
                                                                                     short *button,
                                                                                     short *shift,
                                                                                     VARIANT *XNear,
                                                                                     VARIANT *YNear,
                                                                                     VARIANT *ZNear,
                                                                                     VARIANT *XFar,
                                                                                     VARIANT *YFar,
                                                                                     VARIANT *ZFar);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPlotAreaMouseUp_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                   void *caCallbackData,
                                                                                   short *button,
                                                                                   short *shift,
                                                                                   VARIANT *XNear,
                                                                                   VARIANT *YNear,
                                                                                   VARIANT *ZNear,
                                                                                   VARIANT *XFar,
                                                                                   VARIANT *YFar,
                                                                                   VARIANT *ZFar);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnZoom_CallbackType) (CAObjHandle caServerObjHandle,
                                                                        void *caCallbackData,
                                                                        VARIANT *newDistance);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnPan_CallbackType) (CAObjHandle caServerObjHandle,
                                                                       void *caCallbackData,
                                                                       VARIANT *newXCenter,
                                                                       VARIANT *newYCenter,
                                                                       VARIANT *newZCenter);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnRotate_CallbackType) (CAObjHandle caServerObjHandle,
                                                                          void *caCallbackData,
                                                                          VARIANT *newLatitude,
                                                                          VARIANT *newLongitude);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnCursorChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                void *caCallbackData,
                                                                                long *cursorIndex,
                                                                                double *XPosition,
                                                                                double *YPosition,
                                                                                double *ZPosition,
                                                                                VBOOL *tracking);
typedef HRESULT (CVICALLBACK *_DCWGraph3DEventsRegOnReadyStateChange_CallbackType) (CAObjHandle caServerObjHandle,
                                                                                    void *caCallbackData);
/* NICDBLD_END> Type Library Specific Types */

extern const IID CW3DGraphLib_IID__DCWGraph3D;
extern const IID CW3DGraphLib_IID__DCWGraph3DEvents;
extern const IID CW3DGraphLib_IID_CWAxes3D;
extern const IID CW3DGraphLib_IID_CWAxis3D;
extern const IID CW3DGraphLib_IID_CWTicks3D;
extern const IID CW3DGraphLib_IID_CWLabels3D;
extern const IID CW3DGraphLib_IID_CWValuePairs;
extern const IID CW3DGraphLib_IID_CWValuePair;
extern const IID CW3DGraphLib_IID_CWPlots3D;
extern const IID CW3DGraphLib_IID_CWPlot3D;
extern const IID CW3DGraphLib_IID_CWContours;
extern const IID CW3DGraphLib_IID_CWContour;
extern const IID CW3DGraphLib_IID_CWLights;
extern const IID CW3DGraphLib_IID_CWLight;
extern const IID CW3DGraphLib_IID_CWCursors3D;
extern const IID CW3DGraphLib_IID_CWCursor3D;
extern const IID CW3DGraphLib_IID_CWAxes3D_CI;
extern const IID CW3DGraphLib_IID_CWAxis3D_CI;
extern const IID CW3DGraphLib_IID_CWTicks3D_CI;
extern const IID CW3DGraphLib_IID_CWLabels3D_CI;
extern const IID CW3DGraphLib_IID_CWValuePairs_CI;
extern const IID CW3DGraphLib_IID_CWValuePair_CI;
extern const IID CW3DGraphLib_IID_CWPlots3D_CI;
extern const IID CW3DGraphLib_IID_CWPlot3D_CI;
extern const IID CW3DGraphLib_IID_CWContours_CI;
extern const IID CW3DGraphLib_IID_CWContour_CI;
extern const IID CW3DGraphLib_IID_CWLights_CI;
extern const IID CW3DGraphLib_IID_CWLight_CI;
extern const IID CW3DGraphLib_IID_CWCursors3D_CI;
extern const IID CW3DGraphLib_IID_CWCursor3D_CI;
extern const IID CW3DGraphLib_IID__DCWGraph3D_CI;

HRESULT CVIFUNC CW3DGraphLib_NewCWGraph3D_DCWGraph3D (int panel,
                                                      const char *label, int top,
                                                      int left, int *controlID,
                                                      int *UILError);

HRESULT CVIFUNC CW3DGraphLib_NewCWGraph3D2_DCWGraph3D (int panel,
                                                       const char *label,
                                                       int top, int left,
                                                       int *controlID,
                                                       int *UILError);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DImportStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *fileName);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DExportStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *fileName);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetPlots (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWPlots3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetAxes (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_CWAxes3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DClearData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DControlImage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibObj_Picture *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetLights (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWLights *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT zMatrix,
                                                             VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DSurface (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT xVector,
                                                       VARIANT yVector,
                                                       VARIANT zMatrix,
                                                       VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DParametricSurface (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VARIANT xMatrix,
                                                                 VARIANT yMatrix,
                                                                 VARIANT zMatrix,
                                                                 VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DCurve (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT xVector,
                                                     VARIANT yVector,
                                                     VARIANT zVector,
                                                     VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DAboutBox (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetDefaultView (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DMesh (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT xVector,
                                                    VARIANT yVector,
                                                    VARIANT zVector,
                                                    VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetCursors (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWCursors3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DControlImageEx (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long dpiX, long dpiY,
                                                        CW3DGraphLibObj_Picture *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefEnabled (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetFont (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_Font *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetFont (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_Font newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefFont (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibObj_Font *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefCaption (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefBackColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetReadyState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetReadyState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefReadyState (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetPlotAreaColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetPlotAreaColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefPlotAreaColor (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGraphFrameColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGraphFrameColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGraphFrameColor (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetTrackMode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWGraph3DTrackModes *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetTrackMode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWGraph3DTrackModes newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefTrackMode (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum CW3DGraphLibEnum_CWGraph3DTrackModes *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetPlotTemplate (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_CWPlot3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetPlotTemplate (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_CWPlot3D newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefPlotTemplate (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibObj_CWPlot3D *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetImmediateUpdates (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetImmediateUpdates (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefImmediateUpdates (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetWindowless (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetWindowless (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefWindowless (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefCaptionColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetKeyboardMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWKeyboardModes *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetKeyboardMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWKeyboardModes newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefKeyboardMode (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum CW3DGraphLibEnum_CWKeyboardModes *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGraphFrameVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGraphFrameVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGraphFrameVisible (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetDither (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetDither (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefDither (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetFastDraw (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetFastDraw (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefFastDraw (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridFrameColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridFrameColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridFrameColor (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridSmoothing (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridSmoothing (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridSmoothing (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridXY (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridXY (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridXY (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridXZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridXZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridXZ (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridYZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridYZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridYZ (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetLighting (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetLighting (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefLighting (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetAmbientLightColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetAmbientLightColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefAmbientLightColor (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetProjectionStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWGraph3DProjectionStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetProjectionStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWGraph3DProjectionStyles newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefProjectionStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWGraph3DProjectionStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewAutoDistance (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewAutoDistance (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewAutoDistance (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewDistance (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewDistance (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewDistance (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              double *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewLatitude (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewLatitude (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewLatitude (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              double *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewLongitude (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewLongitude (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewLongitude (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               double *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CWGraph3DViewModes *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CWGraph3DViewModes newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewMode (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWGraph3DViewModes *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewXCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewXCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewXCenter (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewYCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewYCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewYCenter (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewZCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewZCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewZCenter (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetClipData (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetClipData (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefClipData (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT item,
                                           CW3DGraphLibObj_CWAxis3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DGetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DSetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DSetByRefCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetMinMax (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT minimum, VARIANT maximum);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetValuePairs (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWValuePairs *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DAutoScaleNow (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetLog (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetLog (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefLog (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetMaximum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetMaximum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefMaximum (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetMinimum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetMinimum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefMinimum (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetInverted (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetInverted (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefInverted (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefAutoScale (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetTicks (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWTicks3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetTicks (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWTicks3D newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefTicks (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWTicks3D *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetFormatString (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetFormatString (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefFormatString (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetLabels (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWLabels3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetLabels (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWLabels3D newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefLabels (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWLabels3D *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaption (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaption (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaption (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionNormal (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionNormal (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionNormal (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionOpposite (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionOpposite (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionOpposite (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionFont (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibObj_Font *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRef_Name (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWAxisTextOrientationStyle newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetInside (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetInside (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefInside (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetOutside (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetOutside (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefOutside (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetNormal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetNormal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefNormal (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetOpposite (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetOpposite (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefOpposite (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorDivisions (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorDivisions (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetAutoDivisions (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetAutoDivisions (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefAutoDivisions (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorUnitsInterval (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorUnitsBase (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorUnitsBase (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorUnitsBase (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorUnitsInterval (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorGrid (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorGrid (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorGridColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorGridColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorTicks (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorTicks (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorTickColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorTickColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetNormal (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetNormal (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefNormal (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetOpposite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetOpposite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefOpposite (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetOrientationStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetOrientationStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWAxisTextOrientationStyle newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT item,
                                               CW3DGraphLibObj_CWValuePair *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_NewEnum (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   LPUNKNOWN *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsRemove (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsRemoveAll (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsAdd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibObj_CWValuePair *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSwap (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT element1,
                                               VARIANT element2);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   short *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   short newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        short *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetLabelType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWValuePairLabels *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetLabelType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWValuePairLabels newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefLabelType (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWValuePairLabels *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetLocation (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWValuePairLocations *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetLocation (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWValuePairLocations newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefLocation (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum CW3DGraphLibEnum_CWValuePairLocations *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefMajorTicks (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetGridLines (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetGridLines (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefGridLines (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairGetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetByRefName (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairGetValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetByRefValue (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairGet_Value (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSet_Value (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetByRef_Value (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DItem (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT item,
                                            CW3DGraphLibObj_CWPlot3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_NewEnum (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                LPUNKNOWN *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DRemove (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DRemoveAll (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DAdd (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           CW3DGraphLibObj_CWPlot3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DGetCount (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                short *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DSetCount (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                short newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DSetByRefCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     short *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DClearData (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT zMatrix,
                                                          VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DSurface (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT xVector,
                                                    VARIANT yVector,
                                                    VARIANT zMatrix,
                                                    VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DParametricSurface (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT xMatrix,
                                                              VARIANT yMatrix,
                                                              VARIANT zMatrix,
                                                              VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DCurve (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT xVector,
                                                  VARIANT yVector,
                                                  VARIANT zVector,
                                                  VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetContours (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWContours *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetXAxis (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWAxis3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetYAxis (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWAxis3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetZAxis (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWAxis3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DMesh (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT xVector,
                                                 VARIANT yVector,
                                                 VARIANT zVector,
                                                 VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefEnabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRef_Name (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetMultiPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetMultiPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefMultiPlot (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefAutoScale (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum CW3DGraphLibEnum_CWPlot3DStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum CW3DGraphLibEnum_CWPlot3DStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWPlot3DStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetFillStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CWFillStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetFillStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CWFillStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefFillStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CWFillStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetFillColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetFillColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefFillColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetLineStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CW3DLineStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetLineStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CW3DLineStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetLineColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetLineColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetLineWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetLineWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DPointStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DPointStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DPointStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointSize (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointSize (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointSize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointFrequency (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointFrequency (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointFrequency (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetCacheData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetCacheData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefCacheData (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWColorMapStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWColorMapStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWColorMapStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetCoordinateSystem (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWCoordinateSystems *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetCoordinateSystem (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWCoordinateSystems newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefCoordinateSystem (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWCoordinateSystems *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetProjectionXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetProjectionXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefProjectionXY (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetProjectionXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetProjectionXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefProjectionXZ (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetProjectionYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetProjectionYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefProjectionYZ (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetShowProjectionsOnly (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetShowProjectionsOnly (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefShowProjectionsOnly (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetTransparency (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetTransparency (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefTransparency (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapInterpolate (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapInterpolate (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapInterpolate (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapAutoScale (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapAutoScale (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapAutoScale (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapLog (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapLog (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapLog (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapValues (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapValues (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapValues (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapColors (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapColors (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapColors (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursItem (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT item,
                                             CW3DGraphLibObj_CWContour *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContours_NewEnum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 LPUNKNOWN *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursRemove (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWContoursRemoveAll (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLineColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR lineColor);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLineStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CW3DLineStyles lineStyle);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLineWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double lineWidth);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelFormat (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *label);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR labelColor);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font labelFont);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelVisible (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL labelVisible);

HRESULT CVIFUNC CW3DGraphLib_CWContoursAdd (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, double level);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetAnchorEnabled (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetAnchorEnabled (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefAnchorEnabled (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetAnchor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetAnchor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefAnchor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetBasis (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum CW3DGraphLibEnum_CWBases *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetBasis (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum CW3DGraphLibEnum_CWBases newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefBasis (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWBases *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetInterval (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetInterval (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefInterval (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetLevelList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLevelList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefLevelList (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetLevels (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLevels (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefLevels (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWContourLabelOrientationStyle *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWContourLabelOrientationStyle newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefLabelOrientationStyle (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      enum CW3DGraphLibEnum_CWContourLabelOrientationStyle *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLevel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLevel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLevel (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLineColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLineColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLineColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLineStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DLineStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLineStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DLineStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLineStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DLineStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLineWidth (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLineWidth (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLineWidth (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelFormat (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelFont (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_Font *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelVisible (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightsItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT item,
                                           CW3DGraphLibObj_CWLight *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLights_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightsGetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightsSetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightsSetByRefCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightGetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefEnabled (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightGetAttenuation (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWLightAttenuationStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetAttenuation (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWLightAttenuationStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefAttenuation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWLightAttenuationStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightGetLatitude (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetLatitude (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefLatitude (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightGetLongitude (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetLongitude (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefLongitude (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightGetDistance (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetDistance (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefDistance (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightGetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT item,
                                              CW3DGraphLibObj_CWCursor3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  LPUNKNOWN *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DRemove (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DRemoveAll (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DAdd (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             CW3DGraphLibObj_CWCursor3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DSetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DSetByRefCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       short *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPosition (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double x, double y, double z);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR color);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefEnabled (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGet_Name (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSet_Name (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRef_Name (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetName (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetName (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetVisible (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetVisible (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefVisible (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetXPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetXPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefXPosition (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetYPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetYPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefYPosition (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetZPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetZPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefZPosition (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPlot (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWPlot3D *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPlot (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWPlot3D newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPlot (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWPlot3D *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefRow (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetColumn (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetColumn (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefColumn (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetNameVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetNameVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefNameVisible (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPositionVisible (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPositionVisible (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPositionVisible (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetXYPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetXYPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefXYPlaneVisible (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetXZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetXZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefXZPlaneVisible (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetYZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetYZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefYZPlaneVisible (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPointColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPointColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPointColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetLineColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetLineColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefLineColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetTextColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetTextColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefTextColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetTextBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetTextBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefTextBackColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPlaneColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPlaneColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPlaneColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPointSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPointSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPointSize (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetLineWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetLineWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefLineWidth (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPlaneTransparency (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPlaneTransparency (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPlaneTransparency (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPointStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DPointStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPointStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DPointStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPointStyle (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum CW3DGraphLibEnum_CW3DPointStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetLineStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CW3DLineStyles *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetLineStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CW3DLineStyles newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefLineStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CW3DLineStyles *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetSnapMode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWCursor3DSnapModes *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetSnapMode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWCursor3DSnapModes newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefSnapMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWCursor3DSnapModes *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font *returnValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font newValue);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font *newValue);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_CIGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_CIItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT item,
                                              CW3DGraphLibObj_CWAxis3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_CI_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetLog (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetLog (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetMaximum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetMaximum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetMinimum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetMinimum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetInverted (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetInverted (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetTicks (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWTicks3D_CI *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetFormatString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetFormatString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetLabels (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWLabels3D_CI *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionNormal (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionNormal (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionOpposite (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionOpposite (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionFont (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibObj_Font *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionFont (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibObj_Font pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetMinMax (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT minimum,
                                                   VARIANT maximum);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetValuePairs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_CWValuePairs_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIAutoScaleNow (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWAxisTextOrientationStyle pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetInside (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetInside (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetOutside (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetOutside (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetNormal (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetNormal (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetOpposite (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetOpposite (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetAutoDivisions (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetAutoDivisions (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorUnitsBase (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorUnitsBase (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetNormal (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetNormal (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetOpposite (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetOpposite (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetOrientationStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetOrientationStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWAxisTextOrientationStyle pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetLabelType (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWValuePairLabels *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetLabelType (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWValuePairLabels pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetLocation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWValuePairLocations *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetLocation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWValuePairLocations pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetMajorTicks (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetMajorTicks (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetGridLines (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetGridLines (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIItem (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT item,
                                                  CW3DGraphLibObj_CWValuePair_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CI_NewEnum (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CAObjHandle *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIRemove (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIRemoveAll (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIAdd (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_CWValuePair_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISwap (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT element1,
                                                  VARIANT element2);

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CIGetName (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CISetName (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CIGetValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CISetValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIGetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   short *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT item,
                                               CW3DGraphLibObj_CWPlot3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CI_NewEnum (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIRemove (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIRemoveAll (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIAdd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibObj_CWPlot3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetMultiPlot (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetMultiPlot (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetStyle (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum CW3DGraphLibEnum_CWPlot3DStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetStyle (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum CW3DGraphLibEnum_CWPlot3DStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetFillStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWFillStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetFillStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWFillStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetFillColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetFillColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetLineStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DLineStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetLineStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DLineStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetLineColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetLineColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetLineWidth (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetLineWidth (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DPointStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DPointStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointFrequency (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointFrequency (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetCacheData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetCacheData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWColorMapStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWColorMapStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetCoordinateSystem (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum CW3DGraphLibEnum_CWCoordinateSystems *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetCoordinateSystem (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum CW3DGraphLibEnum_CWCoordinateSystems pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetProjectionXY (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetProjectionXY (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetProjectionXZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetProjectionXZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetProjectionYZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetProjectionYZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetShowProjectionsOnly (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetShowProjectionsOnly (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetTransparency (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetTransparency (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapInterpolate (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapInterpolate (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapAutoScale (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapAutoScale (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapLog (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapLog (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapValueVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapValueVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapColorVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapColorVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIClearData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT zMatrix,
                                                             VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DSurface (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT xVector,
                                                       VARIANT yVector,
                                                       VARIANT zMatrix,
                                                       VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DParametricSurface (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VARIANT xMatrix,
                                                                 VARIANT yMatrix,
                                                                 VARIANT zMatrix,
                                                                 VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DCurve (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT xVector,
                                                     VARIANT yVector,
                                                     VARIANT zVector,
                                                     VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetContours (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWContours_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetXAxis (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWAxis3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetYAxis (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWAxis3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetZAxis (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWAxis3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DMesh (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT xVector,
                                                    VARIANT yVector,
                                                    VARIANT zVector,
                                                    VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetAnchorEnabled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetAnchorEnabled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetAnchor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetAnchor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetBasis (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWBases *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetBasis (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWBases pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetInterval (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetInterval (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetLevelList (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLevelList (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetLevels (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLevels (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIItem (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT item,
                                                CW3DGraphLibObj_CWContour_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CI_NewEnum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIRemove (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIRemoveAll (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR lineColor);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles lineStyle);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double lineWidth);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelFormat (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *label);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR labelColor);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelFont (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibObj_Font labelFont);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelVisible (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL labelVisible);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIAdd (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               double level);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWContourLabelOrientationStyle *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWContourLabelOrientationStyle pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLevel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLevel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLineColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLineColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLineStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DLineStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLineStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DLineStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLineWidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLineWidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelFormat (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelFormat (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelFont (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_Font *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelFont (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_Font pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLights_CIGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLights_CIItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT item,
                                              CW3DGraphLibObj_CWLight_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWLights_CI_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetAttenuation (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWLightAttenuationStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetAttenuation (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWLightAttenuationStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetLatitude (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetLatitude (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetLongitude (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetLongitude (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetDistance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetDistance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIGetCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     short *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIItem (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT item,
                                                 CW3DGraphLibObj_CWCursor3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CI_NewEnum (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CAObjHandle *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIRemove (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT element);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIRemoveAll (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIAdd (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWCursor3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetEnabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetEnabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetXPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetXPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetYPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetYPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetZPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetZPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWPlot3D_CI *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWPlot3D_CI pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetColumn (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetColumn (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetNameVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetNameVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPositionVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPositionVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetXYPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetXYPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetXZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetXZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetYZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetYZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPointColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPointColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetTextColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetTextColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetTextBackColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetTextBackColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPlaneColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPlaneColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPointSize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPointSize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPlaneTransparency (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPlaneTransparency (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPointStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DPointStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPointStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DPointStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetSnapMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWCursor3DSnapModes *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetSnapMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWCursor3DSnapModes pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font *pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font pVal);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPosition (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double x, double y,
                                                       double z);

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR color);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetEnabled (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetEnabled (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetCaption (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetCaption (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetReadyState (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetPlotAreaColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetPlotAreaColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGraphFrameColor (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGraphFrameColor (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetTrackMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWGraph3DTrackModes *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetTrackMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWGraph3DTrackModes pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetPlotTemplate (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibObj_CWPlot3D_CI *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetImmediateUpdates (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetImmediateUpdates (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetWindowless (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetWindowless (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetCaptionColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetCaptionColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetKeyboardMode (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWKeyboardModes *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetKeyboardMode (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWKeyboardModes pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGraphFrameVisible (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGraphFrameVisible (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetDither (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetDither (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetFastDraw (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetFastDraw (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridFrameColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridFrameColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridSmoothing (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridSmoothing (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetLighting (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetLighting (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetAmbientLightColor (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CW3DGraphLibType_OLE_COLOR *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetAmbientLightColor (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CW3DGraphLibType_OLE_COLOR pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetProjectionStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWGraph3DProjectionStyles *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetProjectionStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWGraph3DProjectionStyles pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewAutoDistance (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewAutoDistance (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewDistance (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewDistance (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewLatitude (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewLatitude (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewLongitude (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewLongitude (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CWGraph3DViewModes *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CWGraph3DViewModes pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewXCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewXCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewYCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewYCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewZCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewZCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetClipData (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetClipData (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         VBOOL *pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         VBOOL pVal);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIImportStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *fileName);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIExportStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *fileName);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetPlots (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWPlots3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetAxes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWAxes3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIClearData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIControlImage (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_Picture *pRetval);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetLights (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibObj_CWLights_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT zMatrix,
                                                                VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DSurface (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT xVector,
                                                          VARIANT yVector,
                                                          VARIANT zMatrix,
                                                          VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DParametricSurface (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VARIANT xMatrix,
                                                                    VARIANT yMatrix,
                                                                    VARIANT zMatrix,
                                                                    VARIANT wMatrix);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DCurve (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT xVector,
                                                        VARIANT yVector,
                                                        VARIANT zVector,
                                                        VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIAboutBox (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetDefaultView (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DMesh (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT xVector,
                                                       VARIANT yVector,
                                                       VARIANT zVector,
                                                       VARIANT wVector);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetCursors (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_CWCursors3D_CI *pRetval);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIControlImageEx (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long dpiX, long dpiY,
                                                           CW3DGraphLibObj_Picture *pRetval);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnClick (CAObjHandle serverObject,
                                                          _DCWGraph3DEventsRegOnClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnDblClick (CAObjHandle serverObject,
                                                             _DCWGraph3DEventsRegOnDblClick_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnMouseMove (CAObjHandle serverObject,
                                                              _DCWGraph3DEventsRegOnMouseMove_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnMouseUp (CAObjHandle serverObject,
                                                            _DCWGraph3DEventsRegOnMouseUp_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnMouseDown (CAObjHandle serverObject,
                                                              _DCWGraph3DEventsRegOnMouseDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnKeyDown (CAObjHandle serverObject,
                                                            _DCWGraph3DEventsRegOnKeyDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnKeyPress (CAObjHandle serverObject,
                                                             _DCWGraph3DEventsRegOnKeyPress_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnKeyUp (CAObjHandle serverObject,
                                                          _DCWGraph3DEventsRegOnKeyUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotMouseDown (CAObjHandle serverObject,
                                                                  _DCWGraph3DEventsRegOnPlotMouseDown_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotMouseMove (CAObjHandle serverObject,
                                                                  _DCWGraph3DEventsRegOnPlotMouseMove_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotMouseUp (CAObjHandle serverObject,
                                                                _DCWGraph3DEventsRegOnPlotMouseUp_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotAreaMouseDown (CAObjHandle serverObject,
                                                                      _DCWGraph3DEventsRegOnPlotAreaMouseDown_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotAreaMouseMove (CAObjHandle serverObject,
                                                                      _DCWGraph3DEventsRegOnPlotAreaMouseMove_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotAreaMouseUp (CAObjHandle serverObject,
                                                                    _DCWGraph3DEventsRegOnPlotAreaMouseUp_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnZoom (CAObjHandle serverObject,
                                                         _DCWGraph3DEventsRegOnZoom_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPan (CAObjHandle serverObject,
                                                        _DCWGraph3DEventsRegOnPan_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnRotate (CAObjHandle serverObject,
                                                           _DCWGraph3DEventsRegOnRotate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnCursorChange (CAObjHandle serverObject,
                                                                 _DCWGraph3DEventsRegOnCursorChange_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId);

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnReadyStateChange (CAObjHandle serverObject,
                                                                     _DCWGraph3DEventsRegOnReadyStateChange_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId);
#ifdef __cplusplus
    }
#endif
#endif /* _CW3DGRAPHLIB_H */
