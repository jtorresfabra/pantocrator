#include <osgParti/PantocratorWindow.hpp>
#include <iostream>
#include <QtGui/QFileDialog>
#include <osg/View>


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
	return false;
}
bool PantocratorWindow::saveAs(){
	return false;
}
void PantocratorWindow::newParticleSystem(){
	std::cout<<"pasooo"<<std::endl;
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
void PantocratorWindow::connectSlots(){

//open
  	actionOpen->setShortcut(tr("Ctrl+O"));
  	actionOpen->setStatusTip(tr("Open an existing file"));
  	connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));
//new particleSystem
	actionParticleSystem->setStatusTip(tr("New ParticleSystem defaults loaded"));
	connect(actionParticleSystem, SIGNAL(triggered()), this, SLOT(newParticleSystem()));
//combobox
	QObject::connect(shape_cb, SIGNAL(currentIndexChanged(int)), this, SLOT(setShape(int)));
	QObject::connect(sizemin_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMinSize(double)));
	QObject::connect(sizemax_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMaxSize(double)));
	QObject::connect(life_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleLife(double)));
	QObject::connect(mass_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleMass(double)));
	QObject::connect(radius_sb, SIGNAL(valueChanged(double)), this, SLOT(setParticleRadius(double)));
	QObject::connect(fromcolorButton, SIGNAL(clicked()), this, SLOT(setFromColor()));


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
  QColor color = QColorDialog::getColor(Qt::green, this);
     //if (color.isValid()) {
       //  colorLabel->setText(color.name());
        // colorLabel->setPalette(QPalette(color));
        // colorLabel->setAutoFillBackground(true);
     }
 








