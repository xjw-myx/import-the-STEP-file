#pragma once
#include <BRepTools.hxx>  
#include <Standard_DefineHandle.hxx>  
#include <DsgPrs_LengthPresentation.hxx>  
#include <GCPnts_TangentialDeflection.hxx>  
#include <Geom_Axis2Placement.hxx>  
#include <Geom_CartesianPoint.hxx>  
#include <Geom_Line.hxx>  
#include <Geom_Surface.hxx>  
#include <BRepAdaptor_Surface.hxx>  
#include <GeomAbs_CurveType.hxx>  
#include <GeomAdaptor_Curve.hxx>  
#include <GeomTools_Curve2dSet.hxx>  
#include <gp_Vec.hxx>  
#include <Graphic3d_NameOfMaterial.hxx>  
//#include <MMgt_TShared.hxx>  
#include <OSD_Environment.hxx>  
#include <Precision.hxx>  
#include <Prs3d_IsoAspect.hxx>  
#include <Prs3d_LineAspect.hxx>  
//#include <Prs3d_Projector.hxx>  
#include <Prs3d_Text.hxx>  
//#include <Quantity_Factor.hxx>  
//#include <Quantity_Length.hxx>  
#include <Quantity_NameOfColor.hxx>   
//#include <Quantity_PlaneAngle.hxx>  
#include <Quantity_TypeOfColor.hxx>  
#include <SelectMgr_EntityOwner.hxx>  
#include <SelectMgr_SelectableObject.hxx>  
#include <SelectMgr_Selection.hxx>  
#include <SelectMgr_SelectionManager.hxx>  
#include <SelectMgr_ListOfFilter.hxx>  
#include <SelectMgr_Filter.hxx>  
#include <StdSelect_EdgeFilter.hxx>  
#include <StdSelect_ShapeTypeFilter.hxx>  
#include <Standard_Boolean.hxx>  
#include <Standard_CString.hxx>  
#include <Standard_ErrorHandler.hxx>  
#include <Standard_Integer.hxx>  
#include <Standard_IStream.hxx>  
#include <Standard_Macro.hxx>  
#include <Standard_NotImplemented.hxx>  
#include <Standard_OStream.hxx>  
#include <Standard_Real.hxx>  
#include <StdPrs_Curve.hxx>  
#include <StdPrs_Point.hxx>  
#include <StdPrs_PoleCurve.hxx>  
#include <TCollection_AsciiString.hxx>  
#include <TColgp_Array1OfPnt2d.hxx>  
#include <TColgp_HArray1OfPnt2d.hxx>  
#include <TCollection_AsciiString.hxx>  
#include <TColStd_HSequenceOfTransient.hxx>  
#include <TColStd_MapIteratorOfMapOfTransient.hxx>  
#include <TColStd_MapOfTransient.hxx>  
#include <TopExp_Explorer.hxx>  
#include <TopoDS.hxx>  
#include <TopoDS_Compound.hxx>  
#include <TopoDS_Shape.hxx>  
#include <TopoDS_Solid.hxx>  
#include <TopoDS_Vertex.hxx>  
#include <TopExp.hxx>  
#include <TopTools_HSequenceOfShape.hxx>  
#include <UnitsAPI.hxx>  
#include <V3d_View.hxx>  
#include <V3d_Viewer.hxx>  
#include <WNT_Window.hxx>  
#include <Prs3d_PointAspect.hxx>  
#include <AIS_Point.hxx>  
#include <AIS_InteractiveContext.hxx>
#include <AIS_Shape.hxx>
#include <BRep_Tool.hxx>  
#include <BRepAlgoAPI_Fuse.hxx>  
#include <BRepBuilderAPI_MakeEdge.hxx>  
#include <BRepBuilderAPI_MakeFace.hxx>  
#include <BRepBuilderAPI_MakeWire.hxx>  
#include <BRepBuilderAPI_MakeVertex.hxx>  
#include <BRepBuilderAPI_Transform.hxx>  
#include <BRepPrimAPI_MakeCone.hxx>  
#include <BRepPrimAPI_MakeRevol.hxx>  
#include <BRepFilletAPI_MakeFillet.hxx>  
#include <BRepBuilderAPI_Copy.hxx>  
#include <BRepBuilderAPI_MakePolygon.hxx>  
#include <BRepLib.hxx>  
#include <BRepOffsetAPI_MakeThickSolid.hxx>  
#include <BRepOffsetAPI_ThruSections.hxx>  
#include <BRepPrimAPI_MakeCylinder.hxx>  
#include <BRepPrimAPI_MakePrism.hxx>  
#include <BRepPrimAPI_MakeTorus.hxx>  
#include <BRepAlgoAPI_Section.hxx>  
#include <BRepPrimAPI_MakeSphere.hxx>  
#include <BRepFeat_SplitShape.hxx>  
#include <TColgp_HArray1OfPnt.hxx>  
#include <GeomAPI_Interpolate.hxx>  
#include <GC_MakeArcOfCircle.hxx>  
#include <GC_MakeSegment.hxx>  
#include <GC_MakeCircle.hxx>  
#include <GCE2d_MakeSegment.hxx>  
#include <gp.hxx>  
#include <gp_Ax1.hxx>  
#include <gp_Ax2.hxx>  
#include <gp_Ax2d.hxx>  
#include <gp_Dir.hxx>  
#include <gp_Dir2d.hxx>  
#include <gp_Pnt.hxx>  
#include <gp_Pnt2d.hxx>  
#include <gp_Trsf.hxx>  
#include <gp_Vec.hxx>  
#include <Geom_CylindricalSurface.hxx>  
#include <Geom_Plane.hxx>  
#include <Geom_Surface.hxx>  
#include <Geom_TrimmedCurve.hxx>  
#include <Geom2d_Ellipse.hxx>  
#include <Geom2d_TrimmedCurve.hxx>  
#include <TopExp_Explorer.hxx>  
#include <TopoDS.hxx>  
#include <TopoDS_Edge.hxx>  
#include <TopoDS_Face.hxx>  
#include <TopoDS_Wire.hxx>  
#include <TopoDS_Shape.hxx>  
#include <TopoDS_Compound.hxx>  
#include <GCPnts_AbscissaPoint.hxx>  
#include <BRepAdaptor_Curve.hxx>  
#include <GeomLib.hxx>  
#include <GeomConvert_CompCurveToBSplineCurve.hxx>  
#include <TopTools_ListOfShape.hxx>  
#include <TopTools_ListIteratorOfListOfShape.hxx>  
#include <TopTools_DataMapOfShapeInteger.hxx>  
#include <TopTools_DataMapOfShapeReal.hxx>  
#include <TopTools_IndexedDataMapOfShapeAddress.hxx>  
#include <V3d_PositionalLight.hxx>  
#include <V3d_DirectionalLight.hxx>  
#include <V3d_AmbientLight.hxx>  
#include <IGESControl_Controller.hxx>  
#include <IGESControl_Writer.hxx>  
#include <Interface_Static.hxx>  
#include <OpenGl_GraphicDriver.hxx>  
#include <Graphic3d_GraphicDriver.hxx>
#include <Graphic3d_AspectFillArea3d.hxx>



