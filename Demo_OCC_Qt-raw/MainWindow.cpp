#include "MainWindow.h"


#include <QToolBar>
#include <QTreeView>
#include <QMessageBox>
#include <QDockWidget>
#include<qfiledialog.h>
#include<QDebug>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>

#include <gp_Lin2d.hxx>

#include <Geom_ConicalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_CylindricalSurface.hxx>

#include <GCE2d_MakeSegment.hxx>

#include <TopoDS.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TColgp_Array1OfPnt2d.hxx>

#include <BRepLib.hxx>

#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>

#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>

#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>

#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Common.hxx>

#include <AIS_Shape.hxx>
#include <IGESControl_Reader.hxx>
#include <STEPControl_Reader.hxx>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	view = new View();
	ui.gridLayout->addWidget(view);
	createActions();
	createMenus();
	createToolBars();
}


void MainWindow::createActions(void)
{
	// File
	connect(ui.actionExit, SIGNAL(triggered()), this, SLOT(close()));
	connect(ui.actionreadIGS, SIGNAL(triggered()), this, SLOT(readIgs()));
	connect(ui.actionreadSTEP, SIGNAL(triggered()), this, SLOT(readStep()));

	// View
	connect(ui.actionZoom, SIGNAL(triggered()), view, SLOT(zoom()));
	connect(ui.actionPan, SIGNAL(triggered()), view, SLOT(pan()));
	connect(ui.actionRotate, SIGNAL(triggered()), view, SLOT(rotate()));

	connect(ui.actionReset, SIGNAL(triggered()), view, SLOT(reset()));
	connect(ui.actionFitAll, SIGNAL(triggered()), view, SLOT(fitAll()));
	connect(ui.actionMesh, SIGNAL(triggered()), view, SLOT(mesh()));

	// Primitive
	connect(ui.actionBox, SIGNAL(triggered()), this, SLOT(makeBox()));
	connect(ui.actionCone, SIGNAL(triggered()), this, SLOT(makeCone()));
	connect(ui.actionSphere, SIGNAL(triggered()), this, SLOT(makeSphere()));
	connect(ui.actionCylinder, SIGNAL(triggered()), this, SLOT(makeCylinder()));
	connect(ui.actionTorus, SIGNAL(triggered()), this, SLOT(makeTorus()));

	// Modeling
	connect(ui.actionFillet, SIGNAL(triggered()), this, SLOT(makeFillet()));
	connect(ui.actionChamfer, SIGNAL(triggered()), this, SLOT(makeChamfer()));
	connect(ui.actionExtrude, SIGNAL(triggered()), this, SLOT(makeExtrude()));
	connect(ui.actionRevolve, SIGNAL(triggered()), this, SLOT(makeRevol()));
	connect(ui.actionLoft, SIGNAL(triggered()), this, SLOT(makeLoft()));

	connect(ui.actionCut, SIGNAL(triggered()), this, SLOT(testCut()));
	connect(ui.actionFuse, SIGNAL(triggered()), this, SLOT(testFuse()));
	connect(ui.actionCommon, SIGNAL(triggered()), this, SLOT(testCommon()));

	connect(ui.actionHelix, SIGNAL(triggered()), this, SLOT(testHelix()));

	// Help
	connect(ui.actionAbout, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::createMenus(void)
{
}

void MainWindow::createToolBars(void)
{
	QToolBar* aToolBar = this->addToolBar(tr("&Navigate"));
	aToolBar->addAction(ui.actionreadIGS);
	aToolBar->addAction(ui.actionreadSTEP);

	aToolBar = addToolBar(tr("&Navigate"));
	aToolBar->addAction(ui.actionZoom);
	aToolBar->addAction(ui.actionPan);
	aToolBar->addAction(ui.actionRotate);
	aToolBar->addAction(ui.actionRotate);

	aToolBar = addToolBar(tr("&View"));
	aToolBar->addAction(ui.actionReset);
	aToolBar->addAction(ui.actionFitAll);

	aToolBar = addToolBar(tr("&Primitive"));
	aToolBar->addAction(ui.actionBox);
	aToolBar->addAction(ui.actionCone);
	aToolBar->addAction(ui.actionSphere);
	aToolBar->addAction(ui.actionCylinder);
	aToolBar->addAction(ui.actionTorus);

	aToolBar = addToolBar(tr("&Modeling"));
	aToolBar->addAction(ui.actionFillet);
	aToolBar->addAction(ui.actionChamfer);
	aToolBar->addAction(ui.actionExtrude);
	aToolBar->addAction(ui.actionRevolve);
	aToolBar->addAction(ui.actionLoft);
	aToolBar->addSeparator();
	aToolBar->addAction(ui.actionCut);
	aToolBar->addAction(ui.actionFuse);
	aToolBar->addAction(ui.actionCommon);
	aToolBar->addSeparator();
	aToolBar->addAction(ui.actionHelix);

	aToolBar = addToolBar(tr("Help"));
	aToolBar->addAction(ui.actionAbout);
}

void MainWindow::about()
{
	QMessageBox::about(this, tr("About OCCQT"),
		tr("<h2>OCCQT</h2>"
			"<p>sysu-xjw refer to GuoMao-1402490495@qq.com"
			"<p>sysu-xjw: 1575060769@qq.com"
			"<p>OCCQT is a demo applicaton about Qt and OpenCASCADE."));
}
//¶ÁÈ¡igs
void MainWindow::readIgs()
{
	IGESControl_Reader myIgesReader;
	Standard_Integer nIgesFaces, nTransFaces;
	QString fileName = QFileDialog::getOpenFileName();
	myIgesReader.ReadFile(Standard_CString(fileName.toStdString().c_str()));


	Handle(TColStd_HSequenceOfTransient) myList = myIgesReader.GiveList("iges-faces");
	//selects all IGES faces in the file and puts them into a list called //MyList,
	nIgesFaces = myList->Length();
	nTransFaces = myIgesReader.TransferList(myList);
	//translates MyList,
	qDebug() << "IGES Faces: " << nIgesFaces << " Transferred:" << nTransFaces;
	TopoDS_Shape aShape = myIgesReader.OneShape();

	Handle(AIS_Shape) anAisModel = new AIS_Shape(aShape);
	anAisModel->SetColor(Quantity_NOC_BLUE1);
	anAisModel->SetTransparency(1);
	view->getContext()->Display(anAisModel, Standard_True);
}
//¶ÁÈ¡step
void MainWindow::readStep()
{
	STEPControl_Reader reader;
	QString fileName = QFileDialog::getOpenFileName();
	reader.ReadFile(Standard_CString(fileName.toStdString().c_str()));
	// Loads file MyFile.stp
	Standard_Integer NbRoots = reader.NbRootsForTransfer();
	// gets the number of transferable roots
	Standard_Integer NbTrans = reader.TransferRoots();
	// translates all transferable roots, and returns the number of //successful translations
	TopoDS_Shape aShape = reader.OneShape();


	Handle(AIS_Shape) anAisModel = new AIS_Shape(aShape);
	anAisModel->SetColor(Quantity_NOC_BLUE);
	anAisModel->SetTransparency(0.9);
	view->getContext()->Display(anAisModel, Standard_True);
}
void MainWindow::makeBox()
{
	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(3.0, 4.0, 5.0).Shape();
	Handle(AIS_Shape) anAisBox = new AIS_Shape(aTopoBox);

	anAisBox->SetColor(Quantity_NOC_AZURE);

	view->getContext()->Display(anAisBox, Standard_True);
}

void MainWindow::makeCone()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 10.0, 0.0));

	TopoDS_Shape aTopoReducer = BRepPrimAPI_MakeCone(anAxis, 3.0, 1.5, 5.0).Shape();
	Handle(AIS_Shape) anAisReducer = new AIS_Shape(aTopoReducer);

	anAisReducer->SetColor(Quantity_NOC_BISQUE);

	anAxis.SetLocation(gp_Pnt(8.0, 10.0, 0.0));
	TopoDS_Shape aTopoCone = BRepPrimAPI_MakeCone(anAxis, 3.0, 0.0, 5.0).Shape();
	Handle(AIS_Shape) anAisCone = new AIS_Shape(aTopoCone);

	anAisCone->SetColor(Quantity_NOC_CHOCOLATE);

	view->getContext()->Display(anAisReducer, Standard_True);
	view->getContext()->Display(anAisCone, Standard_True);
}

