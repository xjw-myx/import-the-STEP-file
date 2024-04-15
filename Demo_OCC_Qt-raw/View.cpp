#include "View.h"
#include <QMenu>
#include <QMouseEvent>
#include <QRubberBand>
#include <QStyleFactory>
#include <QDebug>
//#include <gmsh.h>
#include<AIS_ViewCube.hxx>
#include<Resource_Unicode.hxx>
#include<AIS_TextLabel.hxx>
#include <StdSelect_BRepOwner.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <StlAPI_Reader.hxx>
//using namespace std;
//using namespace gmsh;
// #ifdef _DEBUG  
// #define new DEBUG_NEW  
// #endif
//#include"occall.h"
View::View(QWidget *parent) : QWidget(parent)
{
	if (m_context.IsNull())//������ʽ������Ϊ��
	{
		//�˶����ṩ��X server�����ӣ���Windows��Mac OS�в�������
		Handle(Aspect_DisplayConnection) m_display_connection = new Aspect_DisplayConnection();
		//����OpenGlͼ������
		if (m_graphic_driver.IsNull())
		{
			m_graphic_driver = new OpenGl_GraphicDriver(m_display_connection);
		}
		//��ȡQWidget�Ĵ���ϵͳ��ʶ��
		WId window_handle = (WId)winId();
		// ����Windows NT ����
		Handle(WNT_Window) wind = new WNT_Window((Aspect_Handle)window_handle);
		//����3D�鿴��
		m_viewer = new V3d_Viewer(m_graphic_driver);
		//������ͼ
		m_view = m_viewer->CreateView();
		m_view->SetWindow(wind);
		//�򿪴���
		if (!wind->IsMapped())
		{
			wind->Map();
		}
		//��������ʽ������
		m_context = new AIS_InteractiveContext(m_viewer);
		//���ò鿴���Ĺ���
		m_viewer->SetDefaultLights();
		//�򿪱����ƹ�
		m_viewer->SetLightOn();
		//������ͼ�ı�����ɫΪ��ɫ
		m_view->SetBackgroundColor(Quantity_NOC_BLACK);
		m_view->MustBeResized();;
		//��ʾֱ������ϵ�����������ڴ�����ʾλ�á�������ɫ����С����ʽ
		//m_view->TriedronDisplay(Aspect_TOTP_LEFT_LOWER, Quantity_NOC_GOLD, 0.2, V3d_ZBUFFER);
		//���ý���ʽ�����ĵ���ʾģʽ
		m_context->SetDisplayMode(AIS_Shaded, Standard_True);
		//����ģ�͸������
		Handle(Prs3d_Drawer) t_hilight_style = m_context->HighlightStyle();
		t_hilight_style->SetMethod(Aspect_TOHM_COLOR);  // ��ɫ��ʾ��ʽ
		t_hilight_style->SetColor(Quantity_NOC_LIGHTYELLOW);    // ���ø�����ɫ
		t_hilight_style->SetDisplayMode(1); // �������
		t_hilight_style->SetTransparency(0.2f); // ����͸����

		// ����ѡ��ģ�͵ķ��
		Handle(Prs3d_Drawer) t_select_style = m_context->SelectionStyle();  // ��ȡѡ����
		t_select_style->SetMethod(Aspect_TOHM_COLOR);  // ��ɫ��ʾ��ʽ
		t_select_style->SetColor(Quantity_NOC_LIGHTSEAGREEN);   // ����ѡ�����ɫ
		t_select_style->SetDisplayMode(1); // �������
		t_select_style->SetTransparency(0.4f); // ����͸����

		TCollection_ExtendedString tostr;
		Handle(AIS_ViewCube) H_AisViewCube = new AIS_ViewCube();
		Resource_Unicode::ConvertGBToUnicode(Standard_CString("��"), tostr);
		H_AisViewCube->SetBoxSideLabel(V3d_Xpos, tostr);
		Resource_Unicode::ConvertGBToUnicode(Standard_CString("��"), tostr);
		H_AisViewCube->SetBoxSideLabel(V3d_Ypos, tostr);
		Resource_Unicode::ConvertGBToUnicode(Standard_CString("��"), tostr);
		H_AisViewCube->SetBoxSideLabel(V3d_Zpos, tostr);
		Resource_Unicode::ConvertGBToUnicode(Standard_CString("��"), tostr);
		H_AisViewCube->SetBoxSideLabel(V3d_Xneg, tostr);
		Resource_Unicode::ConvertGBToUnicode(Standard_CString("ǰ"), tostr);
		H_AisViewCube->SetBoxSideLabel(V3d_Yneg, tostr);
		Resource_Unicode::ConvertGBToUnicode(Standard_CString("��"), tostr);
		H_AisViewCube->SetBoxSideLabel(V3d_Zneg, tostr);
		H_AisViewCube->SetTransparency(0.8);
		H_AisViewCube->SetTextColor(Quantity_Color(Quantity_NOC_WHITE));
		H_AisViewCube->SetFontHeight(20);
		H_AisViewCube->SetMaterial(Graphic3d_MaterialAspect(Graphic3d_NOM_STEEL));
		H_AisViewCube->SetTransformPersistence(
			new Graphic3d_TransformPers(
				Graphic3d_TMF_TriedronPers,
				Aspect_TOTP_LEFT_LOWER,
				Graphic3d_Vec2i(100, 100)));
		m_context->Display(H_AisViewCube, Standard_True);
	}
	setAttribute(Qt::WA_PaintOnScreen);
	setAttribute(Qt::WA_NoSystemBackground);
	setBackgroundRole(QPalette::NoRole);
	setFocusPolicy(Qt::StrongFocus);
	setMouseTracking(true);//����������


}

