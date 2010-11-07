#include "scene.h"

#include "bird.h"
#include "settings.h"
#include "rand.h"

#include <QtCore/QTimer>

Scene::Scene(SceneSettings settings) : timer(0)
{
    qreal w = settings.width;
    qreal h = settings.heigth;
    setSceneRect(0, 0, w, h);
    setBackgroundBrush(Settings::SCENE_BACKGROUND);

    // add a rect as the background for the birds "arena"
    addRect(0, 0, w, h, Qt::NoPen, Settings::SCENE_COLOR);

    populate(settings.birds, settings.birdSize);

    timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), SLOT(advance()));
    timer->start(1000 / Settings::FPS);
}

Scene::~Scene()
{
    delete timer;
}

void Scene::populate(int n, int size)
{
    for (int i = 0; i < n; ++i) {
        Bird * b = new Bird(size);

        // set a random position
        b->setPos(Rand::randPointF(sceneRect()));

        addItem(b);
    }
}
