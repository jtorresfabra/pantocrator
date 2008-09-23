#include <osgParti/PantocratorWindow.hpp>
#include <iostream>
#include <QtGui/QFileDialog>
#include <osg/View>
#include <osgParticle/PointPlacer>

using namespace osgParti;


PantocratorWindow::PantocratorWindow():QMainWindow(),MainWindow()
{
 	
	setupUi(this);
	connectSlots();
	osgwidget->addEventHandler(new osgViewer::StatsHandler); 
	osgwidget->addEventHandler(new osgViewer::HelpHandler); 
	osg::ref_ptr<osgGA::StateSetManipulator> statesetManipulator = new osgGA::StateSetManipulator;
	statesetManipulator->setStateSet(osgwidget->getCamera()->getOrCreateStateSet());
	osgwidget->addEventHandler( statesetManipulator.get() );
	root= new osg::Group();
 
}
void PantocratorWindow::open(){
	QString fileName = QFileDialog::getOpenFileName(this);
	if (!fileName.isEmpty())
         loadFile(fileName);
}
bool PantocratorWindow::save(){
	QString fileName = QFileDialog::getSaveFileName(this, "Save file", "", ".osg") ;
	if (!fileName.isEmpty())
         saveFile(fileName);


}
bool PantocratorWindow::saveAs(){
	return false;
}
void PantocratorWindow::newParticleSystem(){
	particleSystem= new ParticleSystem();
//	particleSystem->setMinTheta(2.0);
//	particleSystem->setMaxTheta(4.0);
//	particleSystem->setMaxRGB(osg::Vec4f(1.0,1.0,1.0,0.7));
//	particleSystem->setMinRGB(osg::Vec4f(0.0,0.0,1.0,1.0));
	root->addChild(particleSystem->getPat());
   	root->addChild(particleSystem->getGroup());
	osgwidget->setSceneData(root.get());
}
void PantocratorWindow::loadFile(const QString &fileName){

	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fileName.toStdString());
	root->addChild(loadedModel.get());
	osgwidget->setSceneData(root.get());
}
void PantocratorWindow::saveFile(const QString &fileName){
	osg::Node *node = ((osg::Node*)root.get());
	osgDB::writeNodeFile(*node,fileName.toStdString());
}
void PantocratorWindow::connectSlots(){

//open
  	actionOpen->setShortcut(tr("Ctrl+O"));
  	actionOpen->setStatusTip(tr("Open an existing file"));
  	connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));
//save
	actionSave->setShortcut(tr("Ctrl+O"));
	actionOpen->setStatusTip(tr("Save scene"));
	connect(actionSave, SIGNAL(triggered()), this, SLOT(save()));

//new particleSystem
	actionParticleSystem->setStatusTip(tr("New ParticleSystem defaults loaded"));
	connect(actionParticleSystem, SIGNAL(triggered()), this, SLOT(newParticleSystem()));
//combobox
	QObject::connect(alignment_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(setParticleAlignment(int)));
	QObject::connect(shape_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(setShape(int)));
	QObject::connect(sizemin_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMinSize(double)));
	QObject::connect(sizemax_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMaxSize(double)));
	QObject::connect(life_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleLife(double)));
	QObject::connect(mass_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMass(double)));
	QObject::connect(radius_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleRadius(double)));
	QObject::connect(fromcolorButton, SIGNAL(clicked()), this, SLOT(setFromColor()));
	QObject::connect(tocolorButton, SIGNAL(clicked()), this, SLOT(setToColor()));
	QObject::connect(thetamin_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMinTheta(double)));
	QObject::connect(thetamax_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMaxTheta(double)));
	QObject::connect(phimin_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMinTheta(double)));
	QObject::connect(phimax_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMaxTheta(double)));

	QObject::connect(speedmin_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMinSpeed(double)));
	QObject::connect(speedmax_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMaxSpeed(double)));
	QObject::connect(countermin_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMinCount(double)));
	QObject::connect(countermax_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMaxCount(double)));
	QObject::connect(placer_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(setParticlePlacer(int)));
