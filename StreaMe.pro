#-------------------------------------------------
#
# Project created by QtCreator 2012-12-03T12:17:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = StreaMe
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    project.cpp \
    source.cpp \
    live.cpp \
    controllerencoding.cpp \
    controller.cpp \
    controllerapi.cpp

HEADERS  += mainwindow.h \
    project.h \
    source.h \
    live.h \
    controller.h

FORMS    += mainwindow.ui

RESOURCES += \
    New.qrc