//#include"BRep_Builder.hxx"
//#include"BRep_Curve3D.hxx"
//#include"BRep_CurveOn2Surfaces.hxx"
//#include"BRep_CurveOnClosedSurface.hxx"
//#include"BRep_CurveOnSurface.hxx"
//#include"BRep_CurveRepresentation.hxx"
//#include"BRep_GCurve.hxx"
//#include"BRep_ListIteratorOfListOfCurveRepresentation.hxx"
//#include"BRep_ListIteratorOfListOfPointRepresentation.hxx"
//#include"BRep_ListOfCurveRepresentation.hxx"
//#include"BRep_ListOfPointRepresentation.hxx"
//#include"BRep_PointOnCurve.hxx"
//#include"BRep_PointOnCurveOnSurface.hxx"
//#include"BRep_PointOnSurface.hxx"
//#include"BRep_PointRepresentation.hxx"
//#include"BRep_PointsOnSurface.hxx"
//#include"BRep_Polygon3D.hxx"
//#include"BRep_PolygonOnClosedSurface.hxx"
//#include"BRep_PolygonOnClosedTriangulation.hxx"
//#include"BRep_PolygonOnSurface.hxx"
//#include"BRep_PolygonOnTriangulation.hxx"
//#include"BRep_TEdge.hxx"
//#include"BRep_TFace.hxx"
//#include"BRep_Tool.hxx"
//#include"BRep_TVertex.hxx"
//#include"BRepAdaptor_Array1OfCurve.hxx"
//#include"BRepAdaptor_CompCurve.hxx"
//#include"BRepAdaptor_Curve.hxx"
//#include"BRepAdaptor_Curve2d.hxx"
//#include"BRepAdaptor_HArray1OfCurve.hxx"
//#include"BRepAdaptor_HCompCurve.hxx"
//#include"BRepAdaptor_HCurve.hxx"
//#include"BRepAdaptor_HCurve2d.hxx"
//#include"BRepAdaptor_HSurface.hxx"
//#include"BRepAdaptor_Surface.hxx"
//#include"BRepAlgo.hxx"
//#include"BRepAlgo_AsDes.hxx"
//#include"BRepAlgo_BooleanOperation.hxx"
//#include"BRepAlgo_CheckStatus.hxx"
//#include"BRepAlgo_Common.hxx"
//#include"BRepAlgo_Cut.hxx"
//#include"BRepAlgo_FaceRestrictor.hxx"
//#include"BRepAlgo_Fuse.hxx"
//#include"BRepAlgo_Image.hxx"
//#include"BRepAlgo_Loop.hxx"
//#include"BRepAlgo_NormalProjection.hxx"
//#include"BRepAlgo_Section.hxx"
//#include"BRepAlgo_Tool.hxx"
//#include"BRepAlgoAPI_Algo.hxx"
//#include"BRepAlgoAPI_BooleanOperation.hxx"
//#include"BRepAlgoAPI_BuilderAlgo.hxx"
//#include"BRepAlgoAPI_Check.hxx"
//#include"BRepAlgoAPI_Common.hxx"
//#include"BRepAlgoAPI_Cut.hxx"
//#include"BRepAlgoAPI_Defeaturing.hxx"
//#include"BRepAlgoAPI_Fuse.hxx"
//#include"BRepAlgoAPI_Section.hxx"
//#include"BRepAlgoAPI_Splitter.hxx"
//#include"BRepApprox_Approx.hxx"
//#include"BRepApprox_ApproxLine.hxx"
//#include"BRepApprox_BSpGradient_BFGSOfMyBSplGradientOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_BSpParFunctionOfMyBSplGradientOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_BSpParLeastSquareOfMyBSplGradientOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_Gradient_BFGSOfMyGradientbisOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_Gradient_BFGSOfMyGradientOfTheComputeLineBezierOfApprox.hxx"
//#include"BRepApprox_MyBSplGradientOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_MyGradientbisOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_MyGradientOfTheComputeLineBezierOfApprox.hxx"
//#include"BRepApprox_ParFunctionOfMyGradientbisOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_ParFunctionOfMyGradientOfTheComputeLineBezierOfApprox.hxx"
//#include"BRepApprox_ParLeastSquareOfMyGradientbisOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_ParLeastSquareOfMyGradientOfTheComputeLineBezierOfApprox.hxx"
//#include"BRepApprox_ResConstraintOfMyGradientbisOfTheComputeLineOfApprox.hxx"
//#include"BRepApprox_ResConstraintOfMyGradientOfTheComputeLineBezierOfApprox.hxx"
//#include"BRepApprox_SurfaceTool.hxx"
//#include"BRepApprox_TheComputeLineBezierOfApprox.hxx"
//#include"BRepApprox_TheComputeLineOfApprox.hxx"
//#include"BRepApprox_TheFunctionOfTheInt2SOfThePrmPrmSvSurfacesOfApprox.hxx"
//#include"BRepApprox_TheImpPrmSvSurfacesOfApprox.hxx"
//#include"BRepApprox_TheInt2SOfThePrmPrmSvSurfacesOfApprox.hxx"
//#include"BRepApprox_TheMultiLineOfApprox.hxx"
//#include"BRepApprox_TheMultiLineToolOfApprox.hxx"
//#include"BRepApprox_ThePrmPrmSvSurfacesOfApprox.hxx"
//#include"BRepApprox_TheZerImpFuncOfTheImpPrmSvSurfacesOfApprox.hxx"
//#include"BRepBlend_AppFunc.hxx"
//#include"BRepBlend_AppFuncRoot.hxx"
//#include"BRepBlend_AppFuncRst.hxx"
//#include"BRepBlend_AppFuncRstRst.hxx"
//#include"BRepBlend_AppSurf.hxx"
//#include"BRepBlend_AppSurface.hxx"
//#include"BRepBlend_BlendTool.hxx"
//#include"BRepBlend_Chamfer.hxx"
//#include"BRepBlend_ChamfInv.hxx"
//#include"BRepBlend_ChAsym.hxx"
//#include"BRepBlend_ChAsymInv.hxx"
//#include"BRepBlend_ConstRad.hxx"
//#include"BRepBlend_ConstRadInv.hxx"
//#include"BRepBlend_ConstThroat.hxx"
//#include"BRepBlend_ConstThroatInv.hxx"
//#include"BRepBlend_ConstThroatWithPenetration.hxx"
//#include"BRepBlend_ConstThroatWithPenetrationInv.hxx"
//#include"BRepBlend_CSCircular.hxx"
//#include"BRepBlend_CSConstRad.hxx"
//#include"BRepBlend_CSWalking.hxx"
//#include"BRepBlend_CurvPointRadInv.hxx"
//#include"BRepBlend_EvolRad.hxx"
//#include"BRepBlend_EvolRadInv.hxx"
//#include"BRepBlend_Extremity.hxx"
//#include"BRepBlend_HCurve2dTool.hxx"
//#include"BRepBlend_HCurveTool.hxx"
//#include"BRepBlend_Line.hxx"
//#include"BRepBlend_PointOnRst.hxx"
//#include"BRepBlend_RstRstConstRad.hxx"
//#include"BRepBlend_RstRstEvolRad.hxx"
//#include"BRepBlend_RstRstLineBuilder.hxx"
//#include"BRepBlend_Ruled.hxx"
//#include"BRepBlend_RuledInv.hxx"
//#include"BRepBlend_SequenceOfLine.hxx"
//#include"BRepBlend_SequenceOfPointOnRst.hxx"
//#include"BRepBlend_SurfCurvConstRadInv.hxx"
//#include"BRepBlend_SurfCurvEvolRadInv.hxx"
//#include"BRepBlend_SurfPointConstRadInv.hxx"
//#include"BRepBlend_SurfPointEvolRadInv.hxx"
//#include"BRepBlend_SurfRstConstRad.hxx"
//#include"BRepBlend_SurfRstEvolRad.hxx"
//#include"BRepBlend_SurfRstLineBuilder.hxx"
//#include"BRepBlend_Walking.hxx"
//#include"BRepBndLib.hxx"
//#include"BRepBuilderAPI.hxx"
//#include"BRepBuilderAPI_BndBoxTreeSelector.hxx"
//#include"BRepBuilderAPI_CellFilter.hxx"
//#include"BRepBuilderAPI_Collect.hxx"
//#include"BRepBuilderAPI_Command.hxx"
//#include"BRepBuilderAPI_Copy.hxx"
//#include"BRepBuilderAPI_EdgeError.hxx"
//#include"BRepBuilderAPI_FaceError.hxx"
//#include"BRepBuilderAPI_FastSewing.hxx"
//#include"BRepBuilderAPI_FindPlane.hxx"
//#include"BRepBuilderAPI_GTransform.hxx"
//#include"BRepBuilderAPI_MakeEdge.hxx"
//#include"BRepBuilderAPI_MakeEdge2d.hxx"
//#include"BRepBuilderAPI_MakeFace.hxx"
//#include"BRepBuilderAPI_MakePolygon.hxx"
//#include"BRepBuilderAPI_MakeShape.hxx"
//#include"BRepBuilderAPI_MakeShell.hxx"
//#include"BRepBuilderAPI_MakeSolid.hxx"
//#include"BRepBuilderAPI_MakeVertex.hxx"
//#include"BRepBuilderAPI_MakeWire.hxx"
//#include"BRepBuilderAPI_ModifyShape.hxx"
//#include"BRepBuilderAPI_NurbsConvert.hxx"
//#include"BRepBuilderAPI_PipeError.hxx"
//#include"BRepBuilderAPI_Sewing.hxx"
//#include"BRepBuilderAPI_ShapeModification.hxx"
//#include"BRepBuilderAPI_ShellError.hxx"
//#include"BRepBuilderAPI_Transform.hxx"
//#include"BRepBuilderAPI_TransitionMode.hxx"
//#include"BRepBuilderAPI_VertexInspector.hxx"
//#include"BRepBuilderAPI_WireError.hxx"
//#include"BRepCheck.hxx"
//#include"BRepCheck_Analyzer.hxx"
//#include"BRepCheck_DataMapIteratorOfDataMapOfShapeListOfStatus.hxx"
//#include"BRepCheck_DataMapIteratorOfDataMapOfShapeResult.hxx"
//#include"BRepCheck_DataMapOfShapeListOfStatus.hxx"
//#include"BRepCheck_DataMapOfShapeResult.hxx"
//#include"BRepCheck_Edge.hxx"
//#include"BRepCheck_Face.hxx"
//#include"BRepCheck_ListIteratorOfListOfStatus.hxx"
//#include"BRepCheck_ListOfStatus.hxx"
//#include"BRepCheck_Result.hxx"
//#include"BRepCheck_Shell.hxx"
//#include"BRepCheck_Solid.hxx"
//#include"BRepCheck_Status.hxx"
//#include"BRepCheck_Vertex.hxx"
//#include"BRepCheck_Wire.hxx"
//#include"BRepClass_Edge.hxx"
//#include"BRepClass_FaceClassifier.hxx"
//#include"BRepClass_FaceExplorer.hxx"
//#include"BRepClass_FacePassiveClassifier.hxx"
//#include"BRepClass_FClass2dOfFClassifier.hxx"
//#include"BRepClass_FClassifier.hxx"
//#include"BRepClass_Intersector.hxx"
//#include"BRepClass3d.hxx"
//#include"BRepClass3d_BndBoxTree.hxx"
//#include"BRepClass3d_DataMapIteratorOfMapOfInter.hxx"
//#include"BRepClass3d_Intersector3d.hxx"
//#include"BRepClass3d_MapOfInter.hxx"
//#include"BRepClass3d_SClassifier.hxx"
//#include"BRepClass3d_SolidClassifier.hxx"
//#include"BRepClass3d_SolidExplorer.hxx"
//#include"BRepClass3d_SolidPassiveClassifier.hxx"
//#include"BRepExtrema_DistanceSS.hxx"
//#include"BRepExtrema_DistShapeShape.hxx"
//#include"BRepExtrema_ElementFilter.hxx"
//#include"BRepExtrema_ExtCC.hxx"
//#include"BRepExtrema_ExtCF.hxx"
//#include"BRepExtrema_ExtFF.hxx"
//#include"BRepExtrema_ExtPC.hxx"
//#include"BRepExtrema_ExtPF.hxx"
//#include"BRepExtrema_MapOfIntegerPackedMapOfInteger.hxx"
//#include"BRepExtrema_OverlapTool.hxx"
//#include"BRepExtrema_Poly.hxx"
//#include"BRepExtrema_SelfIntersection.hxx"
//#include"BRepExtrema_SeqOfSolution.hxx"
//#include"BRepExtrema_ShapeProximity.hxx"
//#include"BRepExtrema_SolutionElem.hxx"
//#include"BRepExtrema_SupportType.hxx"
//#include"BRepExtrema_TriangleSet.hxx"
//#include"BRepExtrema_UnCompatibleShape.hxx"
//#include"BRepFeat.hxx"
//#include"BRepFeat_Builder.hxx"
//#include"BRepFeat_Form.hxx"
//#include"BRepFeat_Gluer.hxx"
//#include"BRepFeat_MakeCylindricalHole.hxx"
//#include"BRepFeat_MakeDPrism.hxx"
//#include"BRepFeat_MakeLinearForm.hxx"
//#include"BRepFeat_MakePipe.hxx"
//#include"BRepFeat_MakePrism.hxx"
//#include"BRepFeat_MakeRevol.hxx"
//#include"BRepFeat_MakeRevolutionForm.hxx"
//#include"BRepFeat_PerfSelection.hxx"
//#include"BRepFeat_RibSlot.hxx"
//#include"BRepFeat_SplitShape.hxx"
//#include"BRepFeat_Status.hxx"
//#include"BRepFeat_StatusError.hxx"
//#include"BRepFill.hxx"
//#include"BRepFill_ACRLaw.hxx"
//#include"BRepFill_AdvancedEvolved.hxx"
//#include"BRepFill_ApproxSeewing.hxx"
//#include"BRepFill_CompatibleWires.hxx"
//#include"BRepFill_ComputeCLine.hxx"
//#include"BRepFill_CurveConstraint.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfNodeDataMapOfShapeShape.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfNodeShape.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfOrientedShapeListOfShape.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfShapeDataMapOfShapeListOfShape.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfShapeHArray2OfShape.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfShapeSequenceOfPnt.hxx"
//#include"BRepFill_DataMapIteratorOfDataMapOfShapeSequenceOfReal.hxx"
//#include"BRepFill_DataMapOfNodeDataMapOfShapeShape.hxx"
//#include"BRepFill_DataMapOfNodeShape.hxx"
//#include"BRepFill_DataMapOfOrientedShapeListOfShape.hxx"
//#include"BRepFill_DataMapOfShapeDataMapOfShapeListOfShape.hxx"
//#include"BRepFill_DataMapOfShapeHArray2OfShape.hxx"
//#include"BRepFill_DataMapOfShapeSequenceOfPnt.hxx"
//#include"BRepFill_DataMapOfShapeSequenceOfReal.hxx"
//#include"BRepFill_Draft.hxx"
//#include"BRepFill_DraftLaw.hxx"
//#include"BRepFill_Edge3DLaw.hxx"
//#include"BRepFill_EdgeFaceAndOrder.hxx"
//#include"BRepFill_EdgeOnSurfLaw.hxx"
//#include"BRepFill_Evolved.hxx"
//#include"BRepFill_FaceAndOrder.hxx"
//#include"BRepFill_Filling.hxx"
//#include"BRepFill_Generator.hxx"
//#include"BRepFill_IndexedDataMapOfOrientedShapeListOfShape.hxx"
//#include"BRepFill_ListIteratorOfListOfOffsetWire.hxx"
//#include"BRepFill_ListOfOffsetWire.hxx"
//#include"BRepFill_LocationLaw.hxx"
//#include"BRepFill_MultiLine.hxx"
//#include"BRepFill_NSections.hxx"
//#include"BRepFill_OffsetAncestors.hxx"
//#include"BRepFill_OffsetWire.hxx"
//#include"BRepFill_Pipe.hxx"
//#include"BRepFill_PipeShell.hxx"
//#include"BRepFill_Section.hxx"
//#include"BRepFill_SectionLaw.hxx"
//#include"BRepFill_SectionPlacement.hxx"
//#include"BRepFill_SequenceOfEdgeFaceAndOrder.hxx"
//#include"BRepFill_SequenceOfFaceAndOrder.hxx"
//#include"BRepFill_SequenceOfSection.hxx"
//#include"BRepFill_ShapeLaw.hxx"
//#include"BRepFill_Sweep.hxx"
//#include"BRepFill_TransitionStyle.hxx"
//#include"BRepFill_TrimEdgeTool.hxx"
//#include"BRepFill_TrimShellCorner.hxx"
//#include"BRepFill_TrimSurfaceTool.hxx"
//#include"BRepFill_TypeOfContact.hxx"
//#include"BRepFilletAPI_LocalOperation.hxx"
//#include"BRepFilletAPI_MakeChamfer.hxx"
//#include"BRepFilletAPI_MakeFillet.hxx"
//#include"BRepFilletAPI_MakeFillet2d.hxx"
//#include"BRepGProp.hxx"
//#include"BRepGProp_Cinert.hxx"
//#include"BRepGProp_Domain.hxx"
//#include"BRepGProp_EdgeTool.hxx"
//#include"BRepGProp_Face.hxx"
//#include"BRepGProp_Gauss.hxx"
//#include"BRepGProp_MeshCinert.hxx"
//#include"BRepGProp_MeshProps.hxx"
//#include"BRepGProp_Sinert.hxx"
//#include"BRepGProp_TFunction.hxx"
//#include"BRepGProp_UFunction.hxx"
//#include"BRepGProp_Vinert.hxx"
//#include"BRepGProp_VinertGK.hxx"
//#include"BRepIntCurveSurface_Inter.hxx"
//#include"BRepLib.hxx"
//#include"BRepLib_CheckCurveOnSurface.hxx"
//#include"BRepLib_Command.hxx"
//#include"BRepLib_EdgeError.hxx"
//#include"BRepLib_FaceError.hxx"
//#include"BRepLib_FindSurface.hxx"
//#include"BRepLib_FuseEdges.hxx"
//#include"BRepLib_MakeEdge.hxx"
//#include"BRepLib_MakeEdge2d.hxx"
//#include"BRepLib_MakeFace.hxx"
//#include"BRepLib_MakePolygon.hxx"
//#include"BRepLib_MakeShape.hxx"
//#include"BRepLib_MakeShell.hxx"
//#include"BRepLib_MakeSolid.hxx"
//#include"BRepLib_MakeVertex.hxx"
//#include"BRepLib_MakeWire.hxx"
//#include"BRepLib_ShapeModification.hxx"
//#include"BRepLib_ShellError.hxx"
//#include"BRepLib_WireError.hxx"
//#include"BRepLProp.hxx"
//#include"BRepLProp_CLProps.hxx"
//#include"BRepLProp_CurveTool.hxx"
//#include"BRepLProp_SLProps.hxx"
//#include"BRepLProp_SurfaceTool.hxx"
//#include"BRepMAT2d_BisectingLocus.hxx"
//#include"BRepMAT2d_DataMapIteratorOfDataMapOfBasicEltShape.hxx"
//#include"BRepMAT2d_DataMapIteratorOfDataMapOfShapeSequenceOfBasicElt.hxx"
//#include"BRepMAT2d_DataMapOfBasicEltShape.hxx"
//#include"BRepMAT2d_DataMapOfShapeSequenceOfBasicElt.hxx"
//#include"BRepMAT2d_Explorer.hxx"
//#include"BRepMAT2d_LinkTopoBilo.hxx"
//#include"BRepMesh_BaseMeshAlgo.hxx"
//#include"BRepMesh_BoundaryParamsRangeSplitter.hxx"
//#include"BRepMesh_Circle.hxx"
//#include"BRepMesh_CircleInspector.hxx"
//#include"BRepMesh_CircleTool.hxx"
//#include"BRepMesh_Classifier.hxx"
//#include"BRepMesh_ConeRangeSplitter.hxx"
//#include"BRepMesh_ConstrainedBaseMeshAlgo.hxx"
//#include"BRepMesh_Context.hxx"
//#include"BRepMesh_CurveTessellator.hxx"
//#include"BRepMesh_CustomBaseMeshAlgo.hxx"
//#include"BRepMesh_CustomDelaunayBaseMeshAlgo.hxx"
//#include"BRepMesh_CylinderRangeSplitter.hxx"
//#include"BRepMesh_DataStructureOfDelaun.hxx"
//#include"BRepMesh_DefaultRangeSplitter.hxx"
//#include"BRepMesh_Deflection.hxx"
//#include"BRepMesh_DegreeOfFreedom.hxx"
//#include"BRepMesh_Delaun.hxx"
//#include"BRepMesh_DelaunayBaseMeshAlgo.hxx"
//#include"BRepMesh_DelaunayDeflectionControlMeshAlgo.hxx"
//#include"BRepMesh_DelaunayNodeInsertionMeshAlgo.hxx"
//#include"BRepMesh_DiscretFactory.hxx"
//#include"BRepMesh_DiscretRoot.hxx"
//#include"BRepMesh_Edge.hxx"
//#include"BRepMesh_EdgeDiscret.hxx"
//#include"BRepMesh_EdgeParameterProvider.hxx"
//#include"BRepMesh_EdgeTessellationExtractor.hxx"
//#include"BRepMesh_FaceChecker.hxx"
//#include"BRepMesh_FaceDiscret.hxx"
//#include"BRepMesh_FactoryError.hxx"
//#include"BRepMesh_FastDiscret.hxx"
//#include"BRepMesh_GeomTool.hxx"
//#include"BRepMesh_IncrementalMesh.hxx"
//#include"BRepMesh_MeshAlgoFactory.hxx"
//#include"BRepMesh_MeshTool.hxx"
//#include"BRepMesh_ModelBuilder.hxx"
//#include"BRepMesh_ModelHealer.hxx"
//#include"BRepMesh_ModelPostProcessor.hxx"
//#include"BRepMesh_ModelPreProcessor.hxx"
//#include"BRepMesh_NodeInsertionMeshAlgo.hxx"
//#include"BRepMesh_NURBSRangeSplitter.hxx"
//#include"BRepMesh_OrientedEdge.hxx"
//#include"BRepMesh_PairOfIndex.hxx"
//#include"BRepMesh_PluginEntryType.hxx"
//#include"BRepMesh_PluginMacro.hxx"
//#include"BRepMesh_SelectorOfDataStructureOfDelaun.hxx"
//#include"BRepMesh_ShapeTool.hxx"
//#include"BRepMesh_ShapeVisitor.hxx"
//#include"BRepMesh_SphereRangeSplitter.hxx"
//#include"BRepMesh_TorusRangeSplitter.hxx"
//#include"BRepMesh_Triangle.hxx"
//#include"BRepMesh_UVParamRangeSplitter.hxx"
//#include"BRepMesh_Vertex.hxx"
//#include"BRepMesh_VertexInspector.hxx"
//#include"BRepMesh_VertexTool.hxx"
//#include"BRepMeshData_Curve.hxx"
//#include"BRepMeshData_Edge.hxx"
//#include"BRepMeshData_Face.hxx"
//#include"BRepMeshData_Model.hxx"
//#include"BRepMeshData_PCurve.hxx"
//#include"BRepMeshData_Wire.hxx"
//#include"BRepOffset.hxx"
//#include"BRepOffset_Analyse.hxx"
//#include"BRepOffset_DataMapIteratorOfDataMapOfShapeListOfInterval.hxx"
//#include"BRepOffset_DataMapIteratorOfDataMapOfShapeMapOfShape.hxx"
//#include"BRepOffset_DataMapIteratorOfDataMapOfShapeOffset.hxx"
//#include"BRepOffset_DataMapOfShapeListOfInterval.hxx"
//#include"BRepOffset_DataMapOfShapeMapOfShape.hxx"
//#include"BRepOffset_DataMapOfShapeOffset.hxx"
//#include"BRepOffset_Error.hxx"
//#include"BRepOffset_Inter2d.hxx"
//#include"BRepOffset_Inter3d.hxx"
//#include"BRepOffset_Interval.hxx"
//#include"BRepOffset_ListIteratorOfListOfInterval.hxx"
//#include"BRepOffset_ListOfInterval.hxx"
//#include"BRepOffset_MakeLoops.hxx"
//#include"BRepOffset_MakeOffset.hxx"
//#include"BRepOffset_MakeSimpleOffset.hxx"
//#include"BRepOffset_Mode.hxx"
//#include"BRepOffset_Offset.hxx"
//#include"BRepOffset_SimpleOffset.hxx"
//#include"BRepOffset_Status.hxx"
//#include"BRepOffset_Tool.hxx"
//#include"BRepOffset_Type.hxx"
//#include"BRepOffsetAPI_DraftAngle.hxx"
//#include"BRepOffsetAPI_FindContigousEdges.hxx"
//#include"BRepOffsetAPI_MakeDraft.hxx"
//#include"BRepOffsetAPI_MakeEvolved.hxx"
//#include"BRepOffsetAPI_MakeFilling.hxx"
//#include"BRepOffsetAPI_MakeOffset.hxx"
//#include"BRepOffsetAPI_MakeOffsetShape.hxx"
//#include"BRepOffsetAPI_MakePipe.hxx"
//#include"BRepOffsetAPI_MakePipeShell.hxx"
//#include"BRepOffsetAPI_MakeThickSolid.hxx"
//#include"BRepOffsetAPI_MiddlePath.hxx"
//#include"BRepOffsetAPI_NormalProjection.hxx"
//#include"BRepOffsetAPI_SequenceOfSequenceOfReal.hxx"
//#include"BRepOffsetAPI_SequenceOfSequenceOfShape.hxx"
//#include"BRepOffsetAPI_Sewing.hxx"
//#include"BRepOffsetAPI_ThruSections.hxx"
//#include"BRepPrim_Builder.hxx"
//#include"BRepPrim_Cone.hxx"
//#include"BRepPrim_Cylinder.hxx"
//#include"BRepPrim_Direction.hxx"
//#include"BRepPrim_FaceBuilder.hxx"
//#include"BRepPrim_GWedge.hxx"
//#include"BRepPrim_OneAxis.hxx"
//#include"BRepPrim_Revolution.hxx"
//#include"BRepPrim_Sphere.hxx"
//#include"BRepPrim_Torus.hxx"
//#include"BRepPrim_Wedge.hxx"
//#include"BRepPrimAPI_MakeBox.hxx"
//#include"BRepPrimAPI_MakeCone.hxx"
//#include"BRepPrimAPI_MakeCylinder.hxx"
//#include"BRepPrimAPI_MakeHalfSpace.hxx"
//#include"BRepPrimAPI_MakeOneAxis.hxx"
//#include"BRepPrimAPI_MakePrism.hxx"
//#include"BRepPrimAPI_MakeRevol.hxx"
//#include"BRepPrimAPI_MakeRevolution.hxx"
//#include"BRepPrimAPI_MakeSphere.hxx"
//#include"BRepPrimAPI_MakeSweep.hxx"
//#include"BRepPrimAPI_MakeTorus.hxx"
//#include"BRepPrimAPI_MakeWedge.hxx"
//#include"BRepProj_Projection.hxx"
//#include"BRepSweep_Builder.hxx"
//#include"BRepSweep_Iterator.hxx"
//#include"BRepSweep_NumLinearRegularSweep.hxx"
//#include"BRepSweep_Prism.hxx"
//#include"BRepSweep_Revol.hxx"
//#include"BRepSweep_Rotation.hxx"
//#include"BRepSweep_Tool.hxx"
//#include"BRepSweep_Translation.hxx"
//#include"BRepSweep_Trsf.hxx"
//#include"BRepTest.hxx"
//#include"BRepTest_DrawableHistory.hxx"
//#include"BRepTest_Objects.hxx"
//#include"BRepToIGES_BREntity.hxx"
//#include"BRepToIGES_BRShell.hxx"
//#include"BRepToIGES_BRSolid.hxx"
//#include"BRepToIGES_BRWire.hxx"
//#include"BRepToIGESBRep_Entity.hxx"
//#include"BRepTools.hxx"
//#include"BRepTools_DataMapIteratorOfMapOfVertexPnt2d.hxx"
//#include"BRepTools_GTrsfModification.hxx"
//#include"BRepTools_History.hxx"
//#include"BRepTools_MapOfVertexPnt2d.hxx"
//#include"BRepTools_Modification.hxx"
//#include"BRepTools_Modifier.hxx"
//#include"BRepTools_NurbsConvertModification.hxx"
//#include"BRepTools_Quilt.hxx"
//#include"BRepTools_ReShape.hxx"
//#include"BRepTools_ShapeSet.hxx"
//#include"BRepTools_Substitution.hxx"
//#include"BRepTools_TrsfModification.hxx"
//#include"BRepTools_WireExplorer.hxx"
//#include"BRepTopAdaptor_DataMapIteratorOfMapOfShapeTool.hxx"
//#include"BRepTopAdaptor_FClass2d.hxx"
//#include"BRepTopAdaptor_HVertex.hxx"
//#include"BRepTopAdaptor_MapOfShapeTool.hxx"
//#include"BRepTopAdaptor_SeqOfPtr.hxx"
//#include"BRepTopAdaptor_Tool.hxx"
//#include"BRepTopAdaptor_TopolTool.hxx"