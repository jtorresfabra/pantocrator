#include <osgParti/PantocratorWindow.hpp>
#include <iostream>
#include <QtGui/QFileDialog>
#include <osg/View>


using namespace osgParti;


PantocratorWindow::PantocratorWindow():QMainWindow(),MainWindow()
{
 	
	setupUi(this);
	connectSlots();
	widget1->addEventHandler(new osgViewer::StatsHandler); 
	widget1->addEventHandler(new osgViewer::HelpHandler); 
	osg::ref_ptr<osgGA::StateSetManipulator> statesetManipulator = new osgGA::StateSetManipulator;
	statesetManipulator->setStateSet(widget1->getCamera()->getOrCreateStateSet());
	widget1->addEventHandler( statesetManipulator.get() );
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
	std::cout<<"pasooo";
	osgParti::ParticleSystem* particleSystem= new ParticleSystem();
	particleSystem->setMinTheta(2.0);
	particleSystem->setMaxTheta(4.0);
	particleSystem->setMaxRGB(osg::Vec4f(1.0,1.0,1.0,0.7));
	particleSystem->setMinRGB(osg::Vec4f(0.0,0.0,1.0,1.0));
	root->addChild(particleSystem->getPat());
    root->addChild(particleSystem->getGroup());
//	widget1->setSceneData(root.get());
}
void PantocratorWindow::loadFile(const QString &fileName){
	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fileName.toStdString());
	root->addChild(loadedModel.get());
	widget1->setSceneData(root.get());




}
void PantocratorWindow::connectSlots(){

//open
  actionOpen->setShortcut(tr("Ctrl+O"));
  actionOpen->setStatusTip(tr("Open an existing file"));
  connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));
//new particleSystem
	actionParticleSystem->setStatusTip(tr("New ParticleSystem defaults loaded"));
	connect(actionOpen, SIGNAL(triggered()), this, SLOT(newParticleSystem()));
}





