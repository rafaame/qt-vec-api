QMAKE_CC = gcc-6
QMAKE_CXX = g++-6
QMAKE_CXXFLAGS += -Wfatal-errors

QT += core network
QT -= gui

TARGET = bin/qt-vec-api
CONFIG += console
CONFIG -= app_bundle
TEMPLATE = app
OBJECTS_DIR=build
MOC_DIR=build

SOURCES += vec-common/*.cpp
SOURCES += src/*.cpp
SOURCES += src/controller/*.cpp
SOURCES += src/handler/*.cpp
SOURCES += src/worker/*.cpp
SOURCES += src/module/*.cpp
SOURCES += src/server/*.cpp

HEADERS += vec-common/*.h
HEADERS += src/*.h
HEADERS += src/controller/*.h
HEADERS += src/handler/*.h
HEADERS += src/worker/*.h
HEADERS += src/module/*.h
HEADERS += src/server/*.h

INCLUDEPATH += $$PWD/vec-common
INCLUDEPATH += $$PWD/src
INCLUDEPATH += $$PWD/src/controller
INCLUDEPATH += $$PWD/src/handler
INCLUDEPATH += $$PWD/src/worker
INCLUDEPATH += $$PWD/src/module
INCLUDEPATH += $$PWD/src/server

INCLUDEPATH += $$PWD/vendor/bcm2835-1.52/src
INCLUDEPATH += $$PWD/vendor/qhttp/src

LIBS += -L$$PWD/vendor/qhttp/xbin -lqhttp
LIBS += -L$$PWD/vendor/bcm2835-1.52/src -lbcm2835