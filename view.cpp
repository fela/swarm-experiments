#include "view.h"
#include "settings.h" // TODO remove

#include <QDebug>
#include <QGLWidget>

View::View(QGraphicsScene *scene) :
    QGraphicsView(scene)
{
    setFrameShape(QFrame::NoFrame);

    if (Settings::USE_ANTIALIASING) {
        setRenderHint(QPainter::Antialiasing);
        qDebug() << "Antialiasing enabled";
    }

    if (Settings::USE_OPENGL) {
        setViewport(new QGLWidget());
        qDebug() << "OpenGL enabled";
    }

    // copied from the tutorial, might be useful...
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
}