void MainWindow::makeSphere()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 20.0, 0.0));

	TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 3.0).Shape();
	Handle(AIS_Shape) anAisSphere = new AIS_Shape(aTopoSphere);

	anAisSphere->SetColor(Quantity_NOC_BLUE1);

	view->getContext()->Display(anAisSphere, Standard_True);
}

void MainWindow::makeCylinder()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 30.0, 0.0));

	TopoDS_Shape aTopoCylinder = BRepPrimAPI_MakeCylinder(anAxis, 3.0, 5.0).Shape();
	Handle(AIS_Shape) anAisCylinder = new AIS_Shape(aTopoCylinder);

	anAisCylinder->SetColor(Quantity_NOC_RED);

	anAxis.SetLocation(gp_Pnt(8.0, 30.0, 0.0));
	TopoDS_Shape aTopoPie = BRepPrimAPI_MakeCylinder(anAxis, 3.0, 5.0, M_PI_2 * 3.0).Shape();
	Handle(AIS_Shape) anAisPie = new AIS_Shape(aTopoPie);

	anAisPie->SetColor(Quantity_NOC_TAN);

	view->getContext()->Display(anAisCylinder, Standard_True);
	view->getContext()->Display(anAisPie, Standard_True);
}

void MainWindow::makeTorus()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 40.0, 0.0));

	TopoDS_Shape aTopoTorus = BRepPrimAPI_MakeTorus(anAxis, 3.0, 1.0).Shape();
	Handle(AIS_Shape) anAisTorus = new AIS_Shape(aTopoTorus);

	anAisTorus->SetColor(Quantity_NOC_YELLOW);

	anAxis.SetLocation(gp_Pnt(8.0, 40.0, 0.0));
	TopoDS_Shape aTopoElbow = BRepPrimAPI_MakeTorus(anAxis, 3.0, 1.0, M_PI_2).Shape();
	Handle(AIS_Shape) anAisElbow = new AIS_Shape(aTopoElbow);

	anAisElbow->SetColor(Quantity_NOC_THISTLE);

	view->getContext()->Display(anAisTorus, Standard_True);
	view->getContext()->Display(anAisElbow, Standard_True);
}

