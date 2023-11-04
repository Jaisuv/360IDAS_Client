#-------------------------------------------------
#
# Project created by QtCreator 2023-10-06T01:08:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 360IDAS_Client
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Thread/videoplaythread.cpp \
    Thread/readthread.cpp \
    Thread/writethread.cpp \
    Window/widget.cpp \
    Window/csettinginit.cpp \
    Window/loginwin.cpp \
    Window/registwin.cpp \
    Window/systemmainwin.cpp \
    Window/videoplayerwidget.cpp \
    Window/videorecorditemwidget.cpp \
    Control/ipaddress.cpp \
    socketconnect.cpp \
    connectthread.cpp \
    tools.cpp \
    Thread/filesplitthread.cpp \
    crccheck.cpp \
    sendimgtask.cpp \
    Thread/camerathread.cpp \
    Control/verificationcode.cpp \
    lightcheck.cpp \
    videoscreenshotdelegate.cpp \
    Thread/heartbeatthread.cpp \
    Thread/heartbeatgetthread.cpp \
    bigpicwidget.cpp \
    Thread/birdviewsidethread.cpp


HEADERS += \
        widget.h \
    Thread/videoplaythread.h \
    Thread/readthread.h \
    Thread/writethread.h \
    Window/widget.h \
    Window/csettinginit.h \
    Window/loginwin.h \
    Window/registwin.h \
    Window/systemmainwin.h \
    Window/videoplayerwidget.h \
    Window/videorecorditemwidget.h \
    Control/ipaddress.h \
    socketconnect.h \
    protocol.h \
    connectthread.h \
    tools.h \
    Thread/filesplitthread.h \
    crccheck.h \
    sendimgtask.h \
    Thread/camerathread.h \
    Control/verificationcode.h \
    lightcheck.h \
    videoscreenshotdelegate.h \
    Thread/heartbeatthread.h \
    Thread/heartbeatgetthread.h \
    bigpicwidget.h \
    Thread/birdviewsidethread.h

FORMS += \
        widget.ui \
    csettinginit.ui \
    loginwin.ui \
    registwin.ui \
    systemmainwin.ui \
    videorecorditemwidget.ui \
    videoplayerwidget.ui \
    bigpicwidget.ui

INCLUDEPATH += /usr/local/include
LIBS += /usr/local/lib/libopencv_world.so

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

