/********************************************************************************
** Form generated from reading ui file 'Pantocrator3.ui'
**
** Created: Mon Jul 28 20:18:45 2008
**      by: Qt User Interface Compiler version 4.4.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef _OSGPARTI_MAINWINDOW_HPP_
#define _OSGPARTI_MAINWINDOW_HPP_ 1

#include <osgParti/Export.hpp>
#include <osgParti/AdapterWidget.hpp>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QScrollBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QWidget>


namespace osgParti{


class OSGPARTI_EXPORT Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_As;
    QAction *actionParticleSystem;
    QAction *actionProcedural_Texture;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    ViewerQT *osgwidget;
    QTabWidget *color_gr;
    QWidget *tab;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QComboBox *shape_cb;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *life_sb;
    QLabel *label_5;
    QDoubleSpinBox *radius_sb;
    QLabel *label_6;
    QDoubleSpinBox *mass_sb;
    QDoubleSpinBox *sizemax_sb;
    QDoubleSpinBox *sizemin_sb;
    QLabel *label;
    QComboBox *alignment_cb;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_8;
    QToolButton *fromcolorButton;
    QLabel *label_9;
    QToolButton *tocolorButton;
    QLabel *label_10;
    QGroupBox *emitter_gr;
    QComboBox *placer_cb;
    QLabel *label_7;
    QGroupBox *radialshooter_gr;
    QScrollBar *thetaSlider;
    QLabel *label_11;
    QLabel *label_12;
    QSlider *phiSlider;
    QLabel *label_13;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_14;
    QDoubleSpinBox *speedmin_sb;
    QLabel *label_15;
    QDoubleSpinBox *speedmax_sb;
    QLabel *label_16;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_17;
    QDoubleSpinBox *countermin_sb;
    QLabel *label_18;
    QDoubleSpinBox *countermax_sb;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QStatusBar *statusbar;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;

    void setupUi(QMainWindow *mainWindow)
    {
    if (mainWindow->objectName().isEmpty())
        mainWindow->setObjectName(QString::fromUtf8("mainWindow"));
    mainWindow->resize(1004, 836);
    QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    sizePolicy.setHorizontalStretch(0);
    sizePolicy.setVerticalStretch(0);
    sizePolicy.setHeightForWidth(mainWindow->sizePolicy().hasHeightForWidth());
    mainWindow->setSizePolicy(sizePolicy);
    mainWindow->setMinimumSize(QSize(503, 0));
    mainWindow->setIconSize(QSize(25, 25));
    actionOpen = new QAction(mainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8("../include/images/open.png")), QIcon::Normal, QIcon::On);
    actionOpen->setIcon(icon);
    actionSave = new QAction(mainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8("../include/images/save.png")), QIcon::Normal, QIcon::On);
    actionSave->setIcon(icon1);
    actionSave_As = new QAction(mainWindow);
    actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
    actionParticleSystem = new QAction(mainWindow);
    actionParticleSystem->setObjectName(QString::fromUtf8("actionParticleSystem"));
    actionProcedural_Texture = new QAction(mainWindow);
    actionProcedural_Texture->setObjectName(QString::fromUtf8("actionProcedural_Texture"));
    centralwidget = new QWidget(mainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 48, 1004, 766));
    horizontalLayout = new QHBoxLayout(centralwidget);
    horizontalLayout->setMargin(2);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(0, 0, 0, 0);
    osgwidget = new ViewerQT(centralwidget);
    osgwidget->setObjectName(QString::fromUtf8("osgwidget"));
    QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(osgwidget->sizePolicy().hasHeightForWidth());
    osgwidget->setSizePolicy(sizePolicy1);

    horizontalLayout->addWidget(osgwidget);

    color_gr = new QTabWidget(centralwidget);
    color_gr->setObjectName(QString::fromUtf8("color_gr"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(color_gr->sizePolicy().hasHeightForWidth());
    color_gr->setSizePolicy(sizePolicy2);
    color_gr->setMinimumSize(QSize(311, 0));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    tab->setGeometry(QRect(0, 0, 305, 710));
    groupBox = new QGroupBox(tab);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(20, 10, 261, 301));
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    shape_cb = new QComboBox(groupBox);
    shape_cb->setObjectName(QString::fromUtf8("shape_cb"));
    shape_cb->setAutoFillBackground(false);

    gridLayout->addWidget(shape_cb, 1, 2, 1, 2);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    life_sb = new QDoubleSpinBox(groupBox);
    life_sb->setObjectName(QString::fromUtf8("life_sb"));

    gridLayout->addWidget(life_sb, 3, 3, 1, 1);

    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout->addWidget(label_5, 4, 0, 1, 1);

    radius_sb = new QDoubleSpinBox(groupBox);
    radius_sb->setObjectName(QString::fromUtf8("radius_sb"));

    gridLayout->addWidget(radius_sb, 4, 3, 1, 1);

    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout->addWidget(label_6, 5, 0, 1, 1);

    mass_sb = new QDoubleSpinBox(groupBox);
    mass_sb->setObjectName(QString::fromUtf8("mass_sb"));

    gridLayout->addWidget(mass_sb, 5, 3, 1, 1);

    sizemax_sb = new QDoubleSpinBox(groupBox);
    sizemax_sb->setObjectName(QString::fromUtf8("sizemax_sb"));
    sizemax_sb->setDecimals(1);
    sizemax_sb->setMaximum(50);
    sizemax_sb->setSingleStep(0.1);
    sizemax_sb->setValue(5);

    gridLayout->addWidget(sizemax_sb, 2, 3, 1, 1);

    sizemin_sb = new QDoubleSpinBox(groupBox);
    sizemin_sb->setObjectName(QString::fromUtf8("sizemin_sb"));
    sizemin_sb->setDecimals(1);
    sizemin_sb->setMaximum(50);

    gridLayout->addWidget(sizemin_sb, 2, 2, 1, 1);

    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    alignment_cb = new QComboBox(groupBox);
    alignment_cb->setObjectName(QString::fromUtf8("alignment_cb"));
    alignment_cb->setAutoFillBackground(false);

    gridLayout->addWidget(alignment_cb, 0, 2, 1, 2);

    horizontalLayout_2 = new QHBoxLayout();
    horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
    label_8 = new QLabel(groupBox);
    label_8->setObjectName(QString::fromUtf8("label_8"));

    horizontalLayout_2->addWidget(label_8);

    fromcolorButton = new QToolButton(groupBox);
    fromcolorButton->setObjectName(QString::fromUtf8("fromcolorButton"));

    horizontalLayout_2->addWidget(fromcolorButton);

    label_9 = new QLabel(groupBox);
    label_9->setObjectName(QString::fromUtf8("label_9"));

    horizontalLayout_2->addWidget(label_9);

    tocolorButton = new QToolButton(groupBox);
    tocolorButton->setObjectName(QString::fromUtf8("tocolorButton"));

    horizontalLayout_2->addWidget(tocolorButton);


    gridLayout->addLayout(horizontalLayout_2, 6, 2, 1, 2);

    label_10 = new QLabel(groupBox);
    label_10->setObjectName(QString::fromUtf8("label_10"));

    gridLayout->addWidget(label_10, 6, 0, 1, 1);

    emitter_gr = new QGroupBox(tab);
    emitter_gr->setObjectName(QString::fromUtf8("emitter_gr"));
    emitter_gr->setGeometry(QRect(20, 320, 261, 331));
    placer_cb = new QComboBox(emitter_gr);
    placer_cb->setObjectName(QString::fromUtf8("placer_cb"));
    placer_cb->setGeometry(QRect(100, 30, 153, 26));
    placer_cb->setAutoFillBackground(false);
    label_7 = new QLabel(emitter_gr);
    label_7->setObjectName(QString::fromUtf8("label_7"));
    label_7->setGeometry(QRect(19, 32, 81, 20));
    radialshooter_gr = new QGroupBox(emitter_gr);
    radialshooter_gr->setObjectName(QString::fromUtf8("radialshooter_gr"));
    radialshooter_gr->setGeometry(QRect(10, 60, 241, 251));
    thetaSlider = new QScrollBar(radialshooter_gr);
    thetaSlider->setObjectName(QString::fromUtf8("thetaSlider"));
    thetaSlider->setGeometry(QRect(70, 40, 160, 16));
    thetaSlider->setOrientation(Qt::Horizontal);
    label_11 = new QLabel(radialshooter_gr);
    label_11->setObjectName(QString::fromUtf8("label_11"));
    label_11->setGeometry(QRect(10, 40, 51, 18));
    label_12 = new QLabel(radialshooter_gr);
    label_12->setObjectName(QString::fromUtf8("label_12"));
    label_12->setGeometry(QRect(10, 70, 51, 18));
    phiSlider = new QSlider(radialshooter_gr);
    phiSlider->setObjectName(QString::fromUtf8("phiSlider"));
    phiSlider->setGeometry(QRect(70, 70, 160, 16));
    phiSlider->setOrientation(Qt::Horizontal);
	phiSlider->setMaximum(50);
	phiSlider->setMinimum(0);
	phiSlider->setTickInterval(10);	
	phiSlider->setTickPosition(QSlider::TicksAbove);		
	label_13 = new QLabel(radialshooter_gr);
    label_13->setObjectName(QString::fromUtf8("label_13"));
    label_13->setGeometry(QRect(10, 100, 51, 18));
    layoutWidget_3 = new QWidget(radialshooter_gr);
    layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
    layoutWidget_3->setGeometry(QRect(20, 120, 209, 43));
    horizontalLayout_3 = new QHBoxLayout(layoutWidget_3);
    horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
    horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
    label_14 = new QLabel(layoutWidget_3);
    label_14->setObjectName(QString::fromUtf8("label_14"));

    horizontalLayout_3->addWidget(label_14);

    speedmin_sb = new QDoubleSpinBox(layoutWidget_3);
    speedmin_sb->setObjectName(QString::fromUtf8("speedmin_sb"));
    speedmin_sb->setDecimals(1);
    speedmin_sb->setMaximum(50);

    horizontalLayout_3->addWidget(speedmin_sb);

    label_15 = new QLabel(layoutWidget_3);
    label_15->setObjectName(QString::fromUtf8("label_15"));

    horizontalLayout_3->addWidget(label_15);

    speedmax_sb = new QDoubleSpinBox(layoutWidget_3);
    speedmax_sb->setObjectName(QString::fromUtf8("speedmax_sb"));
    speedmax_sb->setDecimals(1);
    speedmax_sb->setMaximum(50);
    speedmax_sb->setValue(10);

    horizontalLayout_3->addWidget(speedmax_sb);

    label_15->raise();
    label_14->raise();
    speedmin_sb->raise();
    speedmax_sb->raise();
    label_16 = new QLabel(radialshooter_gr);
    label_16->setObjectName(QString::fromUtf8("label_16"));
    label_16->setGeometry(QRect(10, 170, 51, 18));
    layoutWidget_4 = new QWidget(radialshooter_gr);
    layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
    layoutWidget_4->setGeometry(QRect(20, 190, 209, 43));
    horizontalLayout_4 = new QHBoxLayout(layoutWidget_4);
    horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
    horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
    label_17 = new QLabel(layoutWidget_4);
    label_17->setObjectName(QString::fromUtf8("label_17"));

    horizontalLayout_4->addWidget(label_17);

    countermin_sb = new QDoubleSpinBox(layoutWidget_4);
    countermin_sb->setObjectName(QString::fromUtf8("countermin_sb"));
    countermin_sb->setDecimals(1);
    countermin_sb->setMaximum(50);

    horizontalLayout_4->addWidget(countermin_sb);

    label_18 = new QLabel(layoutWidget_4);
    label_18->setObjectName(QString::fromUtf8("label_18"));

    horizontalLayout_4->addWidget(label_18);

    countermax_sb = new QDoubleSpinBox(layoutWidget_4);
    countermax_sb->setObjectName(QString::fromUtf8("countermax_sb"));
    countermax_sb->setDecimals(1);
    countermax_sb->setMaximum(300);
    countermax_sb->setValue(50);

    horizontalLayout_4->addWidget(countermax_sb);

    color_gr->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tab_2->setGeometry(QRect(0, 0, 305, 710));
    color_gr->addTab(tab_2, QString());

    horizontalLayout->addWidget(color_gr);

    mainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(mainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1004, 22));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuNew = new QMenu(menuFile);
    menuNew->setObjectName(QString::fromUtf8("menuNew"));
    mainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(mainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 814, 1004, 22));
    mainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(mainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    toolBar->setGeometry(QRect(0, 22, 106, 26));
    mainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar_2 = new QToolBar(mainWindow);
    toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
    toolBar_2->setGeometry(QRect(106, 22, 13, 26));
    mainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
    toolBar_3 = new QToolBar(mainWindow);
    toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
    toolBar_3->setGeometry(QRect(119, 22, 885, 26));
    mainWindow->addToolBar(Qt::TopToolBarArea, toolBar_3);

    menubar->addAction(menuFile->menuAction());
    menuFile->addAction(menuNew->menuAction());
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSave_As);
    menuNew->addAction(actionParticleSystem);
    toolBar->addAction(actionOpen);
    toolBar->addAction(actionSave);

    retranslateUi(mainWindow);
    QObject::connect(alignment_cb, SIGNAL(currentIndexChanged(int)), alignment_cb, SLOT(setCurrentIndex(int)));
    QObject::connect(shape_cb, SIGNAL(currentIndexChanged(int)), shape_cb, SLOT(setCurrentIndex(int)));

    color_gr->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(mainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *mainWindow)
    {
    mainWindow->setWindowTitle(QApplication::translate("mainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("mainWindow", "Open", 0, QApplication::UnicodeUTF8));
    actionSave->setText(QApplication::translate("mainWindow", "Save", 0, QApplication::UnicodeUTF8));
    actionSave_As->setText(QApplication::translate("mainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
    actionParticleSystem->setText(QApplication::translate("mainWindow", "ParticleSystem", 0, QApplication::UnicodeUTF8));
    actionProcedural_Texture->setText(QApplication::translate("mainWindow", "Procedural Texture", 0, QApplication::UnicodeUTF8));
    groupBox->setTitle(QApplication::translate("mainWindow", "Particle", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("mainWindow", "Shape:", 0, QApplication::UnicodeUTF8));
    shape_cb->insertItems(0, QStringList()
     << QApplication::translate("mainWindow", "Point", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Quad", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Quad Strip", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Hexagon", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Line", 0, QApplication::UnicodeUTF8)
    );
    label_3->setText(QApplication::translate("mainWindow", "Size:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("mainWindow", "Life:", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("mainWindow", "Radius:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("mainWindow", "Mass:", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("mainWindow", "Alignement:", 0, QApplication::UnicodeUTF8));
    alignment_cb->insertItems(0, QStringList()
     << QApplication::translate("mainWindow", "Billboard", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Fixed", 0, QApplication::UnicodeUTF8)
    );
    label_8->setText(QApplication::translate("mainWindow", "From:", 0, QApplication::UnicodeUTF8));
    fromcolorButton->setText(QApplication::translate("mainWindow", "...", 0, QApplication::UnicodeUTF8));
    label_9->setText(QApplication::translate("mainWindow", "To:", 0, QApplication::UnicodeUTF8));
    tocolorButton->setText(QApplication::translate("mainWindow", "...", 0, QApplication::UnicodeUTF8));
    label_10->setText(QApplication::translate("mainWindow", "Color", 0, QApplication::UnicodeUTF8));
    emitter_gr->setTitle(QApplication::translate("mainWindow", "Emitter", 0, QApplication::UnicodeUTF8));
    placer_cb->insertItems(0, QStringList()
     << QApplication::translate("mainWindow", "Box ", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Point", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Sector", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "MultiSegment", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Segment", 0, QApplication::UnicodeUTF8)
    );
    label_7->setText(QApplication::translate("mainWindow", "Placer", 0, QApplication::UnicodeUTF8));
    radialshooter_gr->setTitle(QApplication::translate("mainWindow", "Radial Shooter", 0, QApplication::UnicodeUTF8));
    label_11->setText(QApplication::translate("mainWindow", "Theta:", 0, QApplication::UnicodeUTF8));
    label_12->setText(QApplication::translate("mainWindow", "Phi:", 0, QApplication::UnicodeUTF8));
    label_13->setText(QApplication::translate("mainWindow", "Speed", 0, QApplication::UnicodeUTF8));
    label_14->setText(QApplication::translate("mainWindow", "From:", 0, QApplication::UnicodeUTF8));
    label_15->setText(QApplication::translate("mainWindow", "To:", 0, QApplication::UnicodeUTF8));
    label_16->setText(QApplication::translate("mainWindow", "Count", 0, QApplication::UnicodeUTF8));
    label_17->setText(QApplication::translate("mainWindow", "From:", 0, QApplication::UnicodeUTF8));
    label_18->setText(QApplication::translate("mainWindow", "To:", 0, QApplication::UnicodeUTF8));
    color_gr->setTabText(color_gr->indexOf(tab), QApplication::translate("mainWindow", "Particles", 0, QApplication::UnicodeUTF8));
    color_gr->setTabText(color_gr->indexOf(tab_2), QApplication::translate("mainWindow", "Textures", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("mainWindow", "File", 0, QApplication::UnicodeUTF8));
    menuNew->setTitle(QApplication::translate("mainWindow", "New", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("mainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    toolBar_2->setWindowTitle(QApplication::translate("mainWindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    toolBar_3->setWindowTitle(QApplication::translate("mainWindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};
 class OSGPARTI_EXPORT MainWindow: public Ui_MainWindow {};

}



#endif // MAINWINDOW_H
