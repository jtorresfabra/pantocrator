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
#include <osgDB/WriteFile>



namespace osgParti{
	
	class OSGPARTI_EXPORT PantocratorWindow: public QMainWindow,public MainWindow
	{
	Q_OBJECT
	
	private slots:
		void open();
		bool save();
    	bool saveAs();
		void newParticleSystem();
		void newFile();
		void setParticleAlignment(int);
		void setShape(int i);
		void setParticleMinSize(double minsize);
		void setParticleMaxSize(double maxsize);
		void setParticleLife(double life);
		void setParticleMass(double mass);
		void setParticleRadius(double radius);
		void setFromColor();
		void setToColor();
		void setParticleMinTheta(double theta);
		void setParticleMaxTheta(double theta);
		void setParticleMinPhi(double phi);
		void setParticleMaxPhi(double phi);
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
		void setParticleAcceleration(int enabled);
		void setParticleFluid(int enabled);
		void setParticleAccelerationX(double x);
		void setParticleAccelerationY(double y);
		void setParticleAccelerationZ(double z);
		void setParticleFluidViscosity(double viscosity);
		void setParticleFluidDensity(double density);

	public:
		PantocratorWindow();
		ViewerQT* getViewerQT(){return osgwidget;}
		
		void connectSlots();
		void loadFile(const QString &fileName);
		void saveFile(const QString &fileName);
		void setParticleProgram(osgParticle::Operator *op);
		osg::ref_ptr<osgParticle::ModularProgram>         program;
		osg::ref_ptr<osgParticle::AccelOperator>      acceleration;
		osg::ref_ptr<osgParticle::FluidFrictionOperator>     fluid;
		osg::ref_ptr<osg::Group>                             root;
		osg::Vec3											 accel;
	
	protected:
		osg::ref_ptr<osgParti::ParticleSystem> particleSystem;
		virtual ~PantocratorWindow(){}
	};
	
	
	
}
#include <osgParti/mPantocratorWindow.hpp>

#endif
 


