#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsRectItem>

class Bird : public QGraphicsRectItem
{
public:
    explicit Bird(int size);

private:
    void advance(int phase);
    void accelerate(QPointF acc);

    QPointF _speed;
    qreal _maxSpeed;
    qreal _maxAcceleration;
};

#endif // BIRD_H
