#include <osgParti/PantocratorWindow.hpp>
#include <iostream>
#include <QtGui/QFileDialog>
#include <osg/View>


using namespace osgParti;


PantocratorWindow::PantocratorWindow():QMainWindow(),MainWindow()
{
 	
	setupUi(this);
	connectSlots();
	widget->addEventHandler(new osgViewer::StatsHandler); 
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

void PantocratorWindow::loadFile(const QString &fileName){
	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fileName.toStdString());
	widget->setSceneData(loadedModel.get());



}
void PantocratorWindow::connectSlots(){
  actionOpen->setShortcut(tr("Ctrl+O"));
  actionOpen->setStatusTip(tr("Open an existing file"));
  connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));

}





