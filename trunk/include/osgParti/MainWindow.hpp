/********************************************************************************
** Form generated from reading ui file 'Pantocrator.ui'
**
** Created: Tue Jul 15 17:43:48 2008
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
    ViewerQT *widget;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;
    QLabel *label_3;
    QSlider *horizontalSlider_3;
    QLabel *label_6;
    QSlider *horizontalSlider_5;
    QLabel *label_5;
    QSlider *horizontalSlider_6;
    QLabel *label_4;
    QSlider *horizontalSlider_4;
    QWidget *tab_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuNew;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(1041, 786);
    MainWindow->setIconSize(QSize(25, 25));
    actionOpen = new QAction(MainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    QIcon icon;
    icon.addPixmap(QPixmap(QString::fromUtf8("../include/images/open.png")), QIcon::Normal, QIcon::On);
    actionOpen->setIcon(icon);
    actionSave = new QAction(MainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    QIcon icon1;
    icon1.addPixmap(QPixmap(QString::fromUtf8("../include/images/save.png")), QIcon::Normal, QIcon::On);
    actionSave->setIcon(icon1);
    actionSave_As = new QAction(MainWindow);
    actionSave_As->setObjectName(QString::fromUtf8("actionSave_As"));
    actionParticleSystem = new QAction(MainWindow);
    actionParticleSystem->setObjectName(QString::fromUtf8("actionParticleSystem"));
    actionProcedural_Texture = new QAction(MainWindow);
    actionProcedural_Texture->setObjectName(QString::fromUtf8("actionProcedural_Texture"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 59, 1041, 705));
    widget = new ViewerQT(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(30, 10, 751, 661));
    dockWidget = new QDockWidget(centralwidget);
    dockWidget->setObjectName(QString::fromUtf8("dockWidget"));
    dockWidget->setGeometry(QRect(785, 0, 231, 641));
    dockWidgetContents = new QWidget();
    dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
    dockWidgetContents->setGeometry(QRect(0, 26, 231, 615));
    tabWidget = new QTabWidget(dockWidgetContents);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tabWidget->setGeometry(QRect(31, 20, 181, 431));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    tab->setGeometry(QRect(0, 0, 175, 402));
    layoutWidget = new QWidget(tab);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    layoutWidget->setGeometry(QRect(20, 20, 141, 350));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    label = new QLabel(layoutWidget);
    label->setObjectName(QString::fromUtf8("label"));

    verticalLayout->addWidget(label);

    horizontalSlider = new QSlider(layoutWidget);
    horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
    horizontalSlider->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(horizontalSlider);

    label_2 = new QLabel(layoutWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    verticalLayout->addWidget(label_2);

    horizontalSlider_2 = new QSlider(layoutWidget);
    horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
    horizontalSlider_2->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(horizontalSlider_2);

    label_3 = new QLabel(layoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    verticalLayout->addWidget(label_3);

    horizontalSlider_3 = new QSlider(layoutWidget);
    horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
    horizontalSlider_3->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(horizontalSlider_3);

    label_6 = new QLabel(layoutWidget);
    label_6->setObjectName(QString::fromUtf8("label_6"));

    verticalLayout->addWidget(label_6);

    horizontalSlider_5 = new QSlider(layoutWidget);
    horizontalSlider_5->setObjectName(QString::fromUtf8("horizontalSlider_5"));
    horizontalSlider_5->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(horizontalSlider_5);

    label_5 = new QLabel(layoutWidget);
    label_5->setObjectName(QString::fromUtf8("label_5"));

    verticalLayout->addWidget(label_5);

    horizontalSlider_6 = new QSlider(layoutWidget);
    horizontalSlider_6->setObjectName(QString::fromUtf8("horizontalSlider_6"));
    horizontalSlider_6->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(horizontalSlider_6);

    label_4 = new QLabel(layoutWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    verticalLayout->addWidget(label_4);

    horizontalSlider_4 = new QSlider(layoutWidget);
    horizontalSlider_4->setObjectName(QString::fromUtf8("horizontalSlider_4"));
    horizontalSlider_4->setOrientation(Qt::Horizontal);

    verticalLayout->addWidget(horizontalSlider_4);

    label->raise();
    horizontalSlider->raise();
    label_2->raise();
    horizontalSlider_2->raise();
    label_6->raise();
    horizontalSlider_5->raise();
    label_5->raise();
    horizontalSlider_6->raise();
    label_4->raise();
    horizontalSlider_4->raise();
    label_3->raise();
    horizontalSlider_3->raise();
    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    tab_2->setGeometry(QRect(0, 0, 175, 402));
    tabWidget->addTab(tab_2, QString());
    dockWidget->setWidget(dockWidgetContents);
    MainWindow->setCentralWidget(centralwidget);
    dockWidget->raise();
    tabWidget->raise();
    horizontalSlider->raise();
    tabWidget->raise();
    widget->raise();
    dockWidget->raise();
    label_2->raise();
    layoutWidget->raise();
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 1041, 22));
    menuFile = new QMenu(menubar);
    menuFile->setObjectName(QString::fromUtf8("menuFile"));
    menuNew = new QMenu(menuFile);
    menuNew->setObjectName(QString::fromUtf8("menuNew"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 764, 1041, 22));
    MainWindow->setStatusBar(statusbar);
    toolBar = new QToolBar(MainWindow);
    toolBar->setObjectName(QString::fromUtf8("toolBar"));
    MainWindow->addToolBar(Qt::TopToolBarArea, toolBar);

    menubar->addAction(menuFile->menuAction());
    menuFile->addAction(menuNew->menuAction());
    menuFile->addAction(actionOpen);
    menuFile->addAction(actionSave);
    menuFile->addAction(actionSave_As);
    menuNew->addAction(actionParticleSystem);
    menuNew->addAction(actionProcedural_Texture);
    toolBar->addAction(actionOpen);
    toolBar->addAction(actionSave);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
    actionSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
    actionSave_As->setText(QApplication::translate("MainWindow", "Save As...", 0, QApplication::UnicodeUTF8));
    actionParticleSystem->setText(QApplication::translate("MainWindow", "ParticleSystem", 0, QApplication::UnicodeUTF8));
    actionProcedural_Texture->setText(QApplication::translate("MainWindow", "Procedural Texture", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    label_6->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    label_5->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindow", "TextLabel", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
    menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
    menuNew->setTitle(QApplication::translate("MainWindow", "New", 0, QApplication::UnicodeUTF8));
    toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};


    class OSGPARTI_EXPORT MainWindow: public Ui_MainWindow {};
 // namespace Ui

}

#endif // MAINWINDOW_H
