#ifndef _OSGPARTI_MAINWINDOW_HPP_
#define _OSGPARTI_MAINWINDOW_HPP_ 1

#include <osgParti/AdapterWidget.hpp>
#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

namespace osgParti{

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    ViewerQT *widget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QMenu *menuParticle_System;
    QMenu *menuProcedural_Textures;
    QStatusBar *statusbar;
	ViewerQT* getViewerQT(){return widget;}
    void setupUi(QMainWindow *MainWindow)	
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    centralwidget->setGeometry(QRect(0, 22, 800, 556));
    widget = new ViewerQT(centralwidget);
    widget->setObjectName(QString::fromUtf8("widget"));
    widget->setGeometry(QRect(70, 40, 391, 311));
    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));
    pushButton->setGeometry(QRect(600, 40, 113, 32));
    pushButton_2 = new QPushButton(centralwidget);
    pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
    pushButton_2->setGeometry(QRect(600, 90, 113, 32));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 22));
    menuParticle_System = new QMenu(menubar);
    menuParticle_System->setObjectName(QString::fromUtf8("menuParticle_System"));
    menuProcedural_Textures = new QMenu(menubar);
    menuProcedural_Textures->setObjectName(QString::fromUtf8("menuProcedural_Textures"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    statusbar->setGeometry(QRect(0, 578, 800, 22));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menuParticle_System->menuAction());
    menubar->addAction(menuProcedural_Textures->menuAction());

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
    pushButton_2->setText(QApplication::translate("MainWindow", "PushButton", 0, QApplication::UnicodeUTF8));
    menuParticle_System->setTitle(QApplication::translate("MainWindow", "Particle System", 0, QApplication::UnicodeUTF8));
    menuProcedural_Textures->setTitle(QApplication::translate("MainWindow", "Procedural Textures", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class OSGPARTI_EXPORT MainWindow: public Ui_MainWindow {};
} // namespace Ui

}

#endif // UNTITLEDV22920_H
