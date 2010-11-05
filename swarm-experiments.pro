#-------------------------------------------------
#
# Project created by QtCreator 2010-11-05T19:27:40
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = swarm-experiments
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    scene.cpp \
    bird.cpp

HEADERS  += mainwindow.h \
    scene.h \
    bird.h \
    settings.h

OTHER_FILES += \
    .gitignore

DEPENDPATH += .
