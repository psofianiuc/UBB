#-------------------------------------------------
#
# Project created by QtCreator 2016-05-28T09:08:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab11
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dog.cpp \
    repository.cpp \
    controller.cpp \
    adoptionlist.cpp \
    dogstablemodel.cpp \
    dogsqtui.cpp

HEADERS  += mainwindow.h \
    dog.h \
    repository.h \
    controller.h \
    adoptionlist.h \
    dogstablemodel.h \
    qtui.h \
    dogsqtui.h

FORMS    += mainwindow.ui

DISTFILES += \
    dogs.txt
