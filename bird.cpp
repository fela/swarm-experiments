#include "bird.h"

#include "settings.h"

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
    qreal dx = qrand() / static_cast<qreal>(RAND_MAX) * s - s/2.0;
    qreal dy = qrand() / static_cast<qreal>(RAND_MAX) * s - s/2.0;
    setPos(pos() + QPointF(dx, dy));
}
