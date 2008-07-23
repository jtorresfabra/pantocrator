#ifndef _OSGPARTI_PANTOCRATORWINDOW_HPP_
#define _OSGPARTI_PANTOCRATORWINDOW_HPP_ 1
#include <osg/Node>
#include <osgParti/Export.hpp>
#include <osgParti/MainWindow.hpp>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <osgParti/ParticleSystem.hpp>

//#include <QtGui/QFileDialog>


namespace osgParti{
	
	class OSGPARTI_EXPORT PantocratorWindow: public QMainWindow,public MainWindow
	{
	Q_OBJECT
	
	private slots:
		void open();
		bool save();
    	bool saveAs();
		void newParticleSystem();
	
	public:
		PantocratorWindow();
		ViewerQT* getViewerQT(){return widget1;}
		
		void connectSlots();
		void loadFile(const QString &fileName);
		osg::ref_ptr<osg::Group>                             root;
	protected:
	
		virtual ~PantocratorWindow(){}
	};
	
	
	
}
#include <osgParti/mPantocratorWindow.hpp>

#endif
 


