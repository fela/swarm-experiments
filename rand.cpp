#include "rand.h"

#include <cstdlib> // for RAND_MAX


namespace Rand {

// random float between 0 and 1
qreal randFloat() {
    return static_cast<qreal>(qrand()) / RAND_MAX;
}

// a random point between 0 and max
qreal randFloat(qreal max) {
    return randFloat() * max;
}

// a random point between min and max
qreal randFloat(qreal min, qreal max) {
    return randFloat(max-min) + min;
}

// a random point in the rect (0, 0, max, max)
QPointF randPointF(qreal max) {
    return QPointF(randFloat(max), randFloat(max));
}

// a random point in the rect (min, min, max, max)
QPointF randPointF(qreal min, qreal max) {
    return QPointF(randFloat(min, max), randFloat(min, max));
}

// a random point in a rect
QPointF randPointF(const QRectF &r) {
    qreal x = randFloat(r.left(), r.right());
    qreal y = randFloat(r.top(), r.bottom());
    return QPointF(x, y);
}


// a random point in the rect (min.x, min.y, max.x, max.y)
//QPointF randPointF(const QPointF &min, const QPointF &max) {
//    return QPointF(randFloat(min.x(), max.x()), randFloat(min.y(), max.y()));
//}

} // namespace Rand