void MainWindow::makeFillet()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 50.0, 0.0));

	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(anAxis, 3.0, 4.0, 5.0).Shape();
	BRepFilletAPI_MakeFillet MF(aTopoBox);

	// Add all the edges to fillet.
	for (TopExp_Explorer ex(aTopoBox, TopAbs_EDGE); ex.More(); ex.Next())
	{
		MF.Add(1.0, TopoDS::Edge(ex.Current()));
	}

	Handle(AIS_Shape) anAisShape = new AIS_Shape(MF.Shape());
	anAisShape->SetColor(Quantity_NOC_VIOLET);

	view->getContext()->Display(anAisShape, Standard_True);
}

void MainWindow::makeChamfer()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(8.0, 50.0, 0.0));

	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(anAxis, 3.0, 4.0, 5.0).Shape();
	BRepFilletAPI_MakeChamfer MC(aTopoBox);
	TopTools_IndexedDataMapOfShapeListOfShape aEdgeFaceMap;

	TopExp::MapShapesAndAncestors(aTopoBox, TopAbs_EDGE, TopAbs_FACE, aEdgeFaceMap);

	for (Standard_Integer i = 1; i <= aEdgeFaceMap.Extent(); ++i)
	{
		TopoDS_Edge anEdge = TopoDS::Edge(aEdgeFaceMap.FindKey(i));
		TopoDS_Face aFace = TopoDS::Face(aEdgeFaceMap.FindFromIndex(i).First());

		MC.Add(0.6, 0.6, anEdge, aFace);
	}

	Handle(AIS_Shape) anAisShape = new AIS_Shape(MC.Shape());
	anAisShape->SetColor(Quantity_NOC_TOMATO);

	view->getContext()->Display(anAisShape, Standard_True);
}

