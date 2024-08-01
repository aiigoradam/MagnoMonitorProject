#include "cw3dgrph.h"
#include <userint.h>

static void CVIFUNC _DCWGraph3DEventsRegOnClick_EventVTableFunc (void *thisPtr);

static void CVIFUNC _DCWGraph3DEventsRegOnDblClick_EventVTableFunc (void *thisPtr);

static void CVIFUNC _DCWGraph3DEventsRegOnMouseMove_EventVTableFunc (void *thisPtr,
                                                                     short button,
                                                                     short shift,
                                                                     long x,
                                                                     long y);

static void CVIFUNC _DCWGraph3DEventsRegOnMouseUp_EventVTableFunc (void *thisPtr,
                                                                   short button,
                                                                   short shift,
                                                                   long x,
                                                                   long y);

static void CVIFUNC _DCWGraph3DEventsRegOnMouseDown_EventVTableFunc (void *thisPtr,
                                                                     short button,
                                                                     short shift,
                                                                     long x,
                                                                     long y);

static void CVIFUNC _DCWGraph3DEventsRegOnKeyDown_EventVTableFunc (void *thisPtr,
                                                                   short *keyCode,
                                                                   short shift);

static void CVIFUNC _DCWGraph3DEventsRegOnKeyPress_EventVTableFunc (void *thisPtr,
                                                                    short *keyAscii);

static void CVIFUNC _DCWGraph3DEventsRegOnKeyUp_EventVTableFunc (void *thisPtr,
                                                                 short *keyCode,
                                                                 short shift);

static void CVIFUNC _DCWGraph3DEventsRegOnPlotMouseDown_EventVTableFunc (void *thisPtr,
                                                                         short *button,
                                                                         short *shift,
                                                                         VARIANT *XData,
                                                                         VARIANT *YData,
                                                                         VARIANT *ZData,
                                                                         short *plotIndex,
                                                                         long *pointI,
                                                                         long *pointJ);

static void CVIFUNC _DCWGraph3DEventsRegOnPlotMouseMove_EventVTableFunc (void *thisPtr,
                                                                         short *button,
                                                                         short *shift,
                                                                         VARIANT *XData,
                                                                         VARIANT *YData,
                                                                         VARIANT *ZData,
                                                                         short *plotIndex,
                                                                         long *pointI,
                                                                         long *pointJ);

static void CVIFUNC _DCWGraph3DEventsRegOnPlotMouseUp_EventVTableFunc (void *thisPtr,
                                                                       short *button,
                                                                       short *shift,
                                                                       VARIANT *XData,
                                                                       VARIANT *YData,
                                                                       VARIANT *ZData,
                                                                       short *plotIndex,
                                                                       long *pointI,
                                                                       long *pointJ);

static void CVIFUNC _DCWGraph3DEventsRegOnPlotAreaMouseDown_EventVTableFunc (void *thisPtr,
                                                                             short *button,
                                                                             short *shift,
                                                                             VARIANT *XNear,
                                                                             VARIANT *YNear,
                                                                             VARIANT *ZNear,
                                                                             VARIANT *XFar,
                                                                             VARIANT *YFar,
                                                                             VARIANT *ZFar);

static void CVIFUNC _DCWGraph3DEventsRegOnPlotAreaMouseMove_EventVTableFunc (void *thisPtr,
                                                                             short *button,
                                                                             short *shift,
                                                                             VARIANT *XNear,
                                                                             VARIANT *YNear,
                                                                             VARIANT *ZNear,
                                                                             VARIANT *XFar,
                                                                             VARIANT *YFar,
                                                                             VARIANT *ZFar);

static void CVIFUNC _DCWGraph3DEventsRegOnPlotAreaMouseUp_EventVTableFunc (void *thisPtr,
                                                                           short *button,
                                                                           short *shift,
                                                                           VARIANT *XNear,
                                                                           VARIANT *YNear,
                                                                           VARIANT *ZNear,
                                                                           VARIANT *XFar,
                                                                           VARIANT *YFar,
                                                                           VARIANT *ZFar);

static void CVIFUNC _DCWGraph3DEventsRegOnZoom_EventVTableFunc (void *thisPtr,
                                                                VARIANT *newDistance);

static void CVIFUNC _DCWGraph3DEventsRegOnPan_EventVTableFunc (void *thisPtr,
                                                               VARIANT *newXCenter,
                                                               VARIANT *newYCenter,
                                                               VARIANT *newZCenter);

static void CVIFUNC _DCWGraph3DEventsRegOnRotate_EventVTableFunc (void *thisPtr,
                                                                  VARIANT *newLatitude,
                                                                  VARIANT *newLongitude);

static void CVIFUNC _DCWGraph3DEventsRegOnCursorChange_EventVTableFunc (void *thisPtr,
                                                                        long *cursorIndex,
                                                                        double *XPosition,
                                                                        double *YPosition,
                                                                        double *ZPosition,
                                                                        VBOOL *tracking);

static void CVIFUNC _DCWGraph3DEventsRegOnReadyStateChange_EventVTableFunc (void *thisPtr);

#define __ActiveXCtrlErrorHandler() \
if ((ctrlId) > 0) \
	{ \
	if (controlID) \
		*controlID = (ctrlId); \
	if (UILError) \
		*UILError = 0; \
	__result = S_OK; \
	} \
else if ((ctrlId) == UIEActiveXError) \
	{ \
	if (controlID) \
		*controlID = 0; \
	if (UILError) \
		*UILError = 0; \
	} \
else \
	{ \
	if (controlID) \
		*controlID = 0; \
	if (UILError) \
		*UILError = (ctrlId); \
	__result = E_CVIAUTO_CVI_UI_ERROR; \
	}

typedef interface tagCW3DGraphLib_CWAxes3D_CI_Interface CW3DGraphLib_CWAxes3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWAxes3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWAxes3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWAxes3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWAxes3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount_) (CW3DGraphLib_CWAxes3D_CI_Interface __RPC_FAR *This, 
	                                                   short *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item_) (CW3DGraphLib_CWAxes3D_CI_Interface __RPC_FAR *This, 
	                                               VARIANT item, 
	                                               LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum_) (CW3DGraphLib_CWAxes3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

} CW3DGraphLib_CWAxes3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWAxes3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWAxes3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWAxes3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWAxis3D_CI_Interface CW3DGraphLib_CWAxis3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWAxis3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLog_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                 VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLog_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                 VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMaximum_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMaximum_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinimum_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinimum_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInverted_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInverted_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                  BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                  BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoScale_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoScale_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTicks_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFormatString_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                          BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFormatString_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                          BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabels_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                    LPUNKNOWN *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                     BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptionColor_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                          unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptionColor_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                          unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptionNormal_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptionNormal_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptionOpposite_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                             VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptionOpposite_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                             VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptionFont_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                         LPDISPATCH *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptionFont_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                         LPDISPATCH pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinMax_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                    VARIANT minimum, 
	                                                    VARIANT maximum);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValuePairs_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                        LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AutoScaleNow_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptionOrientationStyle_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                                     long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptionOrientationStyle_) (CW3DGraphLib_CWAxis3D_CI_Interface __RPC_FAR *This, 
	                                                                     long pVal);

} CW3DGraphLib_CWAxis3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWAxis3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWAxis3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWAxis3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWTicks3D_CI_Interface CW3DGraphLib_CWTicks3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWTicks3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInside_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInside_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOutside_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOutside_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNormal_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNormal_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOpposite_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOpposite_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorDivisions_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorDivisions_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorDivisions_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorDivisions_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoDivisions_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoDivisions_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorUnitsInterval_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                                VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorUnitsInterval_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                                VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorUnitsBase_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorUnitsBase_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorUnitsInterval_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                                VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorUnitsInterval_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                                VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorGrid_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorGrid_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorGrid_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorGrid_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorGridColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorGridColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorGridColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorGridColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorTicks_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorTicks_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorTicks_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorTicks_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorTickColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorTickColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMinorTickColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMinorTickColor_) (CW3DGraphLib_CWTicks3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long pVal);

} CW3DGraphLib_CWTicks3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWTicks3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWTicks3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWTicks3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWLabels3D_CI_Interface CW3DGraphLib_CWLabels3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWLabels3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNormal_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNormal_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOpposite_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOpposite_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColor_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                   unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                   unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFont_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFont_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetOrientationStyle_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                              long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetOrientationStyle_) (CW3DGraphLib_CWLabels3D_CI_Interface __RPC_FAR *This, 
	                                                              long pVal);

} CW3DGraphLib_CWLabels3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWLabels3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWLabels3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWLabels3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWValuePairs_CI_Interface CW3DGraphLib_CWValuePairs_CI_Interface;

typedef struct tagCW3DGraphLib_CWValuePairs_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                   short *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelType_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                       long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelType_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                       long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLocation_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                      long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLocation_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                      long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMajorTicks_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMajorTicks_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridLines_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridLines_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                               VARIANT item, 
	                                               LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                                 VARIANT element);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                              LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Swap_) (CW3DGraphLib_CWValuePairs_CI_Interface __RPC_FAR *This, 
	                                               VARIANT element1, 
	                                               VARIANT element2);

} CW3DGraphLib_CWValuePairs_CI_VTable;

typedef interface tagCW3DGraphLib_CWValuePairs_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWValuePairs_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWValuePairs_CI_Interface;

typedef interface tagCW3DGraphLib_CWValuePair_CI_Interface CW3DGraphLib_CWValuePair_CI_Interface;

typedef struct tagCW3DGraphLib_CWValuePair_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName_) (CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR *This, 
	                                                  BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName_) (CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR *This, 
	                                                  BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetValue_) (CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR *This, 
	                                                   VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetValue_) (CW3DGraphLib_CWValuePair_CI_Interface __RPC_FAR *This, 
	                                                   VARIANT pVal);

} CW3DGraphLib_CWValuePair_CI_VTable;

typedef interface tagCW3DGraphLib_CWValuePair_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWValuePair_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWValuePair_CI_Interface;

typedef interface tagCW3DGraphLib_CWPlots3D_CI_Interface CW3DGraphLib_CWPlots3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWPlots3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount_) (CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR *This, 
	                                                   short *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item_) (CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR *This, 
	                                               VARIANT item, 
	                                               LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum_) (CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove_) (CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR *This, 
	                                                 VARIANT element);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll_) (CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add_) (CW3DGraphLib_CWPlots3D_CI_Interface __RPC_FAR *This, 
	                                              LPUNKNOWN *pRetval);

} CW3DGraphLib_CWPlots3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWPlots3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWPlots3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWPlots3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWPlot3D_CI_Interface CW3DGraphLib_CWPlot3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWPlot3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                  BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                  BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMultiPlot_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetMultiPlot_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAutoScale_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAutoScale_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                   long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                   long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFillStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFillStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFillColor_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFillColor_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineColor_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineColor_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineWidth_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineWidth_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                        long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                        long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointColor_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointColor_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointSize_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointSize_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointFrequency_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                            long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointFrequency_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                            long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCacheData_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCacheData_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorMapStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                           long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorMapStyle_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                           long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCoordinateSystem_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                              long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCoordinateSystem_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                              long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProjectionXY_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProjectionXY_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProjectionXZ_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProjectionXZ_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProjectionYZ_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProjectionYZ_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetShowProjectionsOnly_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShowProjectionsOnly_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTransparency_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTransparency_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                          long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorMapInterpolate_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorMapInterpolate_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorMapAutoScale_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                               VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorMapAutoScale_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                               VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorMapLog_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                         VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorMapLog_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                         VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorMapValueVector_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorMapValueVector_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColorMapColorVector_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColorMapColorVector_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                 VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearData_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DSimpleSurface_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                              VARIANT zMatrix, 
	                                                              VARIANT wMatrix);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DSurface_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                        VARIANT xVector, 
	                                                        VARIANT yVector, 
	                                                        VARIANT zMatrix, 
	                                                        VARIANT wMatrix);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DParametricSurface_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                                  VARIANT xMatrix, 
	                                                                  VARIANT yMatrix, 
	                                                                  VARIANT zMatrix, 
	                                                                  VARIANT wMatrix);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DCurve_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                      VARIANT xVector, 
	                                                      VARIANT yVector, 
	                                                      VARIANT zVector, 
	                                                      VARIANT wVector);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetContours_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                      LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXAxis_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetYAxis_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetZAxis_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DMesh_) (CW3DGraphLib_CWPlot3D_CI_Interface __RPC_FAR *This, 
	                                                     VARIANT xVector, 
	                                                     VARIANT yVector, 
	                                                     VARIANT zVector, 
	                                                     VARIANT wVector);

} CW3DGraphLib_CWPlot3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWPlot3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWPlot3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWPlot3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWContours_CI_Interface CW3DGraphLib_CWContours_CI_Interface;

