#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsEllipseItem>

class Bird : public QGraphicsEllipseItem
{
public:
    explicit Bird(QGraphicsItem *parent = 0);

private:
    void advance(int phase);

    QPointF _speed;
    QPointF _maxSpeed;
    QPointF _maxAcceleration;
};

#endif // BIRD_H
