#ifndef BIRD_H
#define BIRD_H

#include <QGraphicsEllipseItem>

class Bird : public QGraphicsEllipseItem
{
public:
    explicit Bird(QGraphicsItem *parent = 0);

private:
    void advance(int phase);
};

#endif // BIRD_H