typedef struct tagCW3DGraphLib_CWContours_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWContours_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWContours_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWContours_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                   short *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnchorEnabled_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnchorEnabled_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAnchor_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                    double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAnchor_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                    double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBasis_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                   long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBasis_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                   long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetInterval_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                      double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetInterval_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                      double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLevelList_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                       VARIANT *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLevelList_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                       VARIANT pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLevels_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                    long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLevels_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                    long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                               VARIANT item, 
	                                               LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                 VARIANT element);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineColor_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long lineColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineStyle_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                       long lineStyle);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineWidth_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                       double lineWidth);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelFormat_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                         BSTR label);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelColor_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long labelColor);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelFont_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                       LPDISPATCH labelFont);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelVisible_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL labelVisible);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                              double level);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelOrientationStyle_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                                   long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelOrientationStyle_) (CW3DGraphLib_CWContours_CI_Interface __RPC_FAR *This, 
	                                                                   long pVal);

} CW3DGraphLib_CWContours_CI_VTable;

typedef interface tagCW3DGraphLib_CWContours_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWContours_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWContours_CI_Interface;

typedef interface tagCW3DGraphLib_CWContour_CI_Interface CW3DGraphLib_CWContour_CI_Interface;

typedef struct tagCW3DGraphLib_CWContour_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWContour_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWContour_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWContour_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLevel_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                   double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLevel_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                   double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineColor_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineColor_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineStyle_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineStyle_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineWidth_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineWidth_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelFormat_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                         BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelFormat_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                         BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelColor_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelColor_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelFont_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       LPDISPATCH *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelFont_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                       LPDISPATCH pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLabelVisible_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLabelVisible_) (CW3DGraphLib_CWContour_CI_Interface __RPC_FAR *This, 
	                                                          VBOOL pVal);

} CW3DGraphLib_CWContour_CI_VTable;

typedef interface tagCW3DGraphLib_CWContour_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWContour_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWContour_CI_Interface;

typedef interface tagCW3DGraphLib_CWLights_CI_Interface CW3DGraphLib_CWLights_CI_Interface;

typedef struct tagCW3DGraphLib_CWLights_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWLights_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWLights_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWLights_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount_) (CW3DGraphLib_CWLights_CI_Interface __RPC_FAR *This, 
	                                                   short *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item_) (CW3DGraphLib_CWLights_CI_Interface __RPC_FAR *This, 
	                                               VARIANT item, 
	                                               LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum_) (CW3DGraphLib_CWLights_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

} CW3DGraphLib_CWLights_CI_VTable;

typedef interface tagCW3DGraphLib_CWLights_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWLights_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWLights_CI_Interface;

typedef interface tagCW3DGraphLib_CWLight_CI_Interface CW3DGraphLib_CWLight_CI_Interface;

typedef struct tagCW3DGraphLib_CWLight_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWLight_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWLight_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWLight_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAttenuation_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                         long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAttenuation_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                         long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLatitude_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                      double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLatitude_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                      double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLongitude_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLongitude_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDistance_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                      double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDistance_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                      double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColor_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                   unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor_) (CW3DGraphLib_CWLight_CI_Interface __RPC_FAR *This, 
	                                                   unsigned long pVal);

} CW3DGraphLib_CWLight_CI_VTable;

typedef interface tagCW3DGraphLib_CWLight_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWLight_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWLight_CI_Interface;

typedef interface tagCW3DGraphLib_CWCursors3D_CI_Interface CW3DGraphLib_CWCursors3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWCursors3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCount_) (CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR *This, 
	                                                   short *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Item_) (CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR *This, 
	                                               VARIANT item, 
	                                               LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *_NewEnum_) (CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Remove_) (CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR *This, 
	                                                 VARIANT element);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveAll_) (CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add_) (CW3DGraphLib_CWCursors3D_CI_Interface __RPC_FAR *This, 
	                                              LPUNKNOWN *pRetval);

} CW3DGraphLib_CWCursors3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWCursors3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWCursors3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWCursors3D_CI_Interface;

typedef interface tagCW3DGraphLib_CWCursor3D_CI_Interface CW3DGraphLib_CWCursor3D_CI_Interface;

typedef struct tagCW3DGraphLib_CWCursor3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetName_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                  BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetName_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                  BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetXPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetYPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetYPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetZPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetZPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlot_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                  LPUNKNOWN *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlot_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                  LPUNKNOWN pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRow_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                 long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRow_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                 long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetColumn_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                    long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColumn_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                    long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNameVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                         VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetNameVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                         VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPositionVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                             VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPositionVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                             VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXYPlaneVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                            VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetXYPlaneVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                            VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetXZPlaneVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                            VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetXZPlaneVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                            VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetYZPlaneVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                            VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetYZPlaneVisible_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                            VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTextBackgroundTransparency_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                                        long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTextBackgroundTransparency_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                                        long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTextColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTextColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTextBackColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                           unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTextBackColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                           unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlaneColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlaneColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                        unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointSize_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointSize_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineWidth_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineWidth_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlaneTransparency_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                               long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlaneTransparency_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                               long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPointStyle_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                        long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPointStyle_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                        long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLineStyle_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLineStyle_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                       long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSnapMode_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                      long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetSnapMode_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                      long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFont_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFont_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPosition_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                      double x, 
	                                                      double y, 
	                                                      double z);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetColor_) (CW3DGraphLib_CWCursor3D_CI_Interface __RPC_FAR *This, 
	                                                   unsigned long color);

} CW3DGraphLib_CWCursor3D_CI_VTable;

typedef interface tagCW3DGraphLib_CWCursor3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib_CWCursor3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib_CWCursor3D_CI_Interface;

typedef interface tagCW3DGraphLib__DCWGraph3D_CI_Interface CW3DGraphLib__DCWGraph3D_CI_Interface;

typedef struct tagCW3DGraphLib__DCWGraph3D_CI_VTable
{
	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR * This, 
	                                                         REFIID riid, 
	                                                         void __RPC_FAR *__RPC_FAR *ppvObject);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR * This);

	ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR * This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEnabled_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEnabled_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                     VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFont_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFont_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                  LPDISPATCH pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaption_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                     BSTR *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                     BSTR pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetBackColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetBackColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                       unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReadyState_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                        long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlotAreaColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                           unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetPlotAreaColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                           unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGraphFrameColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                             unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGraphFrameColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                             unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTrackMode_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                       long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTrackMode_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                       long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlotTemplate_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          LPUNKNOWN *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetImmediateUpdates_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                              VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetImmediateUpdates_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                              VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWindowless_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetWindowless_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                        VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCaptionColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaptionColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetKeyboardMode_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetKeyboardMode_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGraphFrameVisible_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                               VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGraphFrameVisible_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                               VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDither_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDither_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetFastDraw_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetFastDraw_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridFrameColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridFrameColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                            unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridSmoothing_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridSmoothing_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                           VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridXY_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridXY_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridXZ_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridXZ_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetGridYZ_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetGridYZ_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLighting_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLighting_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAmbientLightColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                               unsigned long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAmbientLightColor_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                               unsigned long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetProjectionStyle_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                             long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetProjectionStyle_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                             long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewAutoDistance_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                              VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewAutoDistance_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                              VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewDistance_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewDistance_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewLatitude_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewLatitude_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                          double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewLongitude_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                           double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewLongitude_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                           double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewMode_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      long *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewMode_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      long pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewXCenter_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewXCenter_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewYCenter_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewYCenter_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetViewZCenter_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         double *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetViewZCenter_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         double pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetClipData_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetClipData_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUse3DHardwareAcceleration_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                                       VBOOL *pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetUse3DHardwareAcceleration_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                                       VBOOL pVal);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ImportStyle_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      BSTR fileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ExportStyle_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      BSTR fileName);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPlots_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                   LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAxes_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                  LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearData_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ControlImage_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                       LPDISPATCH *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLights_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                    LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DSimpleSurface_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                              VARIANT zMatrix, 
	                                                              VARIANT wMatrix);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DSurface_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                        VARIANT xVector, 
	                                                        VARIANT yVector, 
	                                                        VARIANT zMatrix, 
	                                                        VARIANT wMatrix);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DParametricSurface_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                                  VARIANT xMatrix, 
	                                                                  VARIANT yMatrix, 
	                                                                  VARIANT zMatrix, 
	                                                                  VARIANT wMatrix);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DCurve_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                      VARIANT xVector, 
	                                                      VARIANT yVector, 
	                                                      VARIANT zVector, 
	                                                      VARIANT wVector);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AboutBox_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDefaultView_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Plot3DMesh_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                     VARIANT xVector, 
	                                                     VARIANT yVector, 
	                                                     VARIANT zVector, 
	                                                     VARIANT wVector);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCursors_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                     LPUNKNOWN *pRetval);

	HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ControlImageEx_) (CW3DGraphLib__DCWGraph3D_CI_Interface __RPC_FAR *This, 
	                                                         long dpiX, 
	                                                         long dpiY, 
	                                                         LPDISPATCH *pRetval);

} CW3DGraphLib__DCWGraph3D_CI_VTable;

typedef interface tagCW3DGraphLib__DCWGraph3D_CI_Interface
{
	CONST_VTBL CW3DGraphLib__DCWGraph3D_CI_VTable __RPC_FAR *lpVtbl;
} CW3DGraphLib__DCWGraph3D_CI_Interface;

