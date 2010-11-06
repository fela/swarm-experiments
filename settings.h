#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore/QtGlobal>
#include <QtGui/QColor>

#include <cmath>

namespace Settings {

// scene
const qreal SCENE_HEIGHT = 500;
const qreal SCENE_WIDTH = 700;
const Qt::GlobalColor SCENE_COLOR = Qt::black;
const Qt::GlobalColor SCENE_BACKGROUND = Qt::gray;
// every second speed *= friction
const qreal FRICTION_PER_SECOND = 0.65;

const unsigned int INITIAL_POPULATION = 500;
const qreal BIRD_SIZE = 2;


const bool USE_ANTIALIASING = false;
const bool USE_OPENGL = true;
const qreal FPS = 20; // aproximate
// friction per frame
const qreal FRICTION = pow(FRICTION_PER_SECOND, 1.0/FPS);


} // end of Settings namespace

#endif // SETTINGS_H
