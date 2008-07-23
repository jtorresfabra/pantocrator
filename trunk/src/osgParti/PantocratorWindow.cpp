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
	
	//osgParti::ParticleSystem* particleSystem= new ParticleSystem();
	//root->addChild(particleSystem->getPat());
    //root->addChild(particleSystem->getGroup());
	//widget1->setSceneData(root.get());
}
void PantocratorWindow::loadFile(const QString &fileName){
	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fileName.toStdString());
	widget1->setSceneData(loadedModel.get());



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





