/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionZoom;
    QAction *actionPan;
    QAction *actionRotate;
    QAction *actionReset;
    QAction *actionFitAll;
    QAction *actionAbout;
    QAction *actionBox;
    QAction *actionCone;
    QAction *actionSphere;
    QAction *actionCylinder;
    QAction *actionTorus;
    QAction *actionFillet;
    QAction *actionChamfer;
    QAction *actionExtrude;
    QAction *actionRevolve;
    QAction *actionLoft;
    QAction *actionCut;
    QAction *actionFuse;
    QAction *actionCommon;
    QAction *actionHelix;
    QAction *actionreadIGS;
    QAction *actionreadSTEP;
    QAction *actionMesh;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuPrimitive;
    QMenu *menuModeling;
    QMenu *menuHelp;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Resources/lamp.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionZoom = new QAction(MainWindow);
        actionZoom->setObjectName(QString::fromUtf8("actionZoom"));
        actionZoom->setCheckable(false);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Resources/Zoom.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoom->setIcon(icon1);
        actionPan = new QAction(MainWindow);
        actionPan->setObjectName(QString::fromUtf8("actionPan"));
        actionPan->setCheckable(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Resources/Pan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPan->setIcon(icon2);
        actionRotate = new QAction(MainWindow);
        actionRotate->setObjectName(QString::fromUtf8("actionRotate"));
        actionRotate->setCheckable(false);
        actionRotate->setChecked(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/Resources/Rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon3);
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/Resources/Home.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon4);
        actionFitAll = new QAction(MainWindow);
        actionFitAll->setObjectName(QString::fromUtf8("actionFitAll"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/Resources/FitAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFitAll->setIcon(icon5);
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionAbout->setIcon(icon);
        actionBox = new QAction(MainWindow);
        actionBox->setObjectName(QString::fromUtf8("actionBox"));
        actionBox->setIcon(icon4);
        actionCone = new QAction(MainWindow);
        actionCone->setObjectName(QString::fromUtf8("actionCone"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/Resources/cone.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCone->setIcon(icon6);
        actionSphere = new QAction(MainWindow);
        actionSphere->setObjectName(QString::fromUtf8("actionSphere"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/Resources/sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSphere->setIcon(icon7);
        actionCylinder = new QAction(MainWindow);
        actionCylinder->setObjectName(QString::fromUtf8("actionCylinder"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/Resources/cylinder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCylinder->setIcon(icon8);
        actionTorus = new QAction(MainWindow);
        actionTorus->setObjectName(QString::fromUtf8("actionTorus"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/Resources/torus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTorus->setIcon(icon9);
        actionFillet = new QAction(MainWindow);
        actionFillet->setObjectName(QString::fromUtf8("actionFillet"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/Resources/fillet.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFillet->setIcon(icon10);
        actionChamfer = new QAction(MainWindow);
        actionChamfer->setObjectName(QString::fromUtf8("actionChamfer"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/Resources/chamfer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionChamfer->setIcon(icon11);
        actionExtrude = new QAction(MainWindow);
        actionExtrude->setObjectName(QString::fromUtf8("actionExtrude"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/Resources/extrude.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExtrude->setIcon(icon12);
        actionRevolve = new QAction(MainWindow);
        actionRevolve->setObjectName(QString::fromUtf8("actionRevolve"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/Resources/revolve.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRevolve->setIcon(icon13);
        actionLoft = new QAction(MainWindow);
        actionLoft->setObjectName(QString::fromUtf8("actionLoft"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/Resources/loft.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLoft->setIcon(icon14);
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/Resources/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon15);
        actionFuse = new QAction(MainWindow);
        actionFuse->setObjectName(QString::fromUtf8("actionFuse"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/Resources/fuse.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFuse->setIcon(icon16);
        actionCommon = new QAction(MainWindow);
        actionCommon->setObjectName(QString::fromUtf8("actionCommon"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/Resources/common.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCommon->setIcon(icon17);
        actionHelix = new QAction(MainWindow);
        actionHelix->setObjectName(QString::fromUtf8("actionHelix"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/Resources/helix.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelix->setIcon(icon18);
        actionreadIGS = new QAction(MainWindow);
        actionreadIGS->setObjectName(QString::fromUtf8("actionreadIGS"));
        actionreadSTEP = new QAction(MainWindow);
        actionreadSTEP->setObjectName(QString::fromUtf8("actionreadSTEP"));
        actionMesh = new QAction(MainWindow);
        actionMesh->setObjectName(QString::fromUtf8("actionMesh"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/Resources/mesh.ico"), QSize(), QIcon::Normal, QIcon::Off);
        actionMesh->setIcon(icon19);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        menuPrimitive = new QMenu(menuBar);
        menuPrimitive->setObjectName(QString::fromUtf8("menuPrimitive"));
        menuModeling = new QMenu(menuBar);
        menuModeling->setObjectName(QString::fromUtf8("menuModeling"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuPrimitive->menuAction());
        menuBar->addAction(menuModeling->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionreadIGS);
        menuFile->addAction(actionreadSTEP);
        menuFile->addAction(actionExit);
        menuView->addAction(actionZoom);
        menuView->addAction(actionPan);
        menuView->addAction(actionRotate);
        menuView->addSeparator();
        menuView->addAction(actionReset);
        menuView->addAction(actionFitAll);
        menuView->addSeparator();
        menuView->addAction(actionMesh);
        menuPrimitive->addAction(actionBox);
        menuPrimitive->addAction(actionCone);
        menuPrimitive->addAction(actionSphere);
        menuPrimitive->addAction(actionCylinder);
        menuPrimitive->addAction(actionTorus);
        menuModeling->addAction(actionFillet);
        menuModeling->addAction(actionChamfer);
        menuModeling->addAction(actionExtrude);
        menuModeling->addAction(actionRevolve);
        menuModeling->addAction(actionLoft);
        menuModeling->addSeparator();
        menuModeling->addAction(actionCut);
        menuModeling->addAction(actionFuse);
        menuModeling->addAction(actionCommon);
        menuModeling->addSeparator();
        menuModeling->addAction(actionHelix);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "OCC_GUOMAO", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("MainWindow", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionZoom->setText(QApplication::translate("MainWindow", "Zoom", nullptr));
        actionPan->setText(QApplication::translate("MainWindow", "Pan", nullptr));
        actionRotate->setText(QApplication::translate("MainWindow", "Rotate", nullptr));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", nullptr));
        actionFitAll->setText(QApplication::translate("MainWindow", "FitAll", nullptr));
        actionAbout->setText(QApplication::translate("MainWindow", "About", nullptr));
        actionBox->setText(QApplication::translate("MainWindow", "Box", nullptr));
        actionCone->setText(QApplication::translate("MainWindow", "Cone", nullptr));
        actionSphere->setText(QApplication::translate("MainWindow", "Sphere", nullptr));
        actionCylinder->setText(QApplication::translate("MainWindow", "Cylinder", nullptr));
        actionTorus->setText(QApplication::translate("MainWindow", "Torus", nullptr));
        actionFillet->setText(QApplication::translate("MainWindow", "Fillet", nullptr));
        actionChamfer->setText(QApplication::translate("MainWindow", "Chamfer", nullptr));
        actionExtrude->setText(QApplication::translate("MainWindow", "Extrude", nullptr));
        actionRevolve->setText(QApplication::translate("MainWindow", "Rovelve", nullptr));
        actionLoft->setText(QApplication::translate("MainWindow", "Loft", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
        actionFuse->setText(QApplication::translate("MainWindow", "Fuse", nullptr));
        actionCommon->setText(QApplication::translate("MainWindow", "Common", nullptr));
        actionHelix->setText(QApplication::translate("MainWindow", "Helix", nullptr));
        actionreadIGS->setText(QApplication::translate("MainWindow", "readIGS", nullptr));
        actionreadSTEP->setText(QApplication::translate("MainWindow", "readSTEP", nullptr));
        actionMesh->setText(QApplication::translate("MainWindow", "Mesh", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QApplication::translate("MainWindow", "View", nullptr));
        menuPrimitive->setTitle(QApplication::translate("MainWindow", "Primitive", nullptr));
        menuModeling->setTitle(QApplication::translate("MainWindow", "Modeling", nullptr));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
