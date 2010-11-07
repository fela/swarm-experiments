#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDockWidget>

namespace Ui {
    class Settings;
}

class Settings : public QDockWidget
{
    Q_OBJECT

public:
    // scene
    static const qreal SCENE_HEIGHT = 500;
    static const qreal SCENE_WIDTH = 700;
    static const Qt::GlobalColor SCENE_COLOR = Qt::black;
    static const Qt::GlobalColor SCENE_BACKGROUND = Qt::gray;
    // every second speed *= friction
    static const qreal FRICTION_PER_SECOND = 0.65;

    static const unsigned int INITIAL_POPULATION = 500;
    static const qreal BIRD_SIZE = 2;


    static const bool USE_ANTIALIASING = false;
    static const bool USE_OPENGL = true;
    static const qreal FPS = 20; // aproximate
    // friction per frame
    static qreal FRICTION;

    explicit Settings(QWidget *parent = 0);
    ~Settings();

signals:
    void openGLToggled(bool enabled);
    void antialiasingToggled(bool enabled);

private:
    Ui::Settings *ui;

private slots:
    void on_openGLBox_toggled(bool checked);
    void on_antialiasingBox_toggled(bool checked);
};

#endif // SETTINGS_H
