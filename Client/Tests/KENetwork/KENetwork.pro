#-------------------------------------------------
#
# Project created by QtCreator 2015-02-04T19:56:07
#
#-------------------------------------------------

QT       += network testlib

QT       -= gui

TARGET = tst_keinternetexplorertest
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_keinternetexplorertest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../KENetwork/release/ -lKEBrowser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../KENetwork/debug/ -lKEBrowser

INCLUDEPATH += $$PWD/../../KENetwork
DEPENDPATH += $$PWD/../../KENetwork

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/release/libKEBrowser.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/debug/libKEBrowser.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/release/KEBrowser.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/debug/KEBrowser.lib