void MainWindow::makeExtrude()
{
	// prism a vertex result is an edge.
	TopoDS_Vertex aVertex = BRepBuilderAPI_MakeVertex(gp_Pnt(0.0, 60.0, 0.0));
	TopoDS_Shape aPrismVertex = BRepPrimAPI_MakePrism(aVertex, gp_Vec(0.0, 0.0, 5.0));
	Handle(AIS_Shape) anAisPrismVertex = new AIS_Shape(aPrismVertex);

	// prism an edge result is a face.
	TopoDS_Edge anEdge = BRepBuilderAPI_MakeEdge(gp_Pnt(5.0, 60.0, 0.0), gp_Pnt(10.0, 60.0, 0.0));
	TopoDS_Shape aPrismEdge = BRepPrimAPI_MakePrism(anEdge, gp_Vec(0.0, 0.0, 5.0));
	Handle(AIS_Shape) anAisPrismEdge = new AIS_Shape(aPrismEdge);

	// prism a wire result is a shell.
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(16.0, 60.0, 0.0));

	TopoDS_Edge aCircleEdge = BRepBuilderAPI_MakeEdge(gp_Circ(anAxis, 3.0));
	TopoDS_Wire aCircleWire = BRepBuilderAPI_MakeWire(aCircleEdge);
	TopoDS_Shape aPrismCircle = BRepPrimAPI_MakePrism(aCircleWire, gp_Vec(0.0, 0.0, 5.0));
	Handle(AIS_Shape) anAisPrismCircle = new AIS_Shape(aPrismCircle);

	// prism a face or a shell result is a solid.
	anAxis.SetLocation(gp_Pnt(24.0, 60.0, 0.0));
	TopoDS_Edge aEllipseEdge = BRepBuilderAPI_MakeEdge(gp_Elips(anAxis, 3.0, 2.0));
	TopoDS_Wire aEllipseWire = BRepBuilderAPI_MakeWire(aEllipseEdge);
	TopoDS_Face aEllipseFace = BRepBuilderAPI_MakeFace(gp_Pln(gp::XOY()), aEllipseWire);
	TopoDS_Shape aPrismEllipse = BRepPrimAPI_MakePrism(aEllipseFace, gp_Vec(0.0, 0.0, 5.0));
	Handle(AIS_Shape) anAisPrismEllipse = new AIS_Shape(aPrismEllipse);

	anAisPrismVertex->SetColor(Quantity_NOC_PAPAYAWHIP);
	anAisPrismEdge->SetColor(Quantity_NOC_PEACHPUFF);
	anAisPrismCircle->SetColor(Quantity_NOC_PERU);
	anAisPrismEllipse->SetColor(Quantity_NOC_PINK);

	view->getContext()->Display(anAisPrismVertex, Standard_True);
	view->getContext()->Display(anAisPrismEdge, Standard_True);
	view->getContext()->Display(anAisPrismCircle, Standard_True);
	view->getContext()->Display(anAisPrismEllipse, Standard_True);
}

