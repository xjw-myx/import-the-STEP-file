#ifndef VIEW_H
#define VIEW_H
#include"occ.h"
#include <QWidget>
#include<QRubberBand>
#include<QMenu>
class View : public QWidget
{
	Q_OBJECT
public:
	//! mouse actions.
	enum CurrentAction3d
	{
		CurAction3d_Nothing,
		CurAction3d_DynamicZooming,
		CurAction3d_WindowZooming,
		CurAction3d_DynamicPanning,
		CurAction3d_GlobalPanning,
		CurAction3d_DynamicRotation
	};

public:
	explicit View(QWidget *parent = nullptr);
	QPaintEngine *paintEngine() const;
	const Handle(AIS_InteractiveContext)& getContext() const;

	Handle(V3d_View) m_view;

signals:
	void selectionChanged(void);

public slots:
	//! operations for the view.
	void pan(void);
	void fitAll(void);
	void reset(void);
	void zoom(void);
	void rotate(void);
	void mesh(void);

protected:
	// Paint events.
	virtual void paintEvent(QPaintEvent* theEvent);
	virtual void resizeEvent(QResizeEvent* theEvent);

	// Mouse events.
	virtual void mousePressEvent(QMouseEvent* theEvent);
	virtual void mouseReleaseEvent(QMouseEvent* theEvent);
	virtual void mouseMoveEvent(QMouseEvent * theEvent);
	virtual void wheelEvent(QWheelEvent * theEvent);

	// Button events.
	virtual void onLButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onMButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onRButtonDown(const int theFlags, const QPoint thePoint);
	virtual void onMouseWheel(const int theFlags, const int theDelta, const QPoint thePoint);
	virtual void onLButtonUp(const int theFlags, const QPoint thePoint);
	virtual void onMButtonUp(const int theFlags, const QPoint thePoint);
	virtual void onRButtonUp(const int theFlags, const QPoint thePoint);
	virtual void onMouseMove(const int theFlags, const QPoint thePoint);

	// Popup menu.
	virtual void addItemInPopup(QMenu* theMenu);

protected:
	void popup(const int x, const int y);
	void dragEvent(const int x, const int y);
	void inputEvent(const int x, const int y);
	void moveEvent(const int x, const int y);
	void multiMoveEvent(const int x, const int y);
	void multiDragEvent(const int x, const int y);
	void multiInputEvent(const int x, const int y);
	void drawRubberBand(const int minX, const int minY, const int maxX, const int maxY);
	void panByMiddleButton(const QPoint& thePoint);

private:
	Handle(AIS_InteractiveContext) m_context;
	Handle(V3d_Viewer) m_viewer;
	Handle(Graphic3d_GraphicDriver) m_graphic_driver;
	//! save the mouse position.
	Standard_Integer myXmin;
	Standard_Integer myYmin;
	Standard_Integer myXmax;
	Standard_Integer myYmax;
	Standard_Integer myYZoom;

	//! the mouse current mode.
	CurrentAction3d myCurrentMode;

	//! save the degenerate mode state.
	Standard_Boolean myDegenerateModeIsOn;

	//! rubber rectangle for the mouse selection.
	QRubberBand* myRectBand=nullptr;
};

#endif // VIEW_H
