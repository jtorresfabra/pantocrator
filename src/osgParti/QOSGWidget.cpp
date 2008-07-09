#include <osgParti/QOSGWidget.hpp>

QOSGWidget::QOSGWidget( QWidget * parent, const char * name, WindowFlags f):
#if USE_QT4
    QWidget(parent, f)
#else
    QWidget(parent, name, f)
#endif
{
    createContext();
    

#if USE_QT4
    setAttribute(Qt::WA_PaintOnScreen);
    setAttribute(Qt::WA_NoSystemBackground);
#else
    setBackgroundMode(Qt::NoBackground);
#endif    
}

void QOSGWidget::createContext()
{
    osg::DisplaySettings* ds = osg::DisplaySettings::instance();

    osg::ref_ptr<osg::GraphicsContext::Traits> traits = new osg::GraphicsContext::Traits;

    traits->readDISPLAY();
    if (traits->displayNum<0) traits->displayNum = 0;

    traits->windowName = "osgViewerQt";
    traits->screenNum = 0;
    traits->x = x();
    traits->y = y();
    traits->width = width();
    traits->height = height();
    traits->alpha = ds->getMinimumNumAlphaBits();
    traits->stencil = ds->getMinimumNumStencilBits();
    traits->windowDecoration = false;
    traits->doubleBuffer = true;
    traits->sharedContext = 0;
    traits->sampleBuffers = ds->getMultiSamples();
    traits->samples = ds->getNumMultiSamples();

    traits->inheritedWindowData = new WindowData(winId());

    if (ds->getStereo())
    {
        switch(ds->getStereoMode())
        {
            case(osg::DisplaySettings::QUAD_BUFFER): traits->quadBufferStereo = true; break;
            case(osg::DisplaySettings::VERTICAL_INTERLACE):
            case(osg::DisplaySettings::CHECKERBOARD):
            case(osg::DisplaySettings::HORIZONTAL_INTERLACE): traits->stencil = 8; break;
            default: break;
        }
    }

    osg::ref_ptr<osg::GraphicsContext> gc = osg::GraphicsContext::createGraphicsContext(traits.get());
    _gw = dynamic_cast<osgViewer::GraphicsWindow*>(gc.get());
}
void QOSGWidget::destroyEvent(bool destroyWindow, bool destroySubWindows)
{   
    _gw->getEventQueue()->closeWindow();
}


void QOSGWidget::closeEvent( QCloseEvent * event )
{
#ifndef USE_QT4
    event->accept();
#endif

    _gw->getEventQueue()->closeWindow();
}


void QOSGWidget::resizeEvent( QResizeEvent * event )
{
    const QSize & size = event->size();
    _gw->getEventQueue()->windowResize(0, 0, size.width(), size.height() );
    _gw->resized(0, 0, size.width(), size.height());
}

void QOSGWidget::keyPressEvent( QKeyEvent* event )
{
#if USE_QT4
    _gw->getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) *(event->text().toAscii().data() ) );
#else
    _gw->getEventQueue()->keyPress( (osgGA::GUIEventAdapter::KeySymbol) event->ascii() );
#endif
}

void QOSGWidget::keyReleaseEvent( QKeyEvent* event )
{
#if USE_QT4
    int c = *event->text().toAscii().data();
#else
    int c = event->ascii();
#endif

    _gw->getEventQueue()->keyRelease( (osgGA::GUIEventAdapter::KeySymbol) (c) );
}

void QOSGWidget::mousePressEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseButtonPress(event->x(), event->y(), button);
}
void QOSGWidget::mouseDoubleClickEvent ( QMouseEvent * event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseDoubleButtonPress(event->x(), event->y(), button);
}
void QOSGWidget::mouseReleaseEvent( QMouseEvent* event )
{
    int button = 0;
    switch(event->button())
    {
        case(Qt::LeftButton): button = 1; break;
        case(Qt::MidButton): button = 2; break;
        case(Qt::RightButton): button = 3; break;
        case(Qt::NoButton): button = 0; break;
        default: button = 0; break;
    }
    _gw->getEventQueue()->mouseButtonRelease(event->x(), event->y(), button);
}

void QOSGWidget::mouseMoveEvent( QMouseEvent* event )
{
    _gw->getEventQueue()->mouseMotion(event->x(), event->y());
}








class ViewerQOSG : public osgViewer::Viewer, public QOSGWidget
{
    public:

        ViewerQOSG(QWidget * parent = 0, const char * name = 0, WindowFlags f = 0):
            QOSGWidget( parent, name, f )
        {
            getCamera()->setViewport(new osg::Viewport(0,0,width(),height()));
            getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(width())/static_cast<double>(height()), 1.0f, 10000.0f);
            getCamera()->setGraphicsContext(getGraphicsWindow());

