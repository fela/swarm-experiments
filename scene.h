#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>

struct SceneSettings
{
    qreal width;
    qreal heigth;
    unsigned int birds;
    unsigned int predators;
    qreal birdSize;
};

class QTimer;

class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(SceneSettings settings);
    virtual ~Scene();

signals:

public slots:

private:
    void populate(int n, int size);

private:
    static const qreal WIDTH = 700;
    static const qreal HEIGHT = 500;

    QTimer *timer;
};

#endif // SCENE_H
