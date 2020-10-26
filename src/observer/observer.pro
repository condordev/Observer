HOME = ../..
include ($$HOME/common.pri)

TEMPLATE = lib
TARGET = libObserver
DEPENDPATH += .
INCLUDEPATH += . $$HOME/src
unix:DESTDIR = $$HOME/lib
win32:DESTDIR = $$HOME/bin
message(DESTDIR is: $$DESTDIR)

DEFINES += BUILDING_UTILITIES

# Input
HEADERS += \
    Observer.h \
    Publisher.h \
    interface.h
SOURCES += \
    Observer.cpp \
    Publisher.cpp

OTHER_FILES += \
    Publisher.o \
    Observer.o \
    Makefile