            setThreadingModel(osgViewer::Viewer::SingleThreaded);

        connect(&_timer, SIGNAL(timeout()), this, SLOT(update()));
            _timer.start(10);
    }

        virtual void paintEvent( QPaintEvent * event ) { frame(); }

    protected:

        QTimer _timer;
};



class CompositeViewerQOSG : public osgViewer::CompositeViewer, public QOSGWidget
{
    public:

        CompositeViewerQOSG(QWidget * parent = 0, const char * name = 0, WindowFlags f = 0):
            QOSGWidget( parent, name, f )
        {
            setThreadingModel(osgViewer::CompositeViewer::SingleThreaded);

            connect(&_timer, SIGNAL(timeout()), this, SLOT(repaint()));
            _timer.start(1);
        }

        virtual void paintEvent( QPaintEvent * event ) { frame(); }

    protected:

        QTimer _timer;
};


void setupManipulatorAndHandler(osgViewer::View & viewer, osg::ArgumentParser & arguments)
{
    // set up the camera manipulators.
    {
        osg::ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;

        keyswitchManipulator->addMatrixManipulator( '1', "Trackball", new osgGA::TrackballManipulator() );
        keyswitchManipulator->addMatrixManipulator( '2', "Flight", new osgGA::FlightManipulator() );
        keyswitchManipulator->addMatrixManipulator( '3', "Drive", new osgGA::DriveManipulator() );
        keyswitchManipulator->addMatrixManipulator( '4', "Terrain", new osgGA::TerrainManipulator() );

        viewer.setCameraManipulator( keyswitchManipulator.get() );
    }

    // add the state manipulator
    viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );
    
    // add the thread model handler
    viewer.addEventHandler(new osgViewer::ThreadingHandler);

    // add the window size toggle handler
    viewer.addEventHandler(new osgViewer::WindowSizeHandler);
        
    // add the stats handler
    viewer.addEventHandler(new osgViewer::StatsHandler);

    // add the help handler
    viewer.addEventHandler(new osgViewer::HelpHandler(arguments.getApplicationUsage()));
}

int mainQOSGWidget(QApplication& a, osg::ArgumentParser& arguments)
{
    // load the scene.
    osg::ref_ptr<osg::Node> loadedModel = osgDB::readNodeFiles(arguments);
    if (!loadedModel)
    {
        std::cout << arguments[0] <<": No data loaded." << std::endl;
        return 1;
    }

    std::cout<<"Using QOSGWidget - QWidget + osgViewer creating the graphics context."<<std::endl;
    
    
    if (arguments.read("--CompositeViewer"))
    {
        osg::ref_ptr<CompositeViewerQOSG> viewerWindow(new CompositeViewerQOSG);
        viewerWindow->setGeometry(0,0,640,480);
        
        unsigned int width = viewerWindow->width();
        unsigned int height = viewerWindow->height();

        {
            osgViewer::View* view1 = new osgViewer::View;
            view1->getCamera()->setGraphicsContext(viewerWindow->getGraphicsWindow());
            view1->getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(width)/static_cast<double>(height/2), 1.0, 1000.0);
            view1->getCamera()->setViewport(new osg::Viewport(0,0,width,height/2));
            view1->setSceneData(loadedModel.get());

            setupManipulatorAndHandler(*view1, arguments);

            viewerWindow->addView(view1);
        }

        {
            osgViewer::View* view2 = new osgViewer::View;
            view2->getCamera()->setGraphicsContext(viewerWindow->getGraphicsWindow());
            view2->getCamera()->setProjectionMatrixAsPerspective(30.0f, static_cast<double>(width)/static_cast<double>(height/2), 1.0, 1000.0);
            view2->getCamera()->setViewport(new osg::Viewport(0,height/2,width,height/2));
            view2->setSceneData(loadedModel.get());

            setupManipulatorAndHandler(*view2, arguments);

            viewerWindow->addView(view2);
        }

        viewerWindow->show();

        a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );

        return a.exec();
    }
    else
    {
        osg::ref_ptr<ViewerQOSG> viewerWindow(new ViewerQOSG);
        viewerWindow->setGeometry(0,0,640,480);
        
        viewerWindow->setCameraManipulator(new osgGA::TrackballManipulator);
        viewerWindow->setSceneData(loadedModel.get());

        viewerWindow->show();

        setupManipulatorAndHandler(*viewerWindow.get(), arguments);
        
        a.connect( &a, SIGNAL(lastWindowClosed()), &a, SLOT(quit()) );
    
        return a.exec();
    }
}
