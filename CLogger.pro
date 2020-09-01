TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    clogger.cpp

HEADERS += \
    clogger.h

INCLUDEPATH += /opt/mCommonlib/source
