#ifndef RAND_H
#define RAND_H

#include <QtCore/QPointF>
#include <QtCore/QRectF>

namespace Rand {

// random float between 0 and 1
qreal randFloat();

// a random point between 0 and max
qreal randFloat(qreal max);

// a random point between min and max
qreal randFloat(qreal min, qreal max);

// a random point in the rect (0, 0, max, max)
QPointF randPointF(qreal max);

// a random point in the rect (min, min, max, max)
QPointF randPointF(qreal min, qreal max);

// a random point in a rect
QPointF randPointF(const QRectF &r);

// a random direction
QPointF randDirection();


// a random point in the rect (min.x, min.y, max.x, max.y)
//QPointF randPointF(const QPointF &min, const QPointF &max) {
//    return QPointF(randFloat(min.x(), max.x()), randFloat(min.y(), max.y()));
//}

} // namespace Rand

#endif // RAND_H
