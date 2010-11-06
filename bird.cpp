#include "bird.h"

#include "settings.h"
#include "rand.h"

#include <QtGui/QGraphicsScene>

Bird::Bird(QGraphicsItem *parent) :
    QGraphicsEllipseItem(parent)
{
    qreal s = Settings::BIRD_SIZE;
    setRect(-s/2.0, -s/2.0, s, s);
    setPen(Qt::NoPen);
    setBrush(Qt::red);
}

void Bird::advance(int phase)
{
    if (phase == 0) {
        // do nothing
        return;
    }

    qreal s = Settings::BIRD_SIZE;
    QPointF movement = Rand::randPointF(-s/2.0, s/2.0);
    setPos(pos() + movement);

    // detect when the bird falls outside the scene
    // rects are used for improved efficiency
    if ( ! scene()->sceneRect().contains(boundingRect().translated(pos())) ) {
        scene()->removeItem(this);
        return;
    }
}