void MainWindow::makeRevol()
{
	gp_Ax1 anAxis;

	// revol a vertex result is an edge.
	anAxis.SetLocation(gp_Pnt(0.0, 70.0, 0.0));
	TopoDS_Vertex aVertex = BRepBuilderAPI_MakeVertex(gp_Pnt(2.0, 70.0, 0.0));
	TopoDS_Shape aRevolVertex = BRepPrimAPI_MakeRevol(aVertex, anAxis);
	Handle(AIS_Shape) anAisRevolVertex = new AIS_Shape(aRevolVertex);

	// revol an edge result is a face.
	anAxis.SetLocation(gp_Pnt(8.0, 70.0, 0.0));
	TopoDS_Edge anEdge = BRepBuilderAPI_MakeEdge(gp_Pnt(6.0, 70.0, 0.0), gp_Pnt(6.0, 70.0, 5.0));
	TopoDS_Shape aRevolEdge = BRepPrimAPI_MakeRevol(anEdge, anAxis);
	Handle(AIS_Shape) anAisRevolEdge = new AIS_Shape(aRevolEdge);

	// revol a wire result is a shell.
	anAxis.SetLocation(gp_Pnt(20.0, 70.0, 0.0));
	anAxis.SetDirection(gp::DY());

	TopoDS_Edge aCircleEdge = BRepBuilderAPI_MakeEdge(gp_Circ(gp_Ax2(gp_Pnt(15.0, 70.0, 0.0), gp::DZ()), 1.5));
	TopoDS_Wire aCircleWire = BRepBuilderAPI_MakeWire(aCircleEdge);
	TopoDS_Shape aRevolCircle = BRepPrimAPI_MakeRevol(aCircleWire, anAxis, M_PI_2);
	Handle(AIS_Shape) anAisRevolCircle = new AIS_Shape(aRevolCircle);

	// revol a face result is a solid.
	anAxis.SetLocation(gp_Pnt(30.0, 70.0, 0.0));
	anAxis.SetDirection(gp::DY());

	TopoDS_Edge aEllipseEdge = BRepBuilderAPI_MakeEdge(gp_Elips(gp_Ax2(gp_Pnt(25.0, 70.0, 0.0), gp::DZ()), 3.0, 2.0));
	TopoDS_Wire aEllipseWire = BRepBuilderAPI_MakeWire(aEllipseEdge);
	TopoDS_Face aEllipseFace = BRepBuilderAPI_MakeFace(gp_Pln(gp::XOY()), aEllipseWire);
	TopoDS_Shape aRevolEllipse = BRepPrimAPI_MakeRevol(aEllipseFace, anAxis, M_PI_4);
	Handle(AIS_Shape) anAisRevolEllipse = new AIS_Shape(aRevolEllipse);

	anAisRevolVertex->SetColor(Quantity_NOC_LIMEGREEN);
	anAisRevolEdge->SetColor(Quantity_NOC_LINEN);
	anAisRevolCircle->SetColor(Quantity_NOC_MAGENTA1);
	anAisRevolEllipse->SetColor(Quantity_NOC_MAROON);

	view->getContext()->Display(anAisRevolVertex, Standard_True);
	view->getContext()->Display(anAisRevolEdge, Standard_True);
	view->getContext()->Display(anAisRevolCircle, Standard_True);
	view->getContext()->Display(anAisRevolEllipse, Standard_True);
}

void MainWindow::makeLoft()
{
	// bottom wire.
	TopoDS_Edge aCircleEdge = BRepBuilderAPI_MakeEdge(gp_Circ(gp_Ax2(gp_Pnt(0.0, 80.0, 0.0), gp::DZ()), 1.5));
	TopoDS_Wire aCircleWire = BRepBuilderAPI_MakeWire(aCircleEdge);

	// top wire.
	BRepBuilderAPI_MakePolygon aPolygon;
	aPolygon.Add(gp_Pnt(-3.0, 77.0, 6.0));
	aPolygon.Add(gp_Pnt(3.0, 77.0, 6.0));
	aPolygon.Add(gp_Pnt(3.0, 83.0, 6.0));
	aPolygon.Add(gp_Pnt(-3.0, 83.0, 6.0));
	aPolygon.Close();

	BRepOffsetAPI_ThruSections aShellGenerator;
	BRepOffsetAPI_ThruSections aSolidGenerator(true);

	aShellGenerator.AddWire(aCircleWire);
	aShellGenerator.AddWire(aPolygon.Wire());

	aSolidGenerator.AddWire(aCircleWire);
	aSolidGenerator.AddWire(aPolygon.Wire());

	// translate the solid.
	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(18.0, 0.0, 0.0));
	BRepBuilderAPI_Transform aTransform(aSolidGenerator.Shape(), aTrsf);

	Handle(AIS_Shape) anAisShell = new AIS_Shape(aShellGenerator.Shape());
	Handle(AIS_Shape) anAisSolid = new AIS_Shape(aTransform.Shape());

	anAisShell->SetColor(Quantity_NOC_OLIVEDRAB);
	anAisSolid->SetColor(Quantity_NOC_PEACHPUFF);

	view->getContext()->Display(anAisShell, Standard_True);
	view->getContext()->Display(anAisSolid, Standard_True);
}

