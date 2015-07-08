#-------------------------------------------------
#
# Project created by QtCreator 2015-07-05T13:51:27
#
#-------------------------------------------------

QT       += core gui webkit webkitwidgets

CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebViewManager
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    viewlog.cpp

HEADERS  += mainwindow.h \
    viewlog.h

FORMS    += mainwindow.ui \
    viewlog.ui
