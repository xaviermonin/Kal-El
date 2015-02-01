#-------------------------------------------------
#
# Project created by QtCreator 2015-02-01T00:42:43
#
#-------------------------------------------------

QT       += core axcontainer network

QT       -= gui

TARGET = KEBrowserTest
CONFIG   += console axcontainer
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../KEBrowser/release/ -lKEBrowser
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../KEBrowser/debug/ -lKEBrowser

INCLUDEPATH += $$PWD/../KEBrowser
DEPENDPATH += $$PWD/../KEBrowser

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KEBrowser/release/libKEBrowser.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KEBrowser/debug/libKEBrowser.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KEBrowser/release/KEBrowser.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../KEBrowser/debug/KEBrowser.lib
