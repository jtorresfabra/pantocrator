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
#include <QtGui/QColorDialog>



namespace osgParti{
	
	class OSGPARTI_EXPORT PantocratorWindow: public QMainWindow,public MainWindow
	{
	Q_OBJECT
	
	private slots:
		void open();
		bool save();
    	bool saveAs();
		void newParticleSystem();
		void setParticleAlignment(int);
		void setShape(int i);
		void setParticleMinSize(double minsize);
		void setParticleMaxSize(double maxsize);
		void setParticleLife(double life);
		void setParticleMass(double mass);
		void setParticleRadius(double radius);
		void setFromColor();
		void setToColor();
		void setParticleTheta(int theta);
		void setParticleMinSpeed(double minspeed);
		void setParticleMaxSpeed(double maxspeed);
		void setParticleMinCount(double mincount);
		void setParticleMaxCount(double maxcount);
		void setParticlePlacer(int placer);
		void setParticleTextureFire();
		void setParticleTextureSmoke();
		void setParticleTextureBase();
		void setParticleTextureSonic();
		void setParticleTextureVirulent();
		void setParticleTextureLaser();
		void setParticleTextureElectric();
		void setParticleTextureIce();
		void setParticleTextureEmp();
		void setParticleTextureFlower();


	public:
		PantocratorWindow();
		ViewerQT* getViewerQT(){return osgwidget;}
		
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
 