void MainWindow::testCut()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 90.0, 0.0));

	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(anAxis, 3.0, 4.0, 5.0).Shape();
	TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 2.5).Shape();
	TopoDS_Shape aCuttedShape1 = BRepAlgoAPI_Cut(aTopoBox, aTopoSphere);
	TopoDS_Shape aCuttedShape2 = BRepAlgoAPI_Cut(aTopoSphere, aTopoBox);

	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(8.0, 0.0, 0.0));
	BRepBuilderAPI_Transform aTransform1(aCuttedShape1, aTrsf);

	aTrsf.SetTranslation(gp_Vec(16.0, 0.0, 0.0));
	BRepBuilderAPI_Transform aTransform2(aCuttedShape2, aTrsf);

	Handle(AIS_Shape) anAisBox = new AIS_Shape(aTopoBox);
	Handle(AIS_Shape) anAisSphere = new AIS_Shape(aTopoSphere);
	Handle(AIS_Shape) anAisCuttedShape1 = new AIS_Shape(aTransform1.Shape());
	Handle(AIS_Shape) anAisCuttedShape2 = new AIS_Shape(aTransform2.Shape());

	anAisBox->SetColor(Quantity_NOC_SPRINGGREEN);
	anAisSphere->SetColor(Quantity_NOC_STEELBLUE);
	anAisCuttedShape1->SetColor(Quantity_NOC_TAN);
	anAisCuttedShape2->SetColor(Quantity_NOC_SALMON);

	view->getContext()->Display(anAisBox, Standard_True);
	view->getContext()->Display(anAisSphere, Standard_True);
	view->getContext()->Display(anAisCuttedShape1, Standard_True);
	view->getContext()->Display(anAisCuttedShape2, Standard_True);
}

void MainWindow::testFuse()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 100.0, 0.0));

	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(anAxis, 3.0, 4.0, 5.0).Shape();
	TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 2.5).Shape();
	TopoDS_Shape aFusedShape = BRepAlgoAPI_Fuse(aTopoBox, aTopoSphere);

	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(8.0, 0.0, 0.0));
	BRepBuilderAPI_Transform aTransform(aFusedShape, aTrsf);

	Handle(AIS_Shape) anAisBox = new AIS_Shape(aTopoBox);
	Handle(AIS_Shape) anAisSphere = new AIS_Shape(aTopoSphere);
	Handle(AIS_Shape) anAisFusedShape = new AIS_Shape(aTransform.Shape());

	anAisBox->SetColor(Quantity_NOC_SPRINGGREEN);
	anAisSphere->SetColor(Quantity_NOC_STEELBLUE);
	anAisFusedShape->SetColor(Quantity_NOC_ROSYBROWN);

	view->getContext()->Display(anAisBox, Standard_True);
	view->getContext()->Display(anAisSphere, Standard_True);
	view->getContext()->Display(anAisFusedShape, Standard_True);
}

void MainWindow::testCommon()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 110.0, 0.0));

	TopoDS_Shape aTopoBox = BRepPrimAPI_MakeBox(anAxis, 3.0, 4.0, 5.0).Shape();
	TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, 2.5).Shape();
	TopoDS_Shape aCommonShape = BRepAlgoAPI_Common(aTopoBox, aTopoSphere);

	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(8.0, 0.0, 0.0));
	BRepBuilderAPI_Transform aTransform(aCommonShape, aTrsf);

	Handle(AIS_Shape) anAisBox = new AIS_Shape(aTopoBox);
	Handle(AIS_Shape) anAisSphere = new AIS_Shape(aTopoSphere);
	Handle(AIS_Shape) anAisCommonShape = new AIS_Shape(aTransform.Shape());

	anAisBox->SetColor(Quantity_NOC_SPRINGGREEN);
	anAisSphere->SetColor(Quantity_NOC_STEELBLUE);
	anAisCommonShape->SetColor(Quantity_NOC_ROYALBLUE);

	view->getContext()->Display(anAisBox, Standard_True);
	view->getContext()->Display(anAisSphere, Standard_True);
	view->getContext()->Display(anAisCommonShape, Standard_True);
}

