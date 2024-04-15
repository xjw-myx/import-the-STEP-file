#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"
#include"occ.h"
#include"View.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
protected:
	//! create all the actions.
	void createActions(void);
	//! create all the menus.
	void createMenus(void);

	//! create the toolbar.
	void createToolBars(void);

	//! make cylindrical helix.
	void makeCylindricalHelix(void);

	//! make conical helix.
	void makeConicalHelix(void);

	//! make toroidal helix.
	void makeToroidalHelix(void);

private slots:
	//! show about box.
	void about(void);

	//! make box test.
	void makeBox(void);

	//! make cone test.
	void makeCone(void);

	//! make sphere test.
	void makeSphere(void);

	//! make cylinder test.
	void makeCylinder(void);

	//! make torus test.
	void makeTorus(void);

	//! fillet test.
	void makeFillet(void);

	//! chamfer test.
	void makeChamfer(void);

	//! test extrude algorithm.
	void makeExtrude(void);

	//! test revol algorithm.
	void makeRevol(void);

	//! test loft algorithm.
	void makeLoft(void);

	//! test boolean operation cut.
	void testCut(void);

	//! test boolean operation fuse.
	void testFuse(void);

	//! test boolean operation common.
	void testCommon(void);

	//! test helix shapes.
	void testHelix(void);

	//∂¡»°igs
	void readIgs();
	//∂¡»°step
	void readStep();

private:
    Ui::MainWindow ui;
	View* view;
};
