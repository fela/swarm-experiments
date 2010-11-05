#include "mainwindow.h"

#include "scene.h"
#include "settings.h"

#include <QtCore/QDebug>
#include <QtGui/QGraphicsView>
#include <QtOpenGL/QGLWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QGraphicsView *view = new QGraphicsView(new Scene());

    view->setFrameShape(QFrame::NoFrame);

    if (Settings::USE_ANTIALIASING) {
        view->setRenderHint(QPainter::Antialiasing);
        qDebug() << "Antialiasing enabled\n";
    }

    if (Settings::USE_OPENGL) {
        view->setViewport(new QGLWidget());
        qDebug() << "OpenGL enabled\n";
    }

    // copied from the internet, might be useful...
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);

    setWindowTitle("The Swarm!");
    setCentralWidget(view);
}

MainWindow::~MainWindow()
{

}