void MainWindow::testHelix()
{
	makeCylindricalHelix();

	makeConicalHelix();

	makeToroidalHelix();
}

void MainWindow::makeCylindricalHelix()
{
	Standard_Real aRadius = 3.0;
	Standard_Real aPitch = 1.0;

	// the pcurve is a 2d line in the parametric space.
	gp_Lin2d aLine2d(gp_Pnt2d(0.0, 0.0), gp_Dir2d(aRadius, aPitch));

	Handle(Geom2d_TrimmedCurve) aSegment = GCE2d_MakeSegment(aLine2d, 0.0, M_PI * 2.0).Value();

	Handle(Geom_CylindricalSurface) aCylinder = new Geom_CylindricalSurface(gp::XOY(), aRadius);

	TopoDS_Edge aHelixEdge = BRepBuilderAPI_MakeEdge(aSegment, aCylinder, 0.0, 6.0 * M_PI).Edge();

	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(0.0, 120.0, 0.0));
	BRepBuilderAPI_Transform aTransform(aHelixEdge, aTrsf);

	Handle(AIS_Shape) anAisHelixCurve = new AIS_Shape(aTransform.Shape());

	view->getContext()->Display(anAisHelixCurve, Standard_True);

	// sweep a circle profile along the helix curve.
	// there is no curve3d in the pcurve edge, so approx one.
	BRepLib::BuildCurve3d(aHelixEdge);

	gp_Ax2 anAxis;
	anAxis.SetDirection(gp_Dir(0.0, 4.0, 1.0));
	anAxis.SetLocation(gp_Pnt(aRadius, 0.0, 0.0));

	gp_Circ aProfileCircle(anAxis, 0.3);

	TopoDS_Edge aProfileEdge = BRepBuilderAPI_MakeEdge(aProfileCircle).Edge();
	TopoDS_Wire aProfileWire = BRepBuilderAPI_MakeWire(aProfileEdge).Wire();
	TopoDS_Face aProfileFace = BRepBuilderAPI_MakeFace(aProfileWire).Face();

	TopoDS_Wire aHelixWire = BRepBuilderAPI_MakeWire(aHelixEdge).Wire();

	BRepOffsetAPI_MakePipe aPipeMaker(aHelixWire, aProfileFace);

	if (aPipeMaker.IsDone())
	{
		aTrsf.SetTranslation(gp_Vec(8.0, 120.0, 0.0));
		BRepBuilderAPI_Transform aPipeTransform(aPipeMaker.Shape(), aTrsf);

		Handle(AIS_Shape) anAisPipe = new AIS_Shape(aPipeTransform.Shape());
		anAisPipe->SetColor(Quantity_NOC_CORAL);
		view->getContext()->Display(anAisPipe, Standard_True);
	}
}

/**
 * make conical helix, it is the same as the cylindrical helix,
 * the only different is the surface.
 */
