#-------------------------------------------------
#
# Project created by QtCreator 2015-02-09T19:23:25
#
#-------------------------------------------------

QT       += testlib network axcontainer

QT       -= gui

TARGET = tst_kenetworktest
CONFIG   += console testcase
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    main.cpp \
    keinternetexplorertest.cpp \
    kenetworkaccessmanagertest.cpp \
    kenetworkreplytest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    testrunner.h \
    keinternetexplorertest.h \
    kenetworkaccessmanagertest.h \
    kenetworkreplytest.h

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../KENetwork/release/ -lKENetwork
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../KENetwork/debug/ -lKENetwork

INCLUDEPATH += $$PWD/../../KENetwork
DEPENDPATH += $$PWD/../../KENetwork

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/release/libKENetwork.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/debug/libKENetwork.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/release/KENetwork.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../KENetwork/debug/KENetwork.lib