void View::paintEvent(QPaintEvent *)
{m_view->Redraw();}

void View::resizeEvent(QResizeEvent *)
{if (!m_view.IsNull())m_view->MustBeResized();}


QPaintEngine *View::paintEngine() const
{
	return 0;
}

const Handle(AIS_InteractiveContext)& View::getContext() const
{
	return m_context;
}


void View::fitAll(void)
{
	m_view->FitAll();
	m_view->ZFitAll();
	m_view->Redraw();
}

void View::reset(void)
{
	m_view->Reset();
}

void View::pan(void)
{
	myCurrentMode = CurAction3d_DynamicPanning;
}

void View::zoom(void)
{
	myCurrentMode = CurAction3d_DynamicZooming;
}

void View::rotate(void)
{
	myCurrentMode = CurAction3d_DynamicRotation;
}

void View::mesh(void)
{
	//m_context->InitSelected();
	//Handle_StdSelect_BRepOwner s = Handle_StdSelect_BRepOwner::DownCast(m_context->SelectedOwner());
	//TopoDS_Shape a = s->Shape();
	//initialize();
	//option::setNumber("General.Terminal", 1);
	//option::setNumber("Mesh.Algorithm", 1);
	//option::setNumber("Mesh.Algorithm3D", 1);
	//option::setNumber("Mesh.MinimumCirclePoints", 20);
	//option::setNumber("Mesh.MeshSizeMax", 3);
	//std::vector<std::pair<int, int>> dimTags;
	//model::occ::importShapesNativePointer(&a, dimTags);
	//model::occ::synchronize();
	//model::mesh::setSize(dimTags,2);
	//model::mesh::generate(3);
	//write("temp.stl");
	//finalize();
	//StlAPI_Reader reader;
	////TopoDS_Shape shape;
	//if (reader.Read(a, Standard_CString("temp.stl")))
	//{
	//	Handle(AIS_Shape) anAisModel = new AIS_Shape(a);
	//	anAisModel->SetColor(Quantity_NOC_CHOCOLATE);
	//	anAisModel->SetTransparency(0);
	//	m_context->Display(anAisModel,1,3,Standard_True, Standard_True,AIS_DS_None);
	//	anAisModel->SetDisplayMode(AIS_Shaded);
	//	anAisModel->Attributes()->SetFaceBoundaryDraw(true);
	//	anAisModel->Attributes()->SetFaceBoundaryAspect(new Prs3d_LineAspect(Quantity_NOC_BLACK, Aspect_TOL_SOLID, 1.0));
	//	anAisModel->Attributes()->SetIsoOnTriangulation(true);
	//	anAisModel->Redisplay();
	//}
	//m_context->EraseSelected(true);

}




