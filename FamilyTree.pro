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
    newpersone.cpp \
    familytree.cpp \
    mainwidget.cpp \
    mainwindow.cpp \
    TreeWidget.cpp \
    person.cpp

HEADERS  += \
    newpersone.h \
    familytree.h \
    mainwidget.h \
    mainwindow.h \
    TreeWidget.h \
    person.h

FORMS    += familytree.ui \
    newpersone.ui \
    mainwindow.ui
