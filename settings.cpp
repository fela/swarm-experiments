#include "settings.h"
#include "ui_settings.h"

#include <cmath>

qreal Settings::FRICTION = pow(FRICTION_PER_SECOND, 1.0/FPS);

Settings::Settings(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}


bool Settings::openGL() {return ui->openGLBox->isChecked();}
bool Settings::antialiasing() {return ui->antialiasingBox->isChecked();}

SceneSettings Settings::sceneSettings()
{
    SceneSettings res;
    res.width = ui->widthBox->value();
    res.heigth = ui->heightBox->value();
    res.birds = ui->birdsBox->value();
    res.predators = ui->birdsBox->value();
    res.birdSize = ui->birdSizeBox->value();
    return res;
}

void Settings::on_openGLBox_toggled(bool checked)
{
    emit openGLToggled(checked);
}

void Settings::on_antialiasingBox_toggled(bool checked)
{
    emit antialiasingToggled(checked);
}

void Settings::on_createSceneButton_clicked()
{
    emit createSceneClicked(sceneSettings());
}

void Settings::on_zoomSlider_valueChanged(int value)
{
    emit zoomChanged(pow(2, value/3.0));
}