//��갴���¼�
void View::mousePressEvent(QMouseEvent* theEvent)
{
	if (theEvent->button() == Qt::LeftButton)
	{//�������
		onLButtonDown((theEvent->buttons() | theEvent->modifiers()), theEvent->pos());
	}
	else if (theEvent->button() == Qt::MidButton)
	{//�м�����
		onMButtonDown((theEvent->buttons() | theEvent->modifiers()), theEvent->pos());
	}
	else if (theEvent->button() == Qt::RightButton)
	{//�Ҽ�����
		onRButtonDown((theEvent->buttons() | theEvent->modifiers()), theEvent->pos());
	}
}
//����ͷ�
void View::mouseReleaseEvent(QMouseEvent* theEvent)
{
	if (theEvent->button() == Qt::LeftButton)
	{//���
		onLButtonUp(theEvent->buttons() | theEvent->modifiers(), theEvent->pos());
	}
	else if (theEvent->button() == Qt::MidButton)
	{
		onMButtonUp(theEvent->buttons() | theEvent->modifiers(), theEvent->pos());
	}
	else if (theEvent->button() == Qt::RightButton)
	{
		onRButtonUp(theEvent->buttons() | theEvent->modifiers(), theEvent->pos());
	}
}
//����ƶ�
void View::mouseMoveEvent(QMouseEvent * theEvent)
{
	onMouseMove(theEvent->buttons()| theEvent->modifiers(), theEvent->pos());
}
//���ֹ���
void View::wheelEvent(QWheelEvent * theEvent)
{
	onMouseWheel(theEvent->buttons(), theEvent->delta(), theEvent->pos());
}
//�������
void View::onLButtonDown(const int /*theFlags*/, const QPoint thePoint)
{
	// Save the current mouse coordinate in min.
	myXmin = thePoint.x();
	myYmin = thePoint.y();
	myXmax = thePoint.x();
	myYmax = thePoint.y();

}
//�м�����
void View::onMButtonDown(const int /*theFlags*/, const QPoint thePoint)
{
	// Save the current mouse coordinate in min.
	myXmin = thePoint.x();
	myYmin = thePoint.y();
	myXmax = thePoint.x();
	myYmax = thePoint.y();
	myYZoom = thePoint.y();
	m_view->StartRotation(thePoint.x(), thePoint.y());
}
//�Ҽ�����
void View::onRButtonDown(const int /*theFlags*/, const QPoint thePoint)
{
	myXmin = thePoint.x();
	myYmin = thePoint.y();
	myXmax = thePoint.x();
	myYmax = thePoint.y();
	myYZoom = thePoint.y();
	m_view->StartRotation(thePoint.x(), thePoint.y());


}
//��������
void View::onMouseWheel(const int /*theFlags*/, const int theDelta, const QPoint thePoint)
{
	Standard_Integer aFactor = 16;
	Standard_Integer aX = thePoint.x();
	Standard_Integer aY = thePoint.y();
	if (theDelta > 0)
	{
		aX += aFactor;
		aY += aFactor;
	}
	else
	{
		aX -= aFactor;
		aY -= aFactor;
	}
	m_view->StartZoomAtPoint(thePoint.x(), thePoint.y());
	m_view->ZoomAtPoint(thePoint.x(), thePoint.y(), aX, aY);
}

void View::addItemInPopup(QMenu* /*theMenu*/)
{

}

void View::popup(const int /*x*/, const int /*y*/)
{
}
//����ͷ�
void View::onLButtonUp(const int theFlags, const QPoint thePoint)
{
	// Hide the QRubberBand
	if (myRectBand)
	{
		myRectBand->hide();
	}

	// Ctrl for multi selection.
	if (thePoint.x() == myXmin && thePoint.y() == myYmin)
	{
		if (theFlags)
		{
			multiInputEvent(thePoint.x(), thePoint.y());
		}
		else
		{
			inputEvent(thePoint.x(), thePoint.y());
		}
	}

}
//�м��ͷ�
void View::onMButtonUp(const int /*theFlags*/, const QPoint thePoint)
{
	if (thePoint.x() == myXmin && thePoint.y() == myYmin)
	{
//���㴦����
		panByMiddleButton(thePoint);
	}
}
//�Ҽ��ͷ�
void View::onRButtonUp(const int /*theFlags*/, const QPoint thePoint)
{
	 popup(thePoint.x(), thePoint.y());
}

