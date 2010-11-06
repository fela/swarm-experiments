#include "bird.h"

#include "settings.h"
#include "rand.h"

#include <QtGui/QGraphicsScene>

Bird::Bird(QGraphicsItem *parent) :
    QGraphicsRectItem(parent)
{
    _maxSpeed = Rand::randFloat(5, 30);
    _maxAcceleration = 0.3;
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

    //qreal s = Settings::BIRD_SIZE;
    //QPointF movement = Rand::randPointF(-s/2.0, s/2.0);
    //setPos(pos() + movement);

    QPointF acc = Rand::randDirection() * Rand::randFloat(_maxAcceleration);


    // some very simple code to avoid falling outside the scene
    QPointF center(Settings::SCENE_WIDTH/2.0, Settings::SCENE_HEIGHT/2.0);
    acc += (center - pos()) * 0.00005;
    accelerate(acc);

    // detect when the bird falls outside the scene
    // rects are used for improved efficiency
    if ( ! scene()->sceneRect().contains(boundingRect().translated(pos())) ) {
        scene()->removeItem(this);
        return;
    }
}

void Bird::accelerate(QPointF acc)
{
    qreal accLength = QLineF(QPointF(), acc).length();
    if ( accLength > _maxAcceleration ) {
        acc *= _maxAcceleration / accLength;
    }

    _speed += acc;
    _speed *= Settings::FRICTION;
    qreal speedLength = QLineF(QPointF(), _speed).length();
    if ( speedLength > _maxSpeed ) {
        _speed *= _maxSpeed / speedLength;
    }
    setPos(pos() += _speed);
}
