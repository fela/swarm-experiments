#ifndef SETTINGS_H
#define SETTINGS_H

#include <QtCore/QtGlobal>
#include <QtGui/QColor>

namespace Settings {

// scene
const qreal SCENE_HEIGHT = 500;
const qreal SCENE_WIDTH = 700;
const Qt::GlobalColor SCENE_COLOR = Qt::black;
const Qt::GlobalColor SCENE_BACKGROUND = Qt::gray;

const unsigned int INITIAL_POPULATION = 50;
const qreal BIRD_SIZE = 4;

const bool USE_ANTIALIASING = true;
const bool USE_OPENGL = true;
const qreal FPS = 20; // aproximate


} // end of Settings namespace

#endif // SETTINGS_H
