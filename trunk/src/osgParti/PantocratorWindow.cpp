#include <osgParti/PantocratorWindow.hpp>
#include <iostream>
#include <QtGui/QFileDialog>
using namespace osgParti;


PantocratorWindow::PantocratorWindow():QMainWindow(),MainWindow()
{
 	
	setupUi(this);
	connectSlots();
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
	std::cout<<"holaa"<<std::endl;
	osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFile(fileName.toStdString());
	widget->setSceneData(loadedModel.get());



}
void PantocratorWindow::connectSlots(){
  actionOpen->setShortcut(tr("Ctrl+O"));
  actionOpen->setStatusTip(tr("Open an existing file"));
  connect(actionOpen, SIGNAL(triggered()), this, SLOT(open()));

}





