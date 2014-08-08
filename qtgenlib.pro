#-------------------------------------------------
#
# Project created by QtCreator 2014-08-07T11:28:32
#
#-------------------------------------------------

QT       -= gui
QT   += core widgets

TARGET = qtgenlib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += \
    titlevaluewidget.cpp \
    qstringlistinputdialog.cpp \
    todchime.cpp \
    labeleditwidget.cpp

HEADERS += qtgenlib.h \
    titlevaluewidget.h \
    qstringlistinputdialog.h \
    todchime.h \
    labeleditwidget.h
unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = /usr/lib
    }
    INSTALLS += target
}
