#include "view.h"
#include "settings.h" // TODO remove

#include <QDebug>
#include <QGLWidget>

View::View(QGraphicsScene *scene) :
    QGraphicsView(scene)
{
    setFrameShape(QFrame::NoFrame);

    // copied from the tutorial, might be useful...
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    //view.setDragMode(QGraphicsView::ScrollHandDrag);
}

void View::setOpenGL(bool enabled)
{
    QWidget *w = enabled ? new QGLWidget() : new QWidget();
    setViewport(w);
}

void View::setAntialiasing(bool enabled)
{
    setRenderHint(QPainter::Antialiasing, enabled);
}
