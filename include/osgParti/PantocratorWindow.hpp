#ifndef _OSGPARTI_PANTOCRATORWINDOW_HPP_
#define _OSGPARTI_PANTOCRATORWINDOW_HPP_ 1

#include <osgParti/Export.hpp>
#include <osgParti/MainWindow.hpp>
#include <QtGui/QApplication>
#include <QtGui/QWidget>


namespace osgParti{
	
	class OSGPARTI_EXPORT PantocratorWindow: public MainWindow, public QMainWindow
	{
	public:
		PantocratorWindow():QMainWindow()
		{ setupUi(this);}
		ViewerQT* getViewerQT(){return widget;}
		virtual ~PantocratorWindow(){}
	};
	
	
	
}

#endif 