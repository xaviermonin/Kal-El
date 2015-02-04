#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T00:38:04
#
#-------------------------------------------------

QT       -= gui
QT       += axcontainer network

TARGET = KENetwork
TEMPLATE = lib
CONFIG += staticlib axcontainer

SOURCES += \
    keinternetexplorer.cpp \
    kenetworkreply.cpp \
    kenetworkaccessmanager.cpp \
    kehtmldocument.cpp

HEADERS += \
    keinternetexplorer.h \
    kenetworkreply.h \
    kenetworkaccessmanager.h \
    kehtmldocument.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
