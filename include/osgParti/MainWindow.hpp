/********************************************************************************
** Form generated from reading ui file 'Pantocrator2.ui'
**
** Created: Tue Jul 22 19:37:43 2008
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
#include <QtGui/QDockWidget>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QSlider>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtGui/QGroupBox>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QComboBox>

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
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    ViewerQT *widget1;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBox;
    QLabel *label_2;
    QComboBox *comboBox_2;
    QLabel *label_3;
    QLabel *label_4;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_5;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_6;
    QDoubleSpinBox *doubleSpinBox_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QDoubleSpinBox *doubleSpinBox;
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
    centralwidget->setGeometry(QRect(0, 59, 1004, 755));
    widget = new QWidget(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(0, 10, 1001, 741));
    horizontalLayout = new QHBoxLayout(centralwidget);
    horizontalLayout->setMargin(2);
    horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
    horizontalLayout->setContentsMargins(10, 10, 10, 10);
    widget1 = new ViewerQT(widget);
    widget1->setObjectName(QString::fromUtf8("widget1"));
	centralwidget->setLayout(horizontalLayout);
	QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
    sizePolicy1.setHorizontalStretch(0);
    sizePolicy1.setVerticalStretch(0);
    sizePolicy1.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
    widget1->setSizePolicy(sizePolicy1);

    horizontalLayout->addWidget(widget1);

    tabWidget = new QTabWidget(widget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Expanding);
    sizePolicy2.setHorizontalStretch(0);
    sizePolicy2.setVerticalStretch(0);
    sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
    tabWidget->setSizePolicy(sizePolicy2);
    tabWidget->setMinimumSize(QSize(311, 0));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    tab->setGeometry(QRect(0, 0, 305, 710));
    groupBox = new QGroupBox(tab);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    groupBox->setGeometry(QRect(20, 10, 261, 241));
    gridLayout = new QGridLayout(groupBox);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label = new QLabel(groupBox);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 0, 0, 1, 1);

    comboBox = new QComboBox(groupBox);
    comboBox->setObjectName(QString::fromUtf8("comboBox"));
    comboBox->setAutoFillBackground(false);

    gridLayout->addWidget(comboBox, 0, 2, 1, 2);

    label_2 = new QLabel(groupBox);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 1, 0, 1, 1);

    comboBox_2 = new QComboBox(groupBox);
    comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
    comboBox_2->setAutoFillBackground(false);

    gridLayout->addWidget(comboBox_2, 1, 2, 1, 2);

    label_3 = new QLabel(groupBox);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 2, 0, 1, 1);

    label_4 = new QLabel(groupBox);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 3, 0, 1, 1);

    doubleSpinBox_2 = new QDoubleSpinBox(groupBox);
    doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
	doubleSpinBox_2->setDecimals(1);
    doubleSpinBox_2->setSingleStep(0.1);
	doubleSpinBox_2->setValue(10.0);

   gridLayout->addWidget(doubleSpinBox_2, 3, 3, 1, 1);

    label_5 = new QLabel(groupBox);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    gridLayout->addWidget(label_5, 4, 0, 1, 1);

    doubleSpinBox_3 = new QDoubleSpinBox(groupBox);
    doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));

    gridLayout->addWidget(doubleSpinBox_3, 4, 3, 1, 1);

    label_6 = new QLabel(groupBox);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    gridLayout->addWidget(label_6, 5, 0, 1, 1);

    doubleSpinBox_4 = new QDoubleSpinBox(groupBox);
    doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));

    gridLayout->addWidget(doubleSpinBox_4, 5, 3, 1, 1);

    doubleSpinBox_5 = new QDoubleSpinBox(groupBox);
    doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
 	doubleSpinBox_5->setDecimals(1);
    doubleSpinBox_5->setMaximum(50);
    doubleSpinBox_5->setSingleStep(0.1);
    doubleSpinBox_5->setValue(5);
   
 	gridLayout->addWidget(doubleSpinBox_5, 2, 3, 1, 1);

    doubleSpinBox = new QDoubleSpinBox(groupBox);
    doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
	doubleSpinBox->setDecimals(1);
    doubleSpinBox->setMaximum(50);
    doubleSpinBox->setSingleStep(0.1);
    gridLayout->addWidget(doubleSpinBox, 2, 2, 1, 1);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tab_2->setGeometry(QRect(0, 0, 305, 711));
    tabWidget->addTab(tab_2, QString());

    horizontalLayout->addWidget(tabWidget);

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
    toolBar->setGeometry(QRect(0, 22, 91, 37));
    mainWindow->addToolBar(Qt::TopToolBarArea, toolBar);
    toolBar_2 = new QToolBar(mainWindow);
    toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
    toolBar_2->setGeometry(QRect(91, 22, 13, 37));
    mainWindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
    toolBar_3 = new QToolBar(mainWindow);
    toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
    toolBar_3->setGeometry(QRect(104, 22, 900, 37));
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

    tabWidget->setCurrentIndex(0);


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
    label->setText(QApplication::translate("mainWindow", "Alignement:", 0, QApplication::UnicodeUTF8));
    comboBox->insertItems(0, QStringList()
     << QApplication::translate("mainWindow", "Billboard", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Fixed", 0, QApplication::UnicodeUTF8)
    );
    label_2->setText(QApplication::translate("mainWindow", "Shape:", 0, QApplication::UnicodeUTF8));
    comboBox_2->insertItems(0, QStringList()
     << QApplication::translate("mainWindow", "Point", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Quad", 0, QApplication::UnicodeUTF8)
     << QApplication::translate("mainWindow", "Quad strip", 0, QApplication::UnicodeUTF8)
 	<< QApplication::translate("mainWindow", "Hexagon", 0, QApplication::UnicodeUTF8)
	<< QApplication::translate("mainWindow", "Line", 0, QApplication::UnicodeUTF8)
    );
    label_3->setText(QApplication::translate("mainWindow", "Size:", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("mainWindow", "Life:", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("mainWindow", "Radius:", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("mainWindow", "Mass:", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("mainWindow", "Particles", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("mainWindow", "Textures", 0, QApplication::UnicodeUTF8));
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