//Textures
	QObject::connect(toolButton, SIGNAL(clicked()),this,SLOT(setParticleTextureSmoke()));
	QObject::connect(toolButton_2, SIGNAL(clicked()),this,SLOT(setParticleTextureFire()));
	QObject::connect(toolButton_4, SIGNAL(clicked()),this,SLOT(setParticleTextureBase()));
	QObject::connect(toolButton_9, SIGNAL(clicked()),this,SLOT(setParticleTextureSonic()));
	QObject::connect(toolButton_10, SIGNAL(clicked()),this,SLOT(setParticleTextureVirulent()));
	QObject::connect(toolButton_8, SIGNAL(clicked()),this,SLOT(setParticleTextureLaser()));
	QObject::connect(toolButton_6, SIGNAL(clicked()),this,SLOT(setParticleTextureElectric()));
	QObject::connect(toolButton_5, SIGNAL(clicked()),this,SLOT(setParticleTextureIce()));
	QObject::connect(toolButton_3, SIGNAL(clicked()),this,SLOT(setParticleTextureFlower()));
	QObject::connect(toolButton_7, SIGNAL(clicked()),this,SLOT(setParticleTextureEmp()));

}
void PantocratorWindow::setParticleAlignment(int i){
	if (particleSystem!=NULL)
		if (i==1)particleSystem->setAlignmentFixed();
		else particleSystem->setAlignmentBillboard();
}
void PantocratorWindow::setShape(int i){
	if (particleSystem!=NULL)particleSystem->setShape(i);
}
void PantocratorWindow::setParticleMinSize(double minsize){
	if (particleSystem!=NULL)particleSystem->setMinSize(minsize);
}
void PantocratorWindow::setParticleMaxSize(double maxsize){
	if (particleSystem!=NULL)particleSystem->setMaxSize(maxsize);	
}
void PantocratorWindow::setParticleLife(double life){
	if (particleSystem!=NULL)particleSystem->setLifeTime(life);
}
void PantocratorWindow::setParticleMass(double mass){
	if (particleSystem!=NULL)particleSystem->setMass(mass);
}
void PantocratorWindow::setParticleRadius(double radius){
	if (particleSystem!=NULL)particleSystem->setRadius(radius);
}
void PantocratorWindow::setFromColor(){
 	if (particleSystem!=NULL){
	QColor color = QColorDialog::getRgba();
	particleSystem->setMinRGB(osg::Vec4f (color.redF(),color.greenF(),color.blueF(),color.alphaF()));
    } 
}
void PantocratorWindow::setToColor(){
 	if (particleSystem!=NULL){
	QColor color = QColorDialog::getRgba();
	particleSystem->setMaxRGB(osg::Vec4f (color.redF(),color.greenF(),color.blueF(),color.alphaF()));
    } 
}
void PantocratorWindow::setParticleMinTheta(double theta){
	if (particleSystem!=NULL)particleSystem->setMinTheta((float)(theta));
}
void PantocratorWindow::setParticleMaxTheta(double theta){
	if (particleSystem!=NULL)particleSystem->setMaxTheta((float)(theta));
}
void PantocratorWindow::setParticleMinPhi(double phi){
	if (particleSystem!=NULL)particleSystem->setMinPhi((float)(phi));
}
void PantocratorWindow::setParticleMaxPhi(double phi){
	if (particleSystem!=NULL)particleSystem->setMaxPhi((float)(phi));
}
void PantocratorWindow::setParticleMinSpeed(double minspeed){
	if (particleSystem!=NULL)particleSystem->setMinSpeed(minspeed);
}
void PantocratorWindow::setParticleMaxSpeed(double maxspeed){
	if (particleSystem!=NULL)particleSystem->setMaxSpeed(maxspeed);
}
void PantocratorWindow::setParticleMinCount(double mincount){
	if (particleSystem!=NULL)particleSystem->setMinRate(mincount);
}
void PantocratorWindow::setParticleMaxCount(double maxcount){
	if (particleSystem!=NULL)particleSystem->setMaxRate(maxcount);
}
void PantocratorWindow::setParticlePlacer(int placer){
		if (particleSystem!=NULL)
			switch(placer){
				case 0:
				particleSystem->setPlacer(new osgParticle::PointPlacer());
				break;
				case 1:
				particleSystem->setPlacer(new osgParticle::BoxPlacer());
				break;
		}
	}
void PantocratorWindow::setParticleTextureFire(){
	if (particleSystem!=NULL){
		particleSystem->setTexture("../include/images/flame3.png");
	}
}
void PantocratorWindow::setParticleTextureSmoke(){
		if (particleSystem!=NULL){
			particleSystem->setTexture("../include/images/smoke.png");
		}
}		
void PantocratorWindow::setParticleTextureBase(){
		if (particleSystem!=NULL){
			particleSystem->setTexture("../include/images/partbase.png");
		}
}
void PantocratorWindow::setParticleTextureSonic(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/Sonic.png");
			}
}
void PantocratorWindow::setParticleTextureVirulent(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/Virulent.png");
			}
}
void PantocratorWindow::setParticleTextureLaser(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/Laser.png");
			}
}
void PantocratorWindow::setParticleTextureElectric(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/Electric.png");
			}
}
void PantocratorWindow::setParticleTextureIce(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/Ice.png");
			}
}
void PantocratorWindow::setParticleTextureEmp(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/Emp.png");
			}
}
void PantocratorWindow::setParticleTextureFlower(){
		if (particleSystem!=NULL){
				particleSystem->setTexture("../include/images/FlowerBurst.jpg");
			}
}
	
	