static CA_PARAMDATA __DCWGraph3DEvents_RegOnMouseMove_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shift", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnMouseUp_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shift", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnMouseDown_CA_PARAMDATA[] =
	{
		{"button", VT_I2},
        {"shift", VT_I2},
        {"x", VT_I4},
        {"y", VT_I4}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnKeyDown_CA_PARAMDATA[] =
	{
		{"keyCode", VT_I2 | VT_BYREF},
        {"shift", VT_I2}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnKeyPress_CA_PARAMDATA[] =
	{
		{"keyAscii", VT_I2 | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnKeyUp_CA_PARAMDATA[] =
	{
		{"keyCode", VT_I2 | VT_BYREF},
        {"shift", VT_I2}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPlotMouseDown_CA_PARAMDATA[] =
	{
		{"button", VT_I2 | VT_BYREF},
        {"shift", VT_I2 | VT_BYREF},
        {"XData", VT_VARIANT | VT_BYREF},
        {"YData", VT_VARIANT | VT_BYREF},
        {"ZData", VT_VARIANT | VT_BYREF},
        {"plotIndex", VT_I2 | VT_BYREF},
        {"pointI", VT_I4 | VT_BYREF},
        {"pointJ", VT_I4 | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPlotMouseMove_CA_PARAMDATA[] =
	{
		{"button", VT_I2 | VT_BYREF},
        {"shift", VT_I2 | VT_BYREF},
        {"XData", VT_VARIANT | VT_BYREF},
        {"YData", VT_VARIANT | VT_BYREF},
        {"ZData", VT_VARIANT | VT_BYREF},
        {"plotIndex", VT_I2 | VT_BYREF},
        {"pointI", VT_I4 | VT_BYREF},
        {"pointJ", VT_I4 | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPlotMouseUp_CA_PARAMDATA[] =
	{
		{"button", VT_I2 | VT_BYREF},
        {"shift", VT_I2 | VT_BYREF},
        {"XData", VT_VARIANT | VT_BYREF},
        {"YData", VT_VARIANT | VT_BYREF},
        {"ZData", VT_VARIANT | VT_BYREF},
        {"plotIndex", VT_I2 | VT_BYREF},
        {"pointI", VT_I4 | VT_BYREF},
        {"pointJ", VT_I4 | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPlotAreaMouseDown_CA_PARAMDATA[] =
	{
		{"button", VT_I2 | VT_BYREF},
        {"shift", VT_I2 | VT_BYREF},
        {"XNear", VT_VARIANT | VT_BYREF},
        {"YNear", VT_VARIANT | VT_BYREF},
        {"ZNear", VT_VARIANT | VT_BYREF},
        {"XFar", VT_VARIANT | VT_BYREF},
        {"YFar", VT_VARIANT | VT_BYREF},
        {"ZFar", VT_VARIANT | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPlotAreaMouseMove_CA_PARAMDATA[] =
	{
		{"button", VT_I2 | VT_BYREF},
        {"shift", VT_I2 | VT_BYREF},
        {"XNear", VT_VARIANT | VT_BYREF},
        {"YNear", VT_VARIANT | VT_BYREF},
        {"ZNear", VT_VARIANT | VT_BYREF},
        {"XFar", VT_VARIANT | VT_BYREF},
        {"YFar", VT_VARIANT | VT_BYREF},
        {"ZFar", VT_VARIANT | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPlotAreaMouseUp_CA_PARAMDATA[] =
	{
		{"button", VT_I2 | VT_BYREF},
        {"shift", VT_I2 | VT_BYREF},
        {"XNear", VT_VARIANT | VT_BYREF},
        {"YNear", VT_VARIANT | VT_BYREF},
        {"ZNear", VT_VARIANT | VT_BYREF},
        {"XFar", VT_VARIANT | VT_BYREF},
        {"YFar", VT_VARIANT | VT_BYREF},
        {"ZFar", VT_VARIANT | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnZoom_CA_PARAMDATA[] =
	{
		{"newDistance", VT_VARIANT | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnPan_CA_PARAMDATA[] =
	{
		{"newXCenter", VT_VARIANT | VT_BYREF},
        {"newYCenter", VT_VARIANT | VT_BYREF},
        {"newZCenter", VT_VARIANT | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnRotate_CA_PARAMDATA[] =
	{
		{"newLatitude", VT_VARIANT | VT_BYREF},
        {"newLongitude", VT_VARIANT | VT_BYREF}
	};

static CA_PARAMDATA __DCWGraph3DEvents_RegOnCursorChange_CA_PARAMDATA[] =
	{
		{"cursorIndex", VT_I4 | VT_BYREF},
        {"XPosition", VT_R8 | VT_BYREF},
        {"YPosition", VT_R8 | VT_BYREF},
        {"ZPosition", VT_R8 | VT_BYREF},
        {"tracking", VT_BOOL | VT_BYREF}
	};

static CA_METHODDATA __DCWGraph3DEvents_CA_METHODDATA[] =
	{
		{"Click", NULL, -600, 0, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"DblClick", NULL, -601, 1, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY},
        {"MouseMove", __DCWGraph3DEvents_RegOnMouseMove_CA_PARAMDATA, -606, 2, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"MouseUp", __DCWGraph3DEvents_RegOnMouseUp_CA_PARAMDATA, -607, 3, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"MouseDown", __DCWGraph3DEvents_RegOnMouseDown_CA_PARAMDATA, -605, 4, CC_STDCALL, 4, DISPATCH_METHOD, VT_EMPTY},
        {"KeyDown", __DCWGraph3DEvents_RegOnKeyDown_CA_PARAMDATA, -602, 5, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"KeyPress", __DCWGraph3DEvents_RegOnKeyPress_CA_PARAMDATA, -603, 6, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"KeyUp", __DCWGraph3DEvents_RegOnKeyUp_CA_PARAMDATA, -604, 7, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"PlotMouseDown", __DCWGraph3DEvents_RegOnPlotMouseDown_CA_PARAMDATA, 1, 8, CC_STDCALL, 8, DISPATCH_METHOD, VT_EMPTY},
        {"PlotMouseMove", __DCWGraph3DEvents_RegOnPlotMouseMove_CA_PARAMDATA, 2, 9, CC_STDCALL, 8, DISPATCH_METHOD, VT_EMPTY},
        {"PlotMouseUp", __DCWGraph3DEvents_RegOnPlotMouseUp_CA_PARAMDATA, 3, 10, CC_STDCALL, 8, DISPATCH_METHOD, VT_EMPTY},
        {"PlotAreaMouseDown", __DCWGraph3DEvents_RegOnPlotAreaMouseDown_CA_PARAMDATA, 4, 11, CC_STDCALL, 8, DISPATCH_METHOD, VT_EMPTY},
        {"PlotAreaMouseMove", __DCWGraph3DEvents_RegOnPlotAreaMouseMove_CA_PARAMDATA, 5, 12, CC_STDCALL, 8, DISPATCH_METHOD, VT_EMPTY},
        {"PlotAreaMouseUp", __DCWGraph3DEvents_RegOnPlotAreaMouseUp_CA_PARAMDATA, 6, 13, CC_STDCALL, 8, DISPATCH_METHOD, VT_EMPTY},
        {"Zoom", __DCWGraph3DEvents_RegOnZoom_CA_PARAMDATA, 7, 14, CC_STDCALL, 1, DISPATCH_METHOD, VT_EMPTY},
        {"Pan", __DCWGraph3DEvents_RegOnPan_CA_PARAMDATA, 8, 15, CC_STDCALL, 3, DISPATCH_METHOD, VT_EMPTY},
        {"Rotate", __DCWGraph3DEvents_RegOnRotate_CA_PARAMDATA, 9, 16, CC_STDCALL, 2, DISPATCH_METHOD, VT_EMPTY},
        {"CursorChange", __DCWGraph3DEvents_RegOnCursorChange_CA_PARAMDATA, 16, 17, CC_STDCALL, 5, DISPATCH_METHOD, VT_EMPTY},
        {"ReadyStateChange", NULL, -609, 18, CC_STDCALL, 0, DISPATCH_METHOD, VT_EMPTY}
	};

static CA_INTERFACEDATA __DCWGraph3DEvents_CA_INTERFACEDATA =
	{
		__DCWGraph3DEvents_CA_METHODDATA,
        (unsigned int)(sizeof (__DCWGraph3DEvents_CA_METHODDATA) / sizeof (*__DCWGraph3DEvents_CA_METHODDATA))
	};

static void * __DCWGraph3DEvents_EventVTable[] =
	{
		_DCWGraph3DEventsRegOnClick_EventVTableFunc,
        _DCWGraph3DEventsRegOnDblClick_EventVTableFunc,
        _DCWGraph3DEventsRegOnMouseMove_EventVTableFunc,
        _DCWGraph3DEventsRegOnMouseUp_EventVTableFunc,
        _DCWGraph3DEventsRegOnMouseDown_EventVTableFunc,
        _DCWGraph3DEventsRegOnKeyDown_EventVTableFunc,
        _DCWGraph3DEventsRegOnKeyPress_EventVTableFunc,
        _DCWGraph3DEventsRegOnKeyUp_EventVTableFunc,
        _DCWGraph3DEventsRegOnPlotMouseDown_EventVTableFunc,
        _DCWGraph3DEventsRegOnPlotMouseMove_EventVTableFunc,
        _DCWGraph3DEventsRegOnPlotMouseUp_EventVTableFunc,
        _DCWGraph3DEventsRegOnPlotAreaMouseDown_EventVTableFunc,
        _DCWGraph3DEventsRegOnPlotAreaMouseMove_EventVTableFunc,
        _DCWGraph3DEventsRegOnPlotAreaMouseUp_EventVTableFunc,
        _DCWGraph3DEventsRegOnZoom_EventVTableFunc,
        _DCWGraph3DEventsRegOnPan_EventVTableFunc,
        _DCWGraph3DEventsRegOnRotate_EventVTableFunc,
        _DCWGraph3DEventsRegOnCursorChange_EventVTableFunc,
        _DCWGraph3DEventsRegOnReadyStateChange_EventVTableFunc
	};

static CAEventClassDefn __DCWGraph3DEvents_CAEventClassDefn =
	{
		(int)sizeof(CAEventClassDefn),
        &CW3DGraphLib_IID__DCWGraph3DEvents,
        __DCWGraph3DEvents_EventVTable,
        &__DCWGraph3DEvents_CA_INTERFACEDATA,
        0
	};

const IID CW3DGraphLib_IID__DCWGraph3D =
	{
		0x2AFA9F11, 0xB6A, 0x11D2, 0xA2, 0x50, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x4D
	};

const IID CW3DGraphLib_IID__DCWGraph3DEvents =
	{
		0x2AFA9F12, 0xB6A, 0x11D2, 0xA2, 0x50, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x4D
	};

const IID CW3DGraphLib_IID_CWAxes3D =
	{
		0xFD641000, 0x322D, 0x11D2, 0xA3, 0xA3, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWAxis3D =
	{
		0xC798BD20, 0x2319, 0x11D2, 0xA2, 0x53, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x4D
	};

const IID CW3DGraphLib_IID_CWTicks3D =
	{
		0x6810EEF1, 0x232D, 0x11D2, 0xBE, 0xC7, 0x0, 0xA0, 0x24, 0x58, 0x53, 0x0
	};

const IID CW3DGraphLib_IID_CWLabels3D =
	{
		0x2FB97641, 0x230A, 0x11D2, 0xA2, 0x53, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x4D
	};

const IID CW3DGraphLib_IID_CWValuePairs =
	{
		0xE168E231, 0xC75C, 0x11CE, 0xA8, 0x90, 0x0, 0x20, 0xAF, 0x68, 0x45, 0xF6
	};

const IID CW3DGraphLib_IID_CWValuePair =
	{
		0x37715970, 0xC76B, 0x11CE, 0xA8, 0x90, 0x0, 0x20, 0xAF, 0x68, 0x45, 0xF6
	};

const IID CW3DGraphLib_IID_CWPlots3D =
	{
		0xFD640FD0, 0x322D, 0x11D2, 0xA3, 0xA3, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWPlot3D =
	{
		0xB86A73A0, 0x15E3, 0x11D2, 0xA3, 0x9B, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWContours =
	{
		0x9B41D330, 0x36CF, 0x11D2, 0xA3, 0xA3, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWContour =
	{
		0xE4B1BF00, 0x36CF, 0x11D2, 0xA3, 0xA3, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWLights =
	{
		0xF32E05B0, 0x15B6, 0x11D2, 0xA2, 0x53, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x4D
	};

const IID CW3DGraphLib_IID_CWLight =
	{
		0xB1AABB61, 0x15B1, 0x11D2, 0xA2, 0x53, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x4D
	};

const IID CW3DGraphLib_IID_CWCursors3D =
	{
		0xFD641010, 0x322D, 0x11D2, 0xA3, 0xA3, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWCursor3D =
	{
		0xFD641011, 0x322D, 0x11D2, 0xA3, 0xA3, 0x0, 0xA0, 0x24, 0xD8, 0x32, 0x5C
	};

const IID CW3DGraphLib_IID_CWAxes3D_CI =
	{
		0xD76C5891, 0x2ABD, 0x4A91, 0xAE, 0x60, 0xEA, 0xD3, 0xE6, 0xDA, 0xB1, 0xD5
	};

const IID CW3DGraphLib_IID_CWAxis3D_CI =
	{
		0x3D17EA62, 0x6CA6, 0x478C, 0xAA, 0xB8, 0xE4, 0x5B, 0x83, 0x94, 0xD9, 0xC6
	};

const IID CW3DGraphLib_IID_CWTicks3D_CI =
	{
		0x8C7EDD7A, 0x46A6, 0x4CA9, 0xB8, 0x20, 0xC5, 0x2D, 0x3A, 0xB2, 0x25, 0x1F
	};

const IID CW3DGraphLib_IID_CWLabels3D_CI =
	{
		0xC90E4E92, 0xD0F3, 0x49B1, 0x8A, 0x9B, 0x67, 0x8E, 0xE9, 0xE3, 0xA9, 0x4F
	};

const IID CW3DGraphLib_IID_CWValuePairs_CI =
	{
		0x74362B99, 0x2D80, 0x4283, 0x8B, 0xA9, 0xAF, 0xC0, 0xDC, 0x18, 0x2F, 0xCA
	};

const IID CW3DGraphLib_IID_CWValuePair_CI =
	{
		0x1707911E, 0x94A, 0x47DC, 0x98, 0xDF, 0xE8, 0x3B, 0xC5, 0xAF, 0x3F, 0xF0
	};

const IID CW3DGraphLib_IID_CWPlots3D_CI =
	{
		0xE4FE33CC, 0xDFB0, 0x4C19, 0x9D, 0x1B, 0x90, 0x9, 0x86, 0x53, 0xCC, 0x73
	};

const IID CW3DGraphLib_IID_CWPlot3D_CI =
	{
		0x2613902, 0xE39B, 0x4FF8, 0xAA, 0xF, 0x65, 0xDA, 0x26, 0x3E, 0x28, 0x6A
	};

const IID CW3DGraphLib_IID_CWContours_CI =
	{
		0xF0D03500, 0x9A68, 0x4817, 0xAF, 0x6A, 0xAD, 0xC, 0x1B, 0x5A, 0xDB, 0x19
	};

const IID CW3DGraphLib_IID_CWContour_CI =
	{
		0x5958ED07, 0x23F0, 0x4D45, 0xBB, 0x5B, 0xE9, 0x1C, 0x89, 0x53, 0x21, 0x9E
	};

const IID CW3DGraphLib_IID_CWLights_CI =
	{
		0x911DB943, 0x346B, 0x40FD, 0x8C, 0xAC, 0xAD, 0xEF, 0x64, 0xD7, 0x4, 0x75
	};

const IID CW3DGraphLib_IID_CWLight_CI =
	{
		0x3DED18CA, 0x8529, 0x4D20, 0x9D, 0x8, 0x99, 0x86, 0xA0, 0x61, 0xA5, 0xBD
	};

const IID CW3DGraphLib_IID_CWCursors3D_CI =
	{
		0xA0780178, 0xD29A, 0x46D2, 0xAD, 0x3A, 0x2, 0x5D, 0xA9, 0x32, 0x69, 0x60
	};

const IID CW3DGraphLib_IID_CWCursor3D_CI =
	{
		0x46E1F5FB, 0xD0EA, 0x4F7E, 0x8E, 0x51, 0xB3, 0x45, 0x4, 0x3A, 0xA8, 0x85
	};

const IID CW3DGraphLib_IID__DCWGraph3D_CI =
	{
		0x8A877ABC, 0x3F1F, 0x4575, 0x9D, 0xDA, 0x64, 0x57, 0x24, 0x8B, 0x2A, 0xBA
	};

const IID CW3DGraphLib_IID_Font =
	{
		0xBEF6E003, 0xA874, 0x101A, 0x8B, 0xBA, 0x0, 0xAA, 0x0, 0x30, 0xC, 0xAB
	};

const IID CW3DGraphLib_IID_Picture =
	{
		0x7BF80981, 0xBF32, 0x101A, 0x8B, 0xBB, 0x0, 0xAA, 0x0, 0x30, 0xC, 0xAB
	};

HRESULT CVIFUNC CW3DGraphLib_NewCWGraph3D_DCWGraph3D (int panel,
                                                      const char *label, int top,
                                                      int left, int *controlID,
                                                      int *UILError)
{
	HRESULT __result = S_OK;
	int ctrlId;
	GUID clsid = {0x2AFA9F10, 0xB6A, 0x11D2, 0xA2, 0x50, 0x0, 0xA0, 0x24, 0xD8,
	              0x32, 0x4D};
	const char * licStr = "mmhkckfmlpdigkicgckoeapjbgpknaidolbihimldomdhcjcamhabkbmncpoggkgddemcdomdcblnfdbejjpmogm";

	ctrlId = NewActiveXCtrl (panel, label, top, left, &clsid,
	                         &CW3DGraphLib_IID__DCWGraph3D, licStr, &__result);

	__ActiveXCtrlErrorHandler();

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_NewCWGraph3D2_DCWGraph3D (int panel,
                                                       const char *label,
                                                       int top, int left,
                                                       int *controlID,
                                                       int *UILError)
{
	HRESULT __result = S_OK;
	int ctrlId;
	GUID clsid = {0x819DA5E3, 0x4623, 0x498A, 0xBB, 0x34, 0xEF, 0xDB, 0x4,
	              0xF6, 0x87, 0x13};
	const char * licStr = "kkhddjngijfekcbdeboimmpabeoooiodclijelkndlmjggkkgmlajlapoejckodhbaakkpofdaaponfbijaopnak";

	ctrlId = NewActiveXCtrl (panel, label, top, left, &clsid,
	                         &CW3DGraphLib_IID__DCWGraph3D, licStr, &__result);

	__ActiveXCtrlErrorHandler();

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DImportStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *fileName)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x202,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, fileName);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DExportStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     const char *fileName)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x201,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, fileName);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetPlots (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWPlots3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x19,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetAxes (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_CWAxes3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1A,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DClearData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1B,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DControlImage (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibObj_Picture *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1C,
	                              CAVT_OBJHANDLE, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetLights (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWLights *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1D,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT zMatrix,
                                                             VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1E,
	                              CAVT_EMPTY, NULL, 2, __paramTypes, zMatrix,
	                              wMatrix);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DSurface (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT xVector,
                                                       VARIANT yVector,
                                                       VARIANT zMatrix,
                                                       VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1F,
	                              CAVT_EMPTY, NULL, 4, __paramTypes, xVector,
	                              yVector, zMatrix, wMatrix);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DParametricSurface (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VARIANT xMatrix,
                                                                 VARIANT yMatrix,
                                                                 VARIANT zMatrix,
                                                                 VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x20,
	                              CAVT_EMPTY, NULL, 4, __paramTypes, xMatrix,
	                              yMatrix, zMatrix, wMatrix);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DCurve (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT xVector,
                                                     VARIANT yVector,
                                                     VARIANT zVector,
                                                     VARIANT wVector)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x21,
	                              CAVT_EMPTY, NULL, 4, __paramTypes, xVector,
	                              yVector, zVector, wVector);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DAboutBox (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDD8,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetDefaultView (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x25,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DPlot3DMesh (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT xVector,
                                                    VARIANT yVector,
                                                    VARIANT zVector,
                                                    VARIANT wVector)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x27,
	                              CAVT_EMPTY, NULL, 4, __paramTypes, xVector,
	                              yVector, zVector, wVector);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetCursors (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWCursors3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x29,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DControlImageEx (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long dpiX, long dpiY,
                                                        CW3DGraphLibObj_Picture *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG, CAVT_LONG};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x2A,
	                              CAVT_OBJHANDLE, returnValue, 2, __paramTypes,
	                              dpiX, dpiY);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefEnabled (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetFont (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_Font *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFE00,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetFont (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_Font newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFE00,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefFont (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibObj_Font *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFE00,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDFA,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDFA,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefCaption (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDFA,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFE0B,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetBackColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFE0B,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefBackColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFE0B,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetReadyState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDF3,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetReadyState (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDF3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefReadyState (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xFFFFFDF3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetPlotAreaColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetPlotAreaColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefPlotAreaColor (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGraphFrameColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGraphFrameColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGraphFrameColor (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetTrackMode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWGraph3DTrackModes *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetTrackMode (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWGraph3DTrackModes newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefTrackMode (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum CW3DGraphLibEnum_CWGraph3DTrackModes *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetPlotTemplate (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_CWPlot3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetPlotTemplate (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_CWPlot3D newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefPlotTemplate (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibObj_CWPlot3D *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetImmediateUpdates (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetImmediateUpdates (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefImmediateUpdates (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetWindowless (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetWindowless (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefWindowless (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x7,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x7,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefCaptionColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x7,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetKeyboardMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWKeyboardModes *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x8,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetKeyboardMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWKeyboardModes newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x8,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefKeyboardMode (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              enum CW3DGraphLibEnum_CWKeyboardModes *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x8,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGraphFrameVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x9,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGraphFrameVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x9,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGraphFrameVisible (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x9,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetDither (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xA,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetDither (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xA,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefDither (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xA,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetFastDraw (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xB,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetFastDraw (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xB,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefFastDraw (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xB,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridFrameColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xC,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridFrameColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xC,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridFrameColor (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xC,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridSmoothing (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xD,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridSmoothing (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xD,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridSmoothing (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xD,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridXY (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xE,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridXY (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridXY (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridXZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xF,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridXZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xF,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridXZ (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0xF,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetGridYZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x10,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetGridYZ (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x10,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefGridYZ (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x10,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetLighting (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x11,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetLighting (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x11,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefLighting (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x11,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetAmbientLightColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x12,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetAmbientLightColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x12,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefAmbientLightColor (CAObjHandle objectHandle,
                                                                   ERRORINFO *errorInfo,
                                                                   CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x12,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetProjectionStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWGraph3DProjectionStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x13,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetProjectionStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWGraph3DProjectionStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x13,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefProjectionStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWGraph3DProjectionStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x13,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewAutoDistance (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x14,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewAutoDistance (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x14,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewAutoDistance (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x14,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewDistance (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x15,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewDistance (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x15,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewDistance (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x15,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewLatitude (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x16,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewLatitude (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x16,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewLatitude (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x16,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewLongitude (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x17,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewLongitude (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x17,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewLongitude (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x17,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CWGraph3DViewModes *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x18,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewMode (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CWGraph3DViewModes newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x18,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewMode (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWGraph3DViewModes *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x18,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewXCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x22,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewXCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x22,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewXCenter (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x22,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewYCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x23,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewYCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x23,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewYCenter (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x23,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetViewZCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x24,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetViewZCenter (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x24,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefViewZCenter (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x24,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetClipData (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x26,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetClipData (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x26,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefClipData (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x26,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DGetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x28,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x28,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DSetByRefUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID__DCWGraph3D, 0x28,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT item,
                                           CW3DGraphLibObj_CWAxis3D *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxes3D, 0x0,
	                              CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
	                              item);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxes3D, 0xFFFFFFFC,
	                              CAVT_UNKNOWN, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DGetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxes3D, 0x100,
	                              DISPATCH_PROPERTYGET, CAVT_SHORT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DSetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxes3D, 0x100,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3DSetByRefCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxes3D, 0x100,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetMinMax (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT minimum, VARIANT maximum)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x10, CAVT_EMPTY,
	                              NULL, 2, __paramTypes, minimum, maximum);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetValuePairs (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWValuePairs *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x11,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DAutoScaleNow (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x12, CAVT_EMPTY,
	                              NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetLog (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetLog (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefLog (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetMaximum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetMaximum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefMaximum (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetMinimum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetMinimum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefMinimum (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetInverted (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetInverted (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefInverted (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefAutoScale (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetTicks (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWTicks3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x7,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetTicks (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWTicks3D newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x7,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefTicks (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWTicks3D *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x7,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetFormatString (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x8,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetFormatString (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x8,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefFormatString (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x8,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetLabels (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWLabels3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x9,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetLabels (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWLabels3D newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x9,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefLabels (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWLabels3D *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x9,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xA,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xA,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xA,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaption (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xB,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaption (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xB,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaption (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xB,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xC,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xC,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xC,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionNormal (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xD,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionNormal (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xD,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionNormal (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xD,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionOpposite (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xE,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionOpposite (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionOpposite (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xF,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xF,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionFont (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibObj_Font *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0xF,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x0,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x0,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRef_Name (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x0,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DGetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x13,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWAxisTextOrientationStyle newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x13,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3DSetByRefCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWAxis3D, 0x13,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetInside (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetInside (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefInside (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetOutside (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetOutside (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefOutside (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetNormal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetNormal (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefNormal (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetOpposite (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetOpposite (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefOpposite (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorDivisions (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorDivisions (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorDivisions (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetAutoDivisions (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x7,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetAutoDivisions (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x7,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefAutoDivisions (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x7,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x8,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x8,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorUnitsInterval (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x8,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorUnitsBase (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x9,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorUnitsBase (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x9,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorUnitsBase (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x9,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xA,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorUnitsInterval (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xA,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorUnitsInterval (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xA,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xB,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xB,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorGrid (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xB,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xC,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorGrid (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xC,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorGrid (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xC,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xD,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xD,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorGridColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xD,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xE,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorGridColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorGridColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xF,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xF,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorTicks (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0xF,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x10,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorTicks (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x10,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorTicks (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x10,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMajorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x11,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMajorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x11,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMajorTickColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x11,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DGetMinorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x12,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetMinorTickColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x12,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3DSetByRefMinorTickColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWTicks3D, 0x12,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetNormal (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetNormal (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefNormal (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetOpposite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetOpposite (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefOpposite (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DGetOrientationStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetOrientationStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWAxisTextOrientationStyle newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3DSetByRefOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLabels3D, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT item,
                                               CW3DGraphLibObj_CWValuePair *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x0,
	                              CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
	                              item);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_NewEnum (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   LPUNKNOWN *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0xFFFFFFFC,
	                              CAVT_UNKNOWN, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsRemove (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT element)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x101,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, element);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsRemoveAll (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x103,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsAdd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibObj_CWValuePair *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x102,
	                              CAVT_OBJHANDLE, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSwap (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT element1,
                                               VARIANT element2)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x5,
	                              CAVT_EMPTY, NULL, 2, __paramTypes, element1,
	                              element2);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   short *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x100,
	                              DISPATCH_PROPERTYGET, CAVT_SHORT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   short newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x100,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefCount (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        short *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x100,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetLabelType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWValuePairLabels *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetLabelType (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWValuePairLabels newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefLabelType (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWValuePairLabels *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetLocation (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWValuePairLocations *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetLocation (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWValuePairLocations newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefLocation (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum CW3DGraphLibEnum_CWValuePairLocations *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefMajorTicks (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsGetGridLines (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetGridLines (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairsSetByRefGridLines (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePairs, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairGetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetByRefName (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairGetValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetValue (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetByRefValue (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairGet_Value (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x0,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSet_Value (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x0,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairSetByRef_Value (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWValuePair, 0x0,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DItem (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, VARIANT item,
                                            CW3DGraphLibObj_CWPlot3D *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x0,
	                              CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
	                              item);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_NewEnum (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                LPUNKNOWN *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0xFFFFFFFC,
	                              CAVT_UNKNOWN, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DRemove (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              VARIANT element)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x101,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, element);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DRemoveAll (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x103,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DAdd (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo,
                                           CW3DGraphLibObj_CWPlot3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x102,
	                              CAVT_OBJHANDLE, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DGetCount (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                short *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x100,
	                              DISPATCH_PROPERTYGET, CAVT_SHORT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DSetCount (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                short newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x100,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3DSetByRefCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     short *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlots3D, 0x100,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DClearData (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x17, CAVT_EMPTY,
	                              NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT zMatrix,
                                                          VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x18, CAVT_EMPTY,
	                              NULL, 2, __paramTypes, zMatrix, wMatrix);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DSurface (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT xVector,
                                                    VARIANT yVector,
                                                    VARIANT zMatrix,
                                                    VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x19, CAVT_EMPTY,
	                              NULL, 4, __paramTypes, xVector, yVector,
	                              zMatrix, wMatrix);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DParametricSurface (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VARIANT xMatrix,
                                                              VARIANT yMatrix,
                                                              VARIANT zMatrix,
                                                              VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1A, CAVT_EMPTY,
	                              NULL, 4, __paramTypes, xMatrix, yMatrix,
	                              zMatrix, wMatrix);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DCurve (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT xVector,
                                                  VARIANT yVector,
                                                  VARIANT zVector,
                                                  VARIANT wVector)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1B, CAVT_EMPTY,
	                              NULL, 4, __paramTypes, xVector, yVector,
	                              zVector, wVector);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetContours (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWContours *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1C,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetXAxis (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWAxis3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1D,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetYAxis (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWAxis3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1E,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetZAxis (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               CW3DGraphLibObj_CWAxis3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1F,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DPlot3DMesh (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT xVector,
                                                 VARIANT yVector,
                                                 VARIANT zVector,
                                                 VARIANT wVector)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT, CAVT_VARIANT, CAVT_VARIANT,
	                               CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x25, CAVT_EMPTY,
	                              NULL, 4, __paramTypes, xVector, yVector,
	                              zVector, wVector);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetEnabled (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefEnabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x0,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSet_Name (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x0,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRef_Name (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x0,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetName (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetVisible (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetMultiPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetMultiPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefMultiPlot (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetAutoScale (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefAutoScale (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum CW3DGraphLibEnum_CWPlot3DStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetStyle (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               enum CW3DGraphLibEnum_CWPlot3DStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWPlot3DStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetFillStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CWFillStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetFillStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CWFillStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefFillStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CWFillStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetFillColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x7,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetFillColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x7,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefFillColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x7,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetLineStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CW3DLineStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x8,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetLineStyle (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   enum CW3DGraphLibEnum_CW3DLineStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x8,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x8,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetLineColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x9,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetLineColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x9,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x9,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetLineWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xA,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetLineWidth (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xA,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xA,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DPointStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xB,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DPointStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xB,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DPointStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xB,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xC,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xC,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xC,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointSize (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xD,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointSize (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xD,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointSize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xD,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetPointFrequency (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xE,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetPointFrequency (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefPointFrequency (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetCacheData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xF,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetCacheData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xF,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefCacheData (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0xF,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWColorMapStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x10,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWColorMapStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x10,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapStyle (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWColorMapStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x10,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetCoordinateSystem (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWCoordinateSystems *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x11,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetCoordinateSystem (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWCoordinateSystems newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x11,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefCoordinateSystem (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWCoordinateSystems *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x11,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetProjectionXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x12,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetProjectionXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x12,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefProjectionXY (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x12,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetProjectionXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x13,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetProjectionXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x13,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefProjectionXZ (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x13,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetProjectionYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x14,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetProjectionYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x14,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefProjectionYZ (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x14,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetShowProjectionsOnly (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x15,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetShowProjectionsOnly (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x15,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefShowProjectionsOnly (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x15,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetTransparency (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x16,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetTransparency (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x16,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefTransparency (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x16,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapInterpolate (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x20,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapInterpolate (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x20,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapInterpolate (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x20,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapAutoScale (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x21,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapAutoScale (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x21,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapAutoScale (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x21,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapLog (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x22,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapLog (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x22,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapLog (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x22,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapValues (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x23,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapValues (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x23,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapValues (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x23,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DGetColorMapColors (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x24,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetColorMapColors (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x24,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3DSetByRefColorMapColors (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWPlot3D, 0x24,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursItem (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo, VARIANT item,
                                             CW3DGraphLibObj_CWContour *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x0,
	                              CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
	                              item);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_NewEnum (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 LPUNKNOWN *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xFFFFFFFC,
	                              CAVT_UNKNOWN, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursRemove (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT element)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x101,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, element);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursRemoveAll (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x103,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLineColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR lineColor)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x7,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, lineColor);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLineStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CW3DLineStyles lineStyle)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x8,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, lineStyle);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLineWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double lineWidth)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x9,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, lineWidth);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelFormat (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *label)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xA,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, label);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR labelColor)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xB,
	                              CAVT_EMPTY, NULL, 1, __paramTypes,
	                              labelColor);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font labelFont)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xC,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, labelFont);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelVisible (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL labelVisible)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xD,
	                              CAVT_EMPTY, NULL, 1, __paramTypes,
	                              labelVisible);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursAdd (CAObjHandle objectHandle,
                                            ERRORINFO *errorInfo, double level)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xE,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, level);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x100,
	                              DISPATCH_PROPERTYGET, CAVT_SHORT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetCount (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 short newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x100,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x100,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetAnchorEnabled (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetAnchorEnabled (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefAnchorEnabled (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetAnchor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetAnchor (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefAnchor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetBasis (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum CW3DGraphLibEnum_CWBases *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetBasis (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 enum CW3DGraphLibEnum_CWBases newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefBasis (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWBases *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetInterval (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetInterval (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefInterval (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetLevelList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_VARIANT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLevelList (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefLevelList (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, &newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetLevels (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLevels (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefLevels (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursGetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWContourLabelOrientationStyle *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xF,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 enum CW3DGraphLibEnum_CWContourLabelOrientationStyle newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xF,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContoursSetByRefLabelOrientationStyle (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      enum CW3DGraphLibEnum_CWContourLabelOrientationStyle *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContours, 0xF,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLevel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLevel (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLevel (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLineColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLineColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLineColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLineStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DLineStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLineStyle (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CW3DLineStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLineStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DLineStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLineWidth (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLineWidth (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLineWidth (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelFormat (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelFormat (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x7,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x7,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelFont (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_Font *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x7,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourGetLabelVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x8,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetLabelVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x8,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContourSetByRefLabelVisible (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWContour, 0x8,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightsItem (CAObjHandle objectHandle,
                                           ERRORINFO *errorInfo, VARIANT item,
                                           CW3DGraphLibObj_CWLight *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLights, 0x0,
	                              CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
	                              item);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLights_NewEnum (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               LPUNKNOWN *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLights, 0xFFFFFFFC,
	                              CAVT_UNKNOWN, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightsGetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLights, 0x100,
	                              DISPATCH_PROPERTYGET, CAVT_SHORT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightsSetCount (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               short newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLights, 0x100,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightsSetByRefCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLights, 0x100,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightGetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetEnabled (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefEnabled (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightGetAttenuation (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWLightAttenuationStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetAttenuation (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWLightAttenuationStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefAttenuation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWLightAttenuationStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightGetLatitude (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetLatitude (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefLatitude (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightGetLongitude (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetLongitude (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefLongitude (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightGetDistance (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetDistance (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefDistance (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightGetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetColor (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLightSetByRefColor (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWLight, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT item,
                                              CW3DGraphLibObj_CWCursor3D *returnValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x0,
	                              CAVT_OBJHANDLE, returnValue, 1, __paramTypes,
	                              item);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  LPUNKNOWN *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0xFFFFFFFC,
	                              CAVT_UNKNOWN, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DRemove (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT element)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_VARIANT};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x101,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, element);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DRemoveAll (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x103,
	                              CAVT_EMPTY, NULL, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DAdd (CAObjHandle objectHandle,
                                             ERRORINFO *errorInfo,
                                             CW3DGraphLibObj_CWCursor3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x102,
	                              CAVT_OBJHANDLE, returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x100,
	                              DISPATCH_PROPERTYGET, CAVT_SHORT,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DSetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x100,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3DSetByRefCount (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       short *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_SHORT | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursors3D, 0x100,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPosition (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double x, double y, double z)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE, CAVT_DOUBLE, CAVT_DOUBLE};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1B,
	                              CAVT_EMPTY, NULL, 3, __paramTypes, x, y, z);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR color)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_MethodInvokeEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1C,
	                              CAVT_EMPTY, NULL, 1, __paramTypes, color);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefEnabled (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xFFFFFDFE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGet_Name (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x0,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSet_Name (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x0,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRef_Name (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x0,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetName (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                char **returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1,
	                              DISPATCH_PROPERTYGET, CAVT_CSTRING,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetName (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                const char *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefName (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     char **newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_CSTRING | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetVisible (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x2,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetVisible (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x2,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefVisible (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x2,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetXPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x3,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetXPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x3,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefXPosition (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x3,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetYPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x4,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetYPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x4,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefYPosition (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x4,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetZPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x5,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetZPosition (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x5,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefZPosition (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x5,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPlot (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWPlot3D *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x6,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPlot (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWPlot3D newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x6,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPlot (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWPlot3D *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x6,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x7,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetRow (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x7,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefRow (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x7,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetColumn (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x8,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetColumn (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x8,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefColumn (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x8,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetNameVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x9,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetNameVisible (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x9,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefNameVisible (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x9,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPositionVisible (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xA,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPositionVisible (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xA,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPositionVisible (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xA,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetXYPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xB,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetXYPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xB,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefXYPlaneVisible (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xB,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetXZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xC,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetXZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xC,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefXZPlaneVisible (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xC,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetYZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xD,
	                              DISPATCH_PROPERTYGET, CAVT_BOOL, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetYZPlaneVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xD,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefYZPlaneVisible (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               VBOOL *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_BOOL | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xD,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xE,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                      ERRORINFO *errorInfo,
                                                                      long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xE,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                           ERRORINFO *errorInfo,
                                                                           long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xE,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPointColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xF,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPointColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xF,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPointColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0xF,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetLineColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x10,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetLineColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x10,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefLineColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x10,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetTextColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x11,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetTextColor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x11,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefTextColor (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x11,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetTextBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x12,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetTextBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x12,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefTextBackColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x12,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPlaneColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x13,
	                              DISPATCH_PROPERTYGET, CAVT_ULONG,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPlaneColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x13,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPlaneColor (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           CW3DGraphLibType_OLE_COLOR *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_ULONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x13,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPointSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x14,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPointSize (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x14,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPointSize (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x14,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetLineWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x15,
	                              DISPATCH_PROPERTYGET, CAVT_DOUBLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetLineWidth (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x15,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefLineWidth (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          double *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_DOUBLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x15,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPlaneTransparency (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x16,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPlaneTransparency (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             long newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x16,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPlaneTransparency (CAObjHandle objectHandle,
                                                                  ERRORINFO *errorInfo,
                                                                  long *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x16,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetPointStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DPointStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x17,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetPointStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DPointStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x17,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefPointStyle (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           enum CW3DGraphLibEnum_CW3DPointStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x17,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetLineStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CW3DLineStyles *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x18,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetLineStyle (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     enum CW3DGraphLibEnum_CW3DLineStyles newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x18,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefLineStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CW3DLineStyles *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x18,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetSnapMode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWCursor3DSnapModes *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x19,
	                              DISPATCH_PROPERTYGET, CAVT_LONG, returnValue,
	                              0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetSnapMode (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWCursor3DSnapModes newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x19,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefSnapMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWCursor3DSnapModes *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_LONG | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x19,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DGetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font *returnValue)
{
	HRESULT __result = S_OK;

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1A,
	                              DISPATCH_PROPERTYGET, CAVT_OBJHANDLE,
	                              returnValue, 0, NULL);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetFont (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_Font newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1A,
	                              DISPATCH_PROPERTYPUT, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3DSetByRefFont (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_Font *newValue)
{
	HRESULT __result = S_OK;
	unsigned int __paramTypes[] = {CAVT_OBJHANDLE | CAVT_BYREFI};

	__result = CA_InvokeHelperEx (objectHandle, errorInfo,
	                              &CW3DGraphLib_IID_CWCursor3D, 0x1A,
	                              DISPATCH_PROPERTYPUTREF, CAVT_EMPTY, NULL, 1,
	                              __paramTypes, newValue);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_CIGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxes3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxes3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCount_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxes3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_CIItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT item,
                                              CW3DGraphLibObj_CWAxis3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxes3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxes3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Item_ (__vtblIFacePtr, item,
	                                           &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWAxis3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxes3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxes3D_CI_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxes3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxes3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->_NewEnum_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &IID_IUnknown,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxes3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetLog (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLog_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetLog (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo, VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLog_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetMaximum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMaximum_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetMaximum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMaximum_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetMinimum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinimum_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetMinimum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinimum_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetInverted (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInverted_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetInverted (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetInverted_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetName_ (__vtblIFacePtr,
	                                              &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetName_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoScale_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoScale_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetTicks (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWTicks3D_CI *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTicks_ (__vtblIFacePtr,
	                                               &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_CWTicks3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetFormatString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFormatString_ (__vtblIFacePtr,
	                                                      &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetFormatString (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFormatString_ (__vtblIFacePtr,
	                                                      pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetLabels (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWLabels3D_CI *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabels_ (__vtblIFacePtr,
	                                                &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_CWLabels3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVisible_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVisible_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaption_ (__vtblIFacePtr,
	                                                 &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaption (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaption_ (__vtblIFacePtr,
	                                                 pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptionColor_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptionColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionNormal (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptionNormal_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionNormal (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptionNormal_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionOpposite (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptionOpposite_ (__vtblIFacePtr,
	                                                         &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionOpposite (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptionOpposite_ (__vtblIFacePtr,
	                                                         pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionFont (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibObj_Font *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptionFont_ (__vtblIFacePtr,
	                                                     &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_Font,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionFont (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibObj_Font pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;

	if (pVal)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pVal, &CW3DGraphLib_IID_Font, 1,
	                                          &pVal__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptionFont_ (__vtblIFacePtr,
	                                                     pVal__AutoType));

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetMinMax (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT minimum,
                                                   VARIANT maximum)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinMax_ (__vtblIFacePtr, minimum,
	                                                maximum));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetValuePairs (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_CWValuePairs_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetValuePairs_ (__vtblIFacePtr,
	                                                    &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWValuePairs_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIAutoScaleNow (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AutoScaleNow_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CIGetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptionOrientationStyle_ (__vtblIFacePtr,
	                                                                 (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWAxis3D_CISetCaptionOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWAxisTextOrientationStyle pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWAxis3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWAxis3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptionOrientationStyle_ (__vtblIFacePtr,
	                                                                 pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWAxis3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetInside (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInside_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetInside (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetInside_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetOutside (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetOutside_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetOutside (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetOutside_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetNormal (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetNormal_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetNormal (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetNormal_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetOpposite (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetOpposite_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetOpposite (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetOpposite_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorDivisions_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorDivisions_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinorDivisions_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorDivisions (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinorDivisions_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetAutoDivisions (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoDivisions_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetAutoDivisions (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoDivisions_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorUnitsInterval_ (__vtblIFacePtr,
	                                                            &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorUnitsInterval_ (__vtblIFacePtr,
	                                                            pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorUnitsBase (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorUnitsBase_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorUnitsBase (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorUnitsBase_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinorUnitsInterval_ (__vtblIFacePtr,
	                                                            &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorUnitsInterval (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinorUnitsInterval_ (__vtblIFacePtr,
	                                                            pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorGrid_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorGrid_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinorGrid_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorGrid (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinorGrid_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorGridColor_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorGridColor_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinorGridColor_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorGridColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinorGridColor_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorTicks_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorTicks_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinorTicks_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorTicks (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinorTicks_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMajorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorTickColor_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMajorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorTickColor_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CIGetMinorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMinorTickColor_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWTicks3D_CISetMinorTickColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWTicks3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWTicks3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMinorTickColor_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWTicks3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetNormal (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetNormal_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetNormal (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetNormal_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetOpposite (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetOpposite_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetOpposite (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetOpposite_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColor_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFont_ (__vtblIFacePtr,
	                                              &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_Font,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;

	if (pVal)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pVal, &CW3DGraphLib_IID_Font, 1,
	                                          &pVal__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFont_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CIGetOrientationStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWAxisTextOrientationStyle *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetOrientationStyle_ (__vtblIFacePtr,
	                                                          (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLabels3D_CISetOrientationStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWAxisTextOrientationStyle pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLabels3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLabels3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetOrientationStyle_ (__vtblIFacePtr,
	                                                          pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLabels3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetCount (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      short *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCount_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetLabelType (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWValuePairLabels *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelType_ (__vtblIFacePtr,
	                                                   (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetLabelType (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWValuePairLabels pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelType_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetLocation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWValuePairLocations *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLocation_ (__vtblIFacePtr,
	                                                  (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetLocation (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWValuePairLocations pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLocation_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetMajorTicks (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMajorTicks_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetMajorTicks (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMajorTicks_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIGetGridLines (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridLines_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISetGridLines (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridLines_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIItem (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT item,
                                                  CW3DGraphLibObj_CWValuePair_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Item_ (__vtblIFacePtr, item,
	                                           &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWValuePair_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CI_NewEnum (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CAObjHandle *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->_NewEnum_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &IID_IUnknown,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIRemove (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT element)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Remove_ (__vtblIFacePtr, element));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIRemoveAll (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RemoveAll_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CIAdd (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibObj_CWValuePair_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Add_ (__vtblIFacePtr,
	                                          &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWValuePair_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePairs_CISwap (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT element1,
                                                  VARIANT element2)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePairs_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePairs_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Swap_ (__vtblIFacePtr, element1,
	                                           element2));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePairs_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CIGetName (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePair_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePair_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetName_ (__vtblIFacePtr,
	                                              &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePair_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CISetName (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePair_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePair_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetName_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePair_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CIGetValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePair_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePair_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetValue_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePair_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWValuePair_CISetValue (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWValuePair_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWValuePair_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetValue_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWValuePair_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIGetCount (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   short *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlots3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlots3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCount_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlots3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIItem (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               VARIANT item,
                                               CW3DGraphLibObj_CWPlot3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlots3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlots3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Item_ (__vtblIFacePtr, item,
	                                           &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWPlot3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlots3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CI_NewEnum (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CAObjHandle *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlots3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlots3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->_NewEnum_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &IID_IUnknown,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlots3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIRemove (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT element)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlots3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlots3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Remove_ (__vtblIFacePtr, element));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlots3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIRemoveAll (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlots3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlots3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RemoveAll_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlots3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlots3D_CIAdd (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo,
                                              CW3DGraphLibObj_CWPlot3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlots3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlots3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Add_ (__vtblIFacePtr,
	                                          &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWPlot3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlots3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetEnabled (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetName_ (__vtblIFacePtr,
	                                              &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetName (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetName_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVisible_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetVisible (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVisible_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetMultiPlot (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetMultiPlot_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetMultiPlot (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetMultiPlot_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAutoScale_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetAutoScale (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAutoScale_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetStyle (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum CW3DGraphLibEnum_CWPlot3DStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetStyle_ (__vtblIFacePtr,
	                                               (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetStyle (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  enum CW3DGraphLibEnum_CWPlot3DStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetFillStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWFillStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFillStyle_ (__vtblIFacePtr,
	                                                   (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetFillStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CWFillStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFillStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetFillColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFillColor_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetFillColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFillColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetLineStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DLineStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineStyle_ (__vtblIFacePtr,
	                                                   (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetLineStyle (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      enum CW3DGraphLibEnum_CW3DLineStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetLineColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineColor_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetLineColor (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetLineWidth (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineWidth_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetLineWidth (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineWidth_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DPointStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointStyle_ (__vtblIFacePtr,
	                                                    (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DPointStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointColor_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointSize_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointSize (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointSize_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetPointFrequency (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointFrequency_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetPointFrequency (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointFrequency_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetCacheData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCacheData_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetCacheData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCacheData_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWColorMapStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorMapStyle_ (__vtblIFacePtr,
	                                                       (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapStyle (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          enum CW3DGraphLibEnum_CWColorMapStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorMapStyle_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetCoordinateSystem (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum CW3DGraphLibEnum_CWCoordinateSystems *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCoordinateSystem_ (__vtblIFacePtr,
	                                                          (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetCoordinateSystem (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             enum CW3DGraphLibEnum_CWCoordinateSystems pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCoordinateSystem_ (__vtblIFacePtr,
	                                                          pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetProjectionXY (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetProjectionXY_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetProjectionXY (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetProjectionXY_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetProjectionXZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetProjectionXZ_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetProjectionXZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetProjectionXZ_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetProjectionYZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetProjectionYZ_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetProjectionYZ (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetProjectionYZ_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetShowProjectionsOnly (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetShowProjectionsOnly_ (__vtblIFacePtr,
	                                                             &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetShowProjectionsOnly (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetShowProjectionsOnly_ (__vtblIFacePtr,
	                                                             pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetTransparency (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTransparency_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetTransparency (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTransparency_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapInterpolate (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorMapInterpolate_ (__vtblIFacePtr,
	                                                             &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapInterpolate (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorMapInterpolate_ (__vtblIFacePtr,
	                                                             pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapAutoScale (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorMapAutoScale_ (__vtblIFacePtr,
	                                                           &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapAutoScale (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorMapAutoScale_ (__vtblIFacePtr,
	                                                           pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapLog (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorMapLog_ (__vtblIFacePtr,
	                                                     &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapLog (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorMapLog_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapValueVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorMapValueVector_ (__vtblIFacePtr,
	                                                             &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapValueVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorMapValueVector_ (__vtblIFacePtr,
	                                                             pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetColorMapColorVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColorMapColorVector_ (__vtblIFacePtr,
	                                                             &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CISetColorMapColorVector (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColorMapColorVector_ (__vtblIFacePtr,
	                                                             pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIClearData (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearData_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VARIANT zMatrix,
                                                             VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DSimpleSurface_ (__vtblIFacePtr,
	                                                          zMatrix, wMatrix));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DSurface (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT xVector,
                                                       VARIANT yVector,
                                                       VARIANT zMatrix,
                                                       VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DSurface_ (__vtblIFacePtr,
	                                                    xVector, yVector,
	                                                    zMatrix, wMatrix));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DParametricSurface (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VARIANT xMatrix,
                                                                 VARIANT yMatrix,
                                                                 VARIANT zMatrix,
                                                                 VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DParametricSurface_ (__vtblIFacePtr,
	                                                              xMatrix,
	                                                              yMatrix,
	                                                              zMatrix,
	                                                              wMatrix));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DCurve (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     VARIANT xVector,
                                                     VARIANT yVector,
                                                     VARIANT zVector,
                                                     VARIANT wVector)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DCurve_ (__vtblIFacePtr, xVector,
	                                                  yVector, zVector,
	                                                  wVector));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetContours (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWContours_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetContours_ (__vtblIFacePtr,
	                                                  &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWContours_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetXAxis (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWAxis3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetXAxis_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWAxis3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetYAxis (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWAxis3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetYAxis_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWAxis3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIGetZAxis (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CW3DGraphLibObj_CWAxis3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetZAxis_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWAxis3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWPlot3D_CIPlot3DMesh (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    VARIANT xVector,
                                                    VARIANT yVector,
                                                    VARIANT zVector,
                                                    VARIANT wVector)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWPlot3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DMesh_ (__vtblIFacePtr, xVector,
	                                                 yVector, zVector, wVector));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWPlot3D_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetCount (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    short *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCount_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetAnchorEnabled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAnchorEnabled_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetAnchorEnabled (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAnchorEnabled_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetAnchor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAnchor_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetAnchor (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAnchor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetBasis (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWBases *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBasis_ (__vtblIFacePtr,
	                                               (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetBasis (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    enum CW3DGraphLibEnum_CWBases pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBasis_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetInterval (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetInterval_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetInterval (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetInterval_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetLevelList (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VARIANT pVal__Temp;

	if (pVal)
		CA_VariantSetEmpty (pVal);
	CA_VariantSetEmpty (&pVal__Temp);

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLevelList_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		CA_VariantSetEmpty (&pVal__Temp);
		}

Error:
	CA_VariantClear (&pVal__Temp);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			CA_VariantClear (pVal);
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLevelList (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLevelList_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetLevels (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLevels_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLevels (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLevels_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIItem (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                VARIANT item,
                                                CW3DGraphLibObj_CWContour_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Item_ (__vtblIFacePtr, item,
	                                           &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWContour_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CI_NewEnum (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CAObjHandle *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->_NewEnum_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &IID_IUnknown,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIRemove (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  VARIANT element)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Remove_ (__vtblIFacePtr, element));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIRemoveAll (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RemoveAll_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR lineColor)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineColor_ (__vtblIFacePtr,
	                                                   lineColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles lineStyle)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineStyle_ (__vtblIFacePtr,
	                                                   lineStyle));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double lineWidth)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineWidth_ (__vtblIFacePtr,
	                                                   lineWidth));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelFormat (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          const char *label)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR label__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (label, &label__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelFormat_ (__vtblIFacePtr,
	                                                     label__AutoType));

Error:
	CA_FreeBSTR (label__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR labelColor)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelColor_ (__vtblIFacePtr,
	                                                    labelColor));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelFont (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibObj_Font labelFont)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH labelFont__AutoType = 0;

	if (labelFont)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (labelFont,
	                                          &CW3DGraphLib_IID_Font, 1,
	                                          &labelFont__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelFont_ (__vtblIFacePtr,
	                                                   labelFont__AutoType));

Error:
	if (labelFont__AutoType)
		labelFont__AutoType->lpVtbl->Release (labelFont__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelVisible (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           VBOOL labelVisible)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelVisible_ (__vtblIFacePtr,
	                                                      labelVisible));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIAdd (CAObjHandle objectHandle,
                                               ERRORINFO *errorInfo,
                                               double level)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Add_ (__vtblIFacePtr, level));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CIGetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWContourLabelOrientationStyle *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelOrientationStyle_ (__vtblIFacePtr,
	                                                               (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContours_CISetLabelOrientationStyle (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    enum CW3DGraphLibEnum_CWContourLabelOrientationStyle pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContours_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContours_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelOrientationStyle_ (__vtblIFacePtr,
	                                                               pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContours_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLevel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLevel_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLevel (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLevel_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLineColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineColor_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLineColor (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLineStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DLineStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineStyle_ (__vtblIFacePtr,
	                                                   (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLineStyle (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CW3DLineStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLineWidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineWidth_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLineWidth (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineWidth_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelFormat (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelFormat_ (__vtblIFacePtr,
	                                                     &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelFormat (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelFormat_ (__vtblIFacePtr,
	                                                     pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelColor_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelFont (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_Font *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelFont_ (__vtblIFacePtr,
	                                                   &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_Font,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelFont (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_Font pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;

	if (pVal)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pVal, &CW3DGraphLib_IID_Font, 1,
	                                          &pVal__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelFont_ (__vtblIFacePtr,
	                                                   pVal__AutoType));

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CIGetLabelVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLabelVisible_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWContour_CISetLabelVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWContour_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWContour_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLabelVisible_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWContour_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLights_CIGetCount (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  short *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLights_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLights_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCount_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLights_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLights_CIItem (CAObjHandle objectHandle,
                                              ERRORINFO *errorInfo, VARIANT item,
                                              CW3DGraphLibObj_CWLight_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLights_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLights_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Item_ (__vtblIFacePtr, item,
	                                           &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWLight_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLights_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLights_CI_NewEnum (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  CAObjHandle *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLights_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLights_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->_NewEnum_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &IID_IUnknown,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLights_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetEnabled (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetAttenuation (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWLightAttenuationStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAttenuation_ (__vtblIFacePtr,
	                                                     (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetAttenuation (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWLightAttenuationStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAttenuation_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetLatitude (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLatitude_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetLatitude (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLatitude_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetLongitude (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLongitude_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetLongitude (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLongitude_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetDistance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDistance_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetDistance (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDistance_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CIGetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColor_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWLight_CISetColor (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWLight_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWLight_CI, 0,
	                                          &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWLight_CI, __result,
	                    errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIGetCount (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     short *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursors3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	short pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursors3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCount_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursors3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIItem (CAObjHandle objectHandle,
                                                 ERRORINFO *errorInfo,
                                                 VARIANT item,
                                                 CW3DGraphLibObj_CWCursor3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursors3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursors3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Item_ (__vtblIFacePtr, item,
	                                           &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWCursor3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursors3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CI_NewEnum (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CAObjHandle *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursors3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursors3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->_NewEnum_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &IID_IUnknown,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursors3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIRemove (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   VARIANT element)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursors3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursors3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Remove_ (__vtblIFacePtr, element));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursors3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIRemoveAll (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursors3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursors3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->RemoveAll_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursors3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursors3D_CIAdd (CAObjHandle objectHandle,
                                                ERRORINFO *errorInfo,
                                                CW3DGraphLibObj_CWCursor3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursors3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursors3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Add_ (__vtblIFacePtr,
	                                          &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWCursor3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursors3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetEnabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetEnabled (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetName_ (__vtblIFacePtr,
	                                              &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetName (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetName_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetVisible_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetVisible (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetVisible_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetXPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetXPosition_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetXPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetXPosition_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetYPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetYPosition_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetYPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetYPosition_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetZPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetZPosition_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetZPosition (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetZPosition_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWPlot3D_CI *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlot_ (__vtblIFacePtr,
	                                              &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_CWPlot3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPlot (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_CWPlot3D_CI pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pVal__AutoType = 0;

	if (pVal)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pVal,
	                                          &CW3DGraphLib_IID_CWPlot3D_CI, 1,
	                                          &pVal__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPlot_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetRow_ (__vtblIFacePtr, &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetRow (CAObjHandle objectHandle,
                                                  ERRORINFO *errorInfo,
                                                  long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetRow_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetColumn (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetColumn_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetColumn (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColumn_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetNameVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetNameVisible_ (__vtblIFacePtr,
	                                                     &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetNameVisible (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetNameVisible_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPositionVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPositionVisible_ (__vtblIFacePtr,
	                                                         &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPositionVisible (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPositionVisible_ (__vtblIFacePtr,
	                                                         pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetXYPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetXYPlaneVisible_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetXYPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetXYPlaneVisible_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetXZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetXZPlaneVisible_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetXZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetXZPlaneVisible_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetYZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetYZPlaneVisible_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetYZPlaneVisible (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetYZPlaneVisible_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTextBackgroundTransparency_ (__vtblIFacePtr,
	                                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetTextBackgroundTransparency (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTextBackgroundTransparency_ (__vtblIFacePtr,
	                                                                    pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPointColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointColor_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPointColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineColor_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetLineColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetTextColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTextColor_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetTextColor (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTextColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetTextBackColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTextBackColor_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetTextBackColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTextBackColor_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPlaneColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlaneColor_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPlaneColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPlaneColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPointSize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointSize_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPointSize (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointSize_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineWidth_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetLineWidth (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineWidth_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPlaneTransparency (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlaneTransparency_ (__vtblIFacePtr,
	                                                           &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPlaneTransparency (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                long pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPlaneTransparency_ (__vtblIFacePtr,
	                                                           pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetPointStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DPointStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPointStyle_ (__vtblIFacePtr,
	                                                    (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPointStyle (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CW3DPointStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPointStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLineStyle_ (__vtblIFacePtr,
	                                                   (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetLineStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CW3DLineStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLineStyle_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetSnapMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWCursor3DSnapModes *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetSnapMode_ (__vtblIFacePtr,
	                                                  (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetSnapMode (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       enum CW3DGraphLibEnum_CWCursor3DSnapModes pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetSnapMode_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CIGetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFont_ (__vtblIFacePtr,
	                                              &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_Font,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetFont (CAObjHandle objectHandle,
                                                   ERRORINFO *errorInfo,
                                                   CW3DGraphLibObj_Font pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;

	if (pVal)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pVal, &CW3DGraphLib_IID_Font, 1,
	                                          &pVal__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFont_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetPosition (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       double x, double y,
                                                       double z)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPosition_ (__vtblIFacePtr, x, y, z));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib_CWCursor3D_CISetColor (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibType_OLE_COLOR color)
{
	HRESULT __result = S_OK;
	CW3DGraphLib_CWCursor3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID_CWCursor3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetColor_ (__vtblIFacePtr, color));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID_CWCursor3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetEnabled (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetEnabled_ (__vtblIFacePtr,
	                                                 &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetEnabled (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetEnabled_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFont_ (__vtblIFacePtr,
	                                              &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_Font,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetFont (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_Font pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pVal__AutoType = 0;

	if (pVal)
		{
		__caErrChk (CA_GetInterfaceFromObjHandle (pVal, &CW3DGraphLib_IID_Font, 1,
	                                          &pVal__AutoType, NULL));
		}

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFont_ (__vtblIFacePtr,
	                                              pVal__AutoType));

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetCaption (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       char **pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaption_ (__vtblIFacePtr,
	                                                 &pVal__AutoType));

	if (pVal)
		__caErrChk (CA_BSTRGetCString (pVal__AutoType, pVal));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_FreeMemory (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetCaption (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       const char *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR pVal__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (pVal, &pVal__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaption_ (__vtblIFacePtr,
	                                                 pVal__AutoType));

Error:
	CA_FreeBSTR (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetBackColor_ (__vtblIFacePtr,
	                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetBackColor (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetBackColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetReadyState (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          long *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetReadyState_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetPlotAreaColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlotAreaColor_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetPlotAreaColor (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetPlotAreaColor_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGraphFrameColor (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGraphFrameColor_ (__vtblIFacePtr,
	                                                         &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGraphFrameColor (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGraphFrameColor_ (__vtblIFacePtr,
	                                                         pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetTrackMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWGraph3DTrackModes *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetTrackMode_ (__vtblIFacePtr,
	                                                   (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetTrackMode (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         enum CW3DGraphLibEnum_CWGraph3DTrackModes pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetTrackMode_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetPlotTemplate (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibObj_CWPlot3D_CI *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pVal__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pVal)
		*pVal = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlotTemplate_ (__vtblIFacePtr,
	                                                      &pVal__AutoType));
	

	if (pVal)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pVal__AutoType,
		                                             &CW3DGraphLib_IID_CWPlot3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pVal));
		pVal__AutoType = 0;
		}

Error:
	if (pVal__AutoType)
		pVal__AutoType->lpVtbl->Release (pVal__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pVal)
			{
			CA_DiscardObjHandle (*pVal);
			*pVal = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetImmediateUpdates (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetImmediateUpdates_ (__vtblIFacePtr,
	                                                          &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetImmediateUpdates (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetImmediateUpdates_ (__vtblIFacePtr,
	                                                          pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetWindowless (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetWindowless_ (__vtblIFacePtr,
	                                                    &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetWindowless (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetWindowless_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetCaptionColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCaptionColor_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetCaptionColor (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetCaptionColor_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetKeyboardMode (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWKeyboardModes *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetKeyboardMode_ (__vtblIFacePtr,
	                                                      (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetKeyboardMode (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            enum CW3DGraphLibEnum_CWKeyboardModes pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetKeyboardMode_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGraphFrameVisible (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGraphFrameVisible_ (__vtblIFacePtr,
	                                                           &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGraphFrameVisible (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGraphFrameVisible_ (__vtblIFacePtr,
	                                                           pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetDither (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetDither_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetDither (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDither_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetFastDraw (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetFastDraw_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetFastDraw (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetFastDraw_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridFrameColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridFrameColor_ (__vtblIFacePtr,
	                                                        &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridFrameColor (CAObjHandle objectHandle,
                                                              ERRORINFO *errorInfo,
                                                              CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridFrameColor_ (__vtblIFacePtr,
	                                                        pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridSmoothing (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridSmoothing_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridSmoothing (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridSmoothing_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridXY_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridXY (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridXY_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridXZ_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridXZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridXZ_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetGridYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetGridYZ_ (__vtblIFacePtr,
	                                                &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetGridYZ (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetGridYZ_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetLighting (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLighting_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetLighting (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetLighting_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetAmbientLightColor (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CW3DGraphLibType_OLE_COLOR *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	unsigned long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAmbientLightColor_ (__vtblIFacePtr,
	                                                           &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetAmbientLightColor (CAObjHandle objectHandle,
                                                                 ERRORINFO *errorInfo,
                                                                 CW3DGraphLibType_OLE_COLOR pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetAmbientLightColor_ (__vtblIFacePtr,
	                                                           pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetProjectionStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWGraph3DProjectionStyles *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetProjectionStyle_ (__vtblIFacePtr,
	                                                         (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetProjectionStyle (CAObjHandle objectHandle,
                                                               ERRORINFO *errorInfo,
                                                               enum CW3DGraphLibEnum_CWGraph3DProjectionStyles pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetProjectionStyle_ (__vtblIFacePtr,
	                                                         pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewAutoDistance (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewAutoDistance_ (__vtblIFacePtr,
	                                                          &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewAutoDistance (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewAutoDistance_ (__vtblIFacePtr,
	                                                          pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewDistance (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewDistance_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewDistance (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewDistance_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewLatitude (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewLatitude_ (__vtblIFacePtr,
	                                                      &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewLatitude (CAObjHandle objectHandle,
                                                            ERRORINFO *errorInfo,
                                                            double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewLatitude_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewLongitude (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewLongitude_ (__vtblIFacePtr,
	                                                       &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewLongitude (CAObjHandle objectHandle,
                                                             ERRORINFO *errorInfo,
                                                             double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewLongitude_ (__vtblIFacePtr,
	                                                       pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CWGraph3DViewModes *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	long pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewMode_ (__vtblIFacePtr,
	                                                  (long *)&pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewMode (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        enum CW3DGraphLibEnum_CWGraph3DViewModes pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewMode_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewXCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewXCenter_ (__vtblIFacePtr,
	                                                     &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewXCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewXCenter_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewYCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewYCenter_ (__vtblIFacePtr,
	                                                     &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewYCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewYCenter_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetViewZCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	double pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetViewZCenter_ (__vtblIFacePtr,
	                                                     &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetViewZCenter (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           double pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetViewZCenter_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetClipData (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetClipData_ (__vtblIFacePtr,
	                                                  &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetClipData (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetClipData_ (__vtblIFacePtr, pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         VBOOL *pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	VBOOL pVal__Temp;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetUse3DHardwareAcceleration_ (__vtblIFacePtr,
	                                                                   &pVal__Temp));

	if (pVal)
		{
		*pVal = pVal__Temp;
		}

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetUse3DHardwareAcceleration (CAObjHandle objectHandle,
                                                                         ERRORINFO *errorInfo,
                                                                         VBOOL pVal)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetUse3DHardwareAcceleration_ (__vtblIFacePtr,
	                                                                   pVal));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIImportStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *fileName)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR fileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (fileName, &fileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ImportStyle_ (__vtblIFacePtr,
	                                                  fileName__AutoType));

Error:
	CA_FreeBSTR (fileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIExportStyle (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        const char *fileName)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	BSTR fileName__AutoType = 0;

	__caErrChk (CA_CStringToBSTR (fileName, &fileName__AutoType));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ExportStyle_ (__vtblIFacePtr,
	                                                  fileName__AutoType));

Error:
	CA_FreeBSTR (fileName__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetPlots (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo,
                                                     CW3DGraphLibObj_CWPlots3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetPlots_ (__vtblIFacePtr,
	                                               &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWPlots3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetAxes (CAObjHandle objectHandle,
                                                    ERRORINFO *errorInfo,
                                                    CW3DGraphLibObj_CWAxes3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetAxes_ (__vtblIFacePtr,
	                                              &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWAxes3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIClearData (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ClearData_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIControlImage (CAObjHandle objectHandle,
                                                         ERRORINFO *errorInfo,
                                                         CW3DGraphLibObj_Picture *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ControlImage_ (__vtblIFacePtr,
	                                                   &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_Picture,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetLights (CAObjHandle objectHandle,
                                                      ERRORINFO *errorInfo,
                                                      CW3DGraphLibObj_CWLights_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetLights_ (__vtblIFacePtr,
	                                                &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWLights_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DSimpleSurface (CAObjHandle objectHandle,
                                                                ERRORINFO *errorInfo,
                                                                VARIANT zMatrix,
                                                                VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DSimpleSurface_ (__vtblIFacePtr,
	                                                          zMatrix, wMatrix));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DSurface (CAObjHandle objectHandle,
                                                          ERRORINFO *errorInfo,
                                                          VARIANT xVector,
                                                          VARIANT yVector,
                                                          VARIANT zMatrix,
                                                          VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DSurface_ (__vtblIFacePtr,
	                                                    xVector, yVector,
	                                                    zMatrix, wMatrix));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DParametricSurface (CAObjHandle objectHandle,
                                                                    ERRORINFO *errorInfo,
                                                                    VARIANT xMatrix,
                                                                    VARIANT yMatrix,
                                                                    VARIANT zMatrix,
                                                                    VARIANT wMatrix)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DParametricSurface_ (__vtblIFacePtr,
	                                                              xMatrix,
	                                                              yMatrix,
	                                                              zMatrix,
	                                                              wMatrix));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DCurve (CAObjHandle objectHandle,
                                                        ERRORINFO *errorInfo,
                                                        VARIANT xVector,
                                                        VARIANT yVector,
                                                        VARIANT zVector,
                                                        VARIANT wVector)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DCurve_ (__vtblIFacePtr, xVector,
	                                                  yVector, zVector,
	                                                  wVector));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIAboutBox (CAObjHandle objectHandle,
                                                     ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->AboutBox_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CISetDefaultView (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->SetDefaultView_ (__vtblIFacePtr));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIPlot3DMesh (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       VARIANT xVector,
                                                       VARIANT yVector,
                                                       VARIANT zVector,
                                                       VARIANT wVector)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->Plot3DMesh_ (__vtblIFacePtr, xVector,
	                                                 yVector, zVector, wVector));

Error:
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIGetCursors (CAObjHandle objectHandle,
                                                       ERRORINFO *errorInfo,
                                                       CW3DGraphLibObj_CWCursors3D_CI *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPUNKNOWN pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->GetCursors_ (__vtblIFacePtr,
	                                                 &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_CWCursors3D_CI,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3D_CIControlImageEx (CAObjHandle objectHandle,
                                                           ERRORINFO *errorInfo,
                                                           long dpiX, long dpiY,
                                                           CW3DGraphLibObj_Picture *pRetval)
{
	HRESULT __result = S_OK;
	CW3DGraphLib__DCWGraph3D_CI_Interface * __vtblIFacePtr = 0;
	int __didAddRef = 0;
	int __errorInfoPresent = 0;
	LPDISPATCH pRetval__AutoType = 0;
	LCID __locale;
	int __supportMultithreading;

	if (pRetval)
		*pRetval = 0;

	__caErrChk (CA_GetLocale (objectHandle, &__locale));
	__caErrChk (CA_GetSupportForMultithreading (objectHandle,
	                                            &__supportMultithreading));

	__caErrChk (CA_GetInterfaceFromObjHandle (objectHandle,
	                                          &CW3DGraphLib_IID__DCWGraph3D_CI,
	                                          0, &__vtblIFacePtr, &__didAddRef));
	__caErrChk (__vtblIFacePtr->lpVtbl->ControlImageEx_ (__vtblIFacePtr, dpiX,
	                                                     dpiY,
	                                                     &pRetval__AutoType));
	

	if (pRetval)
		{
		__caErrChk (CA_CreateObjHandleFromInterface (pRetval__AutoType,
		                                             &CW3DGraphLib_IID_Picture,
		                                             __supportMultithreading,
		                                             __locale, 0, 0, pRetval));
		pRetval__AutoType = 0;
		}

Error:
	if (pRetval__AutoType)
		pRetval__AutoType->lpVtbl->Release (pRetval__AutoType);
	if (__vtblIFacePtr && __didAddRef)
		__vtblIFacePtr->lpVtbl->Release (__vtblIFacePtr);
	if (FAILED(__result))
		{
		if (pRetval)
			{
			CA_DiscardObjHandle (*pRetval);
			*pRetval = 0;
			}
		}
	CA_FillErrorInfoEx (objectHandle, &CW3DGraphLib_IID__DCWGraph3D_CI,
	                    __result, errorInfo, &__errorInfoPresent);
	if (__errorInfoPresent)
		__result = DISP_E_EXCEPTION;
	return __result;
}

static void CVIFUNC _DCWGraph3DEventsRegOnClick_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnClick_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 0, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnDblClick_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnDblClick_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 1, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnMouseMove_EventVTableFunc (void *thisPtr,
                                                                     short button,
                                                                     short shift,
                                                                     long x,
                                                                     long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnMouseMove_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 2, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnMouseUp_EventVTableFunc (void *thisPtr,
                                                                   short button,
                                                                   short shift,
                                                                   long x,
                                                                   long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnMouseUp_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 3, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnMouseDown_EventVTableFunc (void *thisPtr,
                                                                     short button,
                                                                     short shift,
                                                                     long x,
                                                                     long y)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnMouseDown_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 4, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               x, y);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnKeyDown_EventVTableFunc (void *thisPtr,
                                                                   short *keyCode,
                                                                   short shift)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnKeyDown_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 5, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, keyCode, shift);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnKeyPress_EventVTableFunc (void *thisPtr,
                                                                    short *keyAscii)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnKeyPress_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 6, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, keyAscii);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnKeyUp_EventVTableFunc (void *thisPtr,
                                                                 short *keyCode,
                                                                 short shift)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnKeyUp_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 7, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, keyCode, shift);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPlotMouseDown_EventVTableFunc (void *thisPtr,
                                                                         short *button,
                                                                         short *shift,
                                                                         VARIANT *XData,
                                                                         VARIANT *YData,
                                                                         VARIANT *ZData,
                                                                         short *plotIndex,
                                                                         long *pointI,
                                                                         long *pointJ)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPlotMouseDown_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 8, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               XData, YData, ZData, plotIndex, pointI, pointJ);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPlotMouseMove_EventVTableFunc (void *thisPtr,
                                                                         short *button,
                                                                         short *shift,
                                                                         VARIANT *XData,
                                                                         VARIANT *YData,
                                                                         VARIANT *ZData,
                                                                         short *plotIndex,
                                                                         long *pointI,
                                                                         long *pointJ)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPlotMouseMove_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 9, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               XData, YData, ZData, plotIndex, pointI, pointJ);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPlotMouseUp_EventVTableFunc (void *thisPtr,
                                                                       short *button,
                                                                       short *shift,
                                                                       VARIANT *XData,
                                                                       VARIANT *YData,
                                                                       VARIANT *ZData,
                                                                       short *plotIndex,
                                                                       long *pointI,
                                                                       long *pointJ)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPlotMouseUp_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 10, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               XData, YData, ZData, plotIndex, pointI, pointJ);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPlotAreaMouseDown_EventVTableFunc (void *thisPtr,
                                                                             short *button,
                                                                             short *shift,
                                                                             VARIANT *XNear,
                                                                             VARIANT *YNear,
                                                                             VARIANT *ZNear,
                                                                             VARIANT *XFar,
                                                                             VARIANT *YFar,
                                                                             VARIANT *ZFar)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPlotAreaMouseDown_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 11, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               XNear, YNear, ZNear, XFar, YFar, ZFar);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPlotAreaMouseMove_EventVTableFunc (void *thisPtr,
                                                                             short *button,
                                                                             short *shift,
                                                                             VARIANT *XNear,
                                                                             VARIANT *YNear,
                                                                             VARIANT *ZNear,
                                                                             VARIANT *XFar,
                                                                             VARIANT *YFar,
                                                                             VARIANT *ZFar)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPlotAreaMouseMove_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 12, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               XNear, YNear, ZNear, XFar, YFar, ZFar);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPlotAreaMouseUp_EventVTableFunc (void *thisPtr,
                                                                           short *button,
                                                                           short *shift,
                                                                           VARIANT *XNear,
                                                                           VARIANT *YNear,
                                                                           VARIANT *ZNear,
                                                                           VARIANT *XFar,
                                                                           VARIANT *YFar,
                                                                           VARIANT *ZFar)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPlotAreaMouseUp_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 13, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, button, shift,
		                               XNear, YNear, ZNear, XFar, YFar, ZFar);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnZoom_EventVTableFunc (void *thisPtr,
                                                                VARIANT *newDistance)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnZoom_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 14, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, newDistance);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnPan_EventVTableFunc (void *thisPtr,
                                                               VARIANT *newXCenter,
                                                               VARIANT *newYCenter,
                                                               VARIANT *newZCenter)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnPan_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 15, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, newXCenter,
		                               newYCenter, newZCenter);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnRotate_EventVTableFunc (void *thisPtr,
                                                                  VARIANT *newLatitude,
                                                                  VARIANT *newLongitude)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnRotate_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 16, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, newLatitude,
		                               newLongitude);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnCursorChange_EventVTableFunc (void *thisPtr,
                                                                        long *cursorIndex,
                                                                        double *XPosition,
                                                                        double *YPosition,
                                                                        double *ZPosition,
                                                                        VBOOL *tracking)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnCursorChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 17, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData, cursorIndex,
		                               XPosition, YPosition, ZPosition, tracking);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

static void CVIFUNC _DCWGraph3DEventsRegOnReadyStateChange_EventVTableFunc (void *thisPtr)
{
	HRESULT __result = S_OK;
	void * __callbackData;
	CAObjHandle __serverObjHandle;
	_DCWGraph3DEventsRegOnReadyStateChange_CallbackType __callbackFunction;
	
	

	__caErrChk (CA_GetEventCallback (thisPtr, 18, &__callbackFunction,
	                                 &__callbackData, &__serverObjHandle));

	if (__callbackFunction != NULL)
		{
	
		__result = __callbackFunction (__serverObjHandle, __callbackData);
	
		__caErrChk (__result);
		
		}
Error:

	return;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnClick (CAObjHandle serverObject,
                                                          _DCWGraph3DEventsRegOnClick_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     0, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnDblClick (CAObjHandle serverObject,
                                                             _DCWGraph3DEventsRegOnDblClick_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     1, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnMouseMove (CAObjHandle serverObject,
                                                              _DCWGraph3DEventsRegOnMouseMove_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     2, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnMouseUp (CAObjHandle serverObject,
                                                            _DCWGraph3DEventsRegOnMouseUp_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     3, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnMouseDown (CAObjHandle serverObject,
                                                              _DCWGraph3DEventsRegOnMouseDown_CallbackType callbackFunction,
                                                              void *callbackData,
                                                              int enableCallbacks,
                                                              int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     4, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnKeyDown (CAObjHandle serverObject,
                                                            _DCWGraph3DEventsRegOnKeyDown_CallbackType callbackFunction,
                                                            void *callbackData,
                                                            int enableCallbacks,
                                                            int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     5, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnKeyPress (CAObjHandle serverObject,
                                                             _DCWGraph3DEventsRegOnKeyPress_CallbackType callbackFunction,
                                                             void *callbackData,
                                                             int enableCallbacks,
                                                             int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     6, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnKeyUp (CAObjHandle serverObject,
                                                          _DCWGraph3DEventsRegOnKeyUp_CallbackType callbackFunction,
                                                          void *callbackData,
                                                          int enableCallbacks,
                                                          int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     7, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotMouseDown (CAObjHandle serverObject,
                                                                  _DCWGraph3DEventsRegOnPlotMouseDown_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     8, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotMouseMove (CAObjHandle serverObject,
                                                                  _DCWGraph3DEventsRegOnPlotMouseMove_CallbackType callbackFunction,
                                                                  void *callbackData,
                                                                  int enableCallbacks,
                                                                  int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     9, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotMouseUp (CAObjHandle serverObject,
                                                                _DCWGraph3DEventsRegOnPlotMouseUp_CallbackType callbackFunction,
                                                                void *callbackData,
                                                                int enableCallbacks,
                                                                int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     10, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotAreaMouseDown (CAObjHandle serverObject,
                                                                      _DCWGraph3DEventsRegOnPlotAreaMouseDown_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     11, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotAreaMouseMove (CAObjHandle serverObject,
                                                                      _DCWGraph3DEventsRegOnPlotAreaMouseMove_CallbackType callbackFunction,
                                                                      void *callbackData,
                                                                      int enableCallbacks,
                                                                      int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     12, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPlotAreaMouseUp (CAObjHandle serverObject,
                                                                    _DCWGraph3DEventsRegOnPlotAreaMouseUp_CallbackType callbackFunction,
                                                                    void *callbackData,
                                                                    int enableCallbacks,
                                                                    int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     13, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnZoom (CAObjHandle serverObject,
                                                         _DCWGraph3DEventsRegOnZoom_CallbackType callbackFunction,
                                                         void *callbackData,
                                                         int enableCallbacks,
                                                         int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     14, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnPan (CAObjHandle serverObject,
                                                        _DCWGraph3DEventsRegOnPan_CallbackType callbackFunction,
                                                        void *callbackData,
                                                        int enableCallbacks,
                                                        int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     15, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnRotate (CAObjHandle serverObject,
                                                           _DCWGraph3DEventsRegOnRotate_CallbackType callbackFunction,
                                                           void *callbackData,
                                                           int enableCallbacks,
                                                           int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     16, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnCursorChange (CAObjHandle serverObject,
                                                                 _DCWGraph3DEventsRegOnCursorChange_CallbackType callbackFunction,
                                                                 void *callbackData,
                                                                 int enableCallbacks,
                                                                 int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     17, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}

HRESULT CVIFUNC CW3DGraphLib__DCWGraph3DEventsRegOnReadyStateChange (CAObjHandle serverObject,
                                                                     _DCWGraph3DEventsRegOnReadyStateChange_CallbackType callbackFunction,
                                                                     void *callbackData,
                                                                     int enableCallbacks,
                                                                     int *callbackId)
{
	HRESULT __result = S_OK;

	__result = CA_RegisterEventCallback (serverObject,
	                                     &__DCWGraph3DEvents_CAEventClassDefn,
	                                     18, callbackFunction, callbackData,
	                                     enableCallbacks, callbackId);

	return __result;
}