void View::onMouseMove(const int theFlags, const QPoint thePoint)
{
	// ���ƿ�ѡ����
	if (theFlags & Qt::LeftButton)
	{
		drawRubberBand(myXmin, myYmin, thePoint.x(), thePoint.y());

		dragEvent(thePoint.x(), thePoint.y());
	}
	// ̽����괦����
	if (theFlags & Qt::ControlModifier)
	{
		multiMoveEvent(thePoint.x(), thePoint.y());
	}
	else
	{
		moveEvent(thePoint.x(), thePoint.y());
	}

	// ��ת
	if ((theFlags & Qt::MidButton)==Qt::MidButton)
	{
		if ((theFlags & Qt::ControlModifier)==Qt::ControlModifier)
		{
			m_view->Pan(thePoint.x() - myXmax, myYmax - thePoint.y());
			myXmax = thePoint.x();
			myYmax = thePoint.y();
		}
		else m_view->Rotation(thePoint.x(), thePoint.y());
	}
	//ƽ��
	if (theFlags & Qt::RightButton)
	{
		switch (myCurrentMode)
		{
		case CurAction3d_DynamicRotation:
		{
			m_view->Rotation(thePoint.x(), thePoint.y());
			break;
		}

		case CurAction3d_DynamicZooming:
		{
			
			Standard_Integer aFactor = 5;
			Standard_Integer aX = myXmin;
			Standard_Integer aY = myYmin;
			if (thePoint.y()-myYZoom > 0)
			{
				aX += aFactor;
				aY += aFactor;
			}
			else
			{
				aX -= aFactor;
				aY -= aFactor;
			}
			m_view->StartZoomAtPoint(myXmin, myYmin);
			m_view->ZoomAtPoint(myXmin, myYmin, aX, aY);
			myYZoom = thePoint.y();
		break;
		}

		case CurAction3d_DynamicPanning:
		{
			m_view->Pan(thePoint.x() - myXmax, myYmax - thePoint.y());
			myXmax = thePoint.x();
			myYmax = thePoint.y();
			break;
		}
			

		default:
			break;
		}
	}

}
//��ѡ
void View::dragEvent(const int x, const int y)
{
	m_context->Select(myXmin, myYmin, x, y, m_view, Standard_True);

	emit selectionChanged();
}
//��ѡ����
void View::multiDragEvent(const int x, const int y)
{
	m_context->ShiftSelect(myXmin, myYmin, x, y, m_view, Standard_True);

	emit selectionChanged();

}
//��ѡ
void View::inputEvent(const int x, const int y)
{
	Q_UNUSED(x);
	Q_UNUSED(y);

	m_context->Select(Standard_True);

	emit selectionChanged();
}
//��ѡ����
void View::multiInputEvent(const int x, const int y)
{
	Q_UNUSED(x);
	Q_UNUSED(y);

	m_context->ShiftSelect(Standard_True);

	emit selectionChanged();
}
//�ƶ�λ�ô�Ԫ��̽��
void View::moveEvent(const int x, const int y)
{
	m_context->MoveTo(x, y, m_view, Standard_True);
}
//�ƶ�λ�ô�Ԫ��̽�⣬ͬ��
void View::multiMoveEvent(const int x, const int y)
{
	m_context->MoveTo(x, y, m_view, Standard_True);
}
//���ƿ�ѡ����
void View::drawRubberBand(const int minX, const int minY, const int maxX, const int maxY)
{
	QRect aRect;

	// Set the rectangle correctly.
	(minX < maxX) ? (aRect.setX(minX)) : (aRect.setX(maxX));
	(minY < maxY) ? (aRect.setY(minY)) : (aRect.setY(maxY));

	aRect.setWidth(abs(maxX - minX));
	aRect.setHeight(abs(maxY - minY));

	if (!myRectBand)
	{
		myRectBand = new QRubberBand(QRubberBand::Rectangle, this);

		// setStyle is important, set to windows style will just draw
		// rectangle frame, otherwise will draw a solid rectangle.
		myRectBand->setStyle(QStyleFactory::create("windows"));
	}

	myRectBand->setGeometry(aRect);
	myRectBand->show();
}

void View::panByMiddleButton(const QPoint& thePoint)
{
	Standard_Integer aCenterX = 0;
	Standard_Integer aCenterY = 0;

	QSize aSize = size();

	aCenterX = aSize.width() / 2;
	aCenterY = aSize.height() / 2;

	m_view->Pan(aCenterX - thePoint.x(), thePoint.y() - aCenterY);
}
