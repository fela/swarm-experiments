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
    bird.cpp \
    rand.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    scene.h \
    bird.h \
    settings.h \
    rand.h

OTHER_FILES += \
    .gitignore

DEPENDPATH += .

FORMS += \
    settings.ui
