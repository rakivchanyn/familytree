#-------------------------------------------------
#
# Project created by QtCreator 2014-05-17T14:27:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
CONFIG += c++11
TARGET = FamilyTree
TEMPLATE = app


SOURCES += main.cpp\
    persone.cpp \
    newpersone.cpp \
    familytree.cpp \
    mainwidget.cpp

HEADERS  += \
    persone.h \
    newpersone.h \
    familytree.h \
    mainwidget.h

FORMS    += familytree.ui \
    newpersone.ui
