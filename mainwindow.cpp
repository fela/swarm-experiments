#include "mainwindow.h"

#include "scene.h"
#include "settings.h"
#include "view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("The Swarm!");

    Settings *settings = new Settings(this);
    addDockWidget(Qt::RightDockWidgetArea, settings);


    View *view = new View(new Scene());
    connect(settings, SIGNAL(openGLToggled(bool)),
            view, SLOT(setOpenGL(bool)));
    connect(settings, SIGNAL(antialiasingToggled(bool)),
            view, SLOT(setAntialiasing(bool)));
    // initialize correctly
    view->setOpenGL(settings->openGL());
    view->setAntialiasing(settings->antialiasing());
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
