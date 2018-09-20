#-------------------------------------------------
#
# Project created by QtCreator 2018-09-15T09:32:23
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Map
TEMPLATE = app


SOURCES += main.cpp\
    map.cpp \
    clickableable.cpp \
    placeholder.cpp

HEADERS  += map.h \
    clickablelabel.h \
    placeholder.h \
    information.h

FORMS    += map.ui \
    frame.ui

CONFIG += c++11
