#include "view.h"
#include "settings.h" // TODO remove

#include <QDebug>
#include <QGLWidget>

View::View(QGraphicsScene *scene) :
        QGraphicsView(scene), current_zoom(1)
{
    setFrameShape(QFrame::NoFrame);

    // copied from the tutorial, might be useful...
    //view.setCacheMode(QGraphicsView::CacheBackground);
    //view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    setDragMode(QGraphicsView::ScrollHandDrag);
}

View::~View()
{
    delete scene();
}

void View::setScene(QGraphicsScene *newScene)
{
    delete scene();
    QGraphicsView::setScene(newScene);
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

void View::setZoom(qreal zoom)
{
    qreal zoom_by = zoom/current_zoom;
    scale(zoom_by, zoom_by);
    current_zoom = zoom;
}
