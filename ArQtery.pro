#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T23:18:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ArQtery_Dialog
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    field.cpp \
    tank.cpp \
    cannon.cpp \
    bullet.cpp \
    wind.cpp

HEADERS  += dialog.h \
    field.h \
    tank.h \
    cannon.h \
    bullet.h \
    wind.h

FORMS    += dialog.ui
