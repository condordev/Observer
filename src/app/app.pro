HOME = ../..
include ($$HOME/common.pri)

QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

DEPENDPATH += .
INCLUDEPATH += $$HOME/src
DESTDIR = $$HOME/bin

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

unix:LIBS += -ldl
win32:LIBS += -L$$HOME/bin -llibObserver1

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