void MainWindow::makeConicalHelix()
{
	Standard_Real aRadius = 3.0;
	Standard_Real aPitch = 1.0;

	// the pcurve is a 2d line in the parametric space.
	gp_Lin2d aLine2d(gp_Pnt2d(0.0, 0.0), gp_Dir2d(aRadius, aPitch));

	Handle(Geom2d_TrimmedCurve) aSegment = GCE2d_MakeSegment(aLine2d, 0.0, M_PI * 2.0).Value();

	Handle(Geom_ConicalSurface) aCylinder = new Geom_ConicalSurface(gp::XOY(), M_PI / 6.0, aRadius);

	TopoDS_Edge aHelixEdge = BRepBuilderAPI_MakeEdge(aSegment, aCylinder, 0.0, 6.0 * M_PI).Edge();

	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(18.0, 120.0, 0.0));
	BRepBuilderAPI_Transform aTransform(aHelixEdge, aTrsf);

	Handle(AIS_Shape) anAisHelixCurve = new AIS_Shape(aTransform.Shape());

	view->getContext()->Display(anAisHelixCurve, Standard_True);

	// sweep a circle profile along the helix curve.
	// there is no curve3d in the pcurve edge, so approx one.
	BRepLib::BuildCurve3d(aHelixEdge);

	gp_Ax2 anAxis;
	anAxis.SetDirection(gp_Dir(0.0, 4.0, 1.0));
	anAxis.SetLocation(gp_Pnt(aRadius, 0.0, 0.0));

	gp_Circ aProfileCircle(anAxis, 0.3);

	TopoDS_Edge aProfileEdge = BRepBuilderAPI_MakeEdge(aProfileCircle).Edge();
	TopoDS_Wire aProfileWire = BRepBuilderAPI_MakeWire(aProfileEdge).Wire();
	TopoDS_Face aProfileFace = BRepBuilderAPI_MakeFace(aProfileWire).Face();

	TopoDS_Wire aHelixWire = BRepBuilderAPI_MakeWire(aHelixEdge).Wire();

	BRepOffsetAPI_MakePipe aPipeMaker(aHelixWire, aProfileFace);

	if (aPipeMaker.IsDone())
	{
		aTrsf.SetTranslation(gp_Vec(28.0, 120.0, 0.0));
		BRepBuilderAPI_Transform aPipeTransform(aPipeMaker.Shape(), aTrsf);

		Handle(AIS_Shape) anAisPipe = new AIS_Shape(aPipeTransform.Shape());
		anAisPipe->SetColor(Quantity_NOC_DARKGOLDENROD);
		view->getContext()->Display(anAisPipe, Standard_True);
	}
}

void MainWindow::makeToroidalHelix()
{
	Standard_Real aRadius = 1.0;
	Standard_Real aSlope = 0.05;

	// the pcurve is a 2d line in the parametric space.
	gp_Lin2d aLine2d(gp_Pnt2d(0.0, 0.0), gp_Dir2d(aSlope, 1.0));

	Handle(Geom2d_TrimmedCurve) aSegment = GCE2d_MakeSegment(aLine2d, 0.0, M_PI * 2.0).Value();

	Handle(Geom_ToroidalSurface) aCylinder = new Geom_ToroidalSurface(gp::XOY(), aRadius * 5.0, aRadius);

	TopoDS_Edge aHelixEdge = BRepBuilderAPI_MakeEdge(aSegment, aCylinder, 0.0, 2.0 * M_PI / aSlope).Edge();

	gp_Trsf aTrsf;
	aTrsf.SetTranslation(gp_Vec(45.0, 120.0, 0.0));
	BRepBuilderAPI_Transform aTransform(aHelixEdge, aTrsf);

	Handle(AIS_Shape) anAisHelixCurve = new AIS_Shape(aTransform.Shape());

	view->getContext()->Display(anAisHelixCurve, Standard_True);

	// sweep a circle profile along the helix curve.
	// there is no curve3d in the pcurve edge, so approx one.
	BRepLib::BuildCurve3d(aHelixEdge);

	gp_Ax2 anAxis;
	anAxis.SetDirection(gp_Dir(0.0, 0.0, 1.0));
	anAxis.SetLocation(gp_Pnt(aRadius * 6.0, 0.0, 0.0));

	gp_Circ aProfileCircle(anAxis, 0.3);

	TopoDS_Edge aProfileEdge = BRepBuilderAPI_MakeEdge(aProfileCircle).Edge();
	TopoDS_Wire aProfileWire = BRepBuilderAPI_MakeWire(aProfileEdge).Wire();
	TopoDS_Face aProfileFace = BRepBuilderAPI_MakeFace(aProfileWire).Face();

	TopoDS_Wire aHelixWire = BRepBuilderAPI_MakeWire(aHelixEdge).Wire();

	BRepOffsetAPI_MakePipe aPipeMaker(aHelixWire, aProfileFace);

	if (aPipeMaker.IsDone())
	{
		aTrsf.SetTranslation(gp_Vec(60.0, 120.0, 0.0));
		BRepBuilderAPI_Transform aPipeTransform(aPipeMaker.Shape(), aTrsf);

		Handle(AIS_Shape) anAisPipe = new AIS_Shape(aPipeTransform.Shape());
		anAisPipe->SetColor(Quantity_NOC_CORNSILK1);
		view->getContext()->Display(anAisPipe, Standard_True);
	}
}