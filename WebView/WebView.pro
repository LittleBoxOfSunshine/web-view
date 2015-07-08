#-------------------------------------------------
#
# Project created by QtCreator 2015-06-24T10:34:34
#
#-------------------------------------------------

QT       += core gui
QT       += webkit webkitwidgets

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebView
TEMPLATE = app


SOURCES += main.cpp\
    dialog.cpp \
    manager.cpp \
    view.cpp \
    cookiejar.cpp \

HEADERS  += \
    dialog.h \
    manager.h \
    view.h \
    cookiejar.h

FORMS    += \
    dialog.ui \
    manager.ui \
    view.ui
