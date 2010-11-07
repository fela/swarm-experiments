#ifndef VIEW_H
#define VIEW_H

#include <QGraphicsView>

class View : public QGraphicsView
{
    Q_OBJECT
public:
    explicit View(QGraphicsScene *scene = 0);

signals:

public slots:
    void setOpenGL(bool enabled);
    void setAntialiasing(bool enabled);
};

#endif // VIEW_H
