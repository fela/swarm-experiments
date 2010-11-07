#include "mainwindow.h"

#include "scene.h"
#include "settings.h"
#include "view.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("The Swarm!");
    addDockWidget(Qt::RightDockWidgetArea, new Settings(this));
    setCentralWidget(new View(new Scene()));
}

MainWindow::~MainWindow()
{

}
