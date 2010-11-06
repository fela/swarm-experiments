#include "scene.h"

#include "bird.h"
#include "settings.h"
#include "rand.h"

#include <QtCore/QTimer>

Scene::Scene(QObject *parent) :
    QGraphicsScene(parent), timer(0)
{
    qreal w = Settings::SCENE_WIDTH;
    qreal h = Settings::SCENE_HEIGHT;
    setSceneRect(0, 0, w, h);
    setBackgroundBrush(Settings::SCENE_BACKGROUND);

    // add a rect as the background for the birds "arena"
    addRect(0, 0, w, h, Qt::NoPen, Settings::SCENE_COLOR);

    populate(Settings::INITIAL_POPULATION);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), SLOT(advance()));
    timer->start(1000 / Settings::FPS);
}

Scene::~Scene()
{
    delete timer;
}

void Scene::populate(int n)
{
    for (int i = 0; i < n; ++i) {
        Bird * b = new Bird();

        // set a random position
        b->setPos(Rand::randPointF(sceneRect()));

        addItem(b);
    }
}
