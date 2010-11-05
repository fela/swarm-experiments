#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>


class QTimer;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject *parent = 0);
    virtual ~Scene();

signals:

public slots:

private:
    void populate(int n);

private:
    static const qreal WIDTH = 700;
    static const qreal HEIGHT = 500;

    QTimer *timer;
};

#endif // SCENE_H
