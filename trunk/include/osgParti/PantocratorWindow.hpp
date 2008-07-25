#ifndef _OSGPARTI_PANTOCRATORWINDOW_HPP_
#define _OSGPARTI_PANTOCRATORWINDOW_HPP_ 1
#define QT_NO_EMIT 

#include <osgParti/ParticleSystem.hpp>
#include <osg/Node>
#include <osgParti/Export.hpp>
#include <osgParti/MainWindow.hpp>
#include <QtGui/QApplication>
#include <QtGui/QWidget>
#include <osgGA/StateSetManipulator>

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
		void setShape(int i);

	public:
		PantocratorWindow();
		ViewerQT* getViewerQT(){return widget1;}
		
		void connectSlots();
		void loadFile(const QString &fileName);
		osg::ref_ptr<osg::Group>                             root;
	protected:
		osg::ref_ptr<osgParti::ParticleSystem> particleSystem;
		virtual ~PantocratorWindow(){}
	};
	
	
	
}
#include <osgParti/mPantocratorWindow.hpp>

#endif
 


