#ifndef _OSGPARTI_PANTOCRATORWINDOW_HPP_
#define _OSGPARTI_PANTOCRATORWINDOW_HPP_ 1
#include <osg/Node>
#include <osgParti/Export.hpp>
#include <osgParti/MainWindow.hpp>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
//#include <QtGui/QFileDialog>


namespace osgParti{
	
	class OSGPARTI_EXPORT PantocratorWindow: public QMainWindow,public MainWindow
	{
	Q_OBJECT
	
	private slots:
		void open();
		bool save();
    		bool saveAs();

	
	public:
		PantocratorWindow();
		ViewerQT* getViewerQT(){return widget;}
		virtual ~PantocratorWindow(){}
		void connectSlots();
		void loadFile(const QString &fileName);

	};
	
	
	
}
#include <osgParti/mPantocratorWindow.hpp>

#endif
 


