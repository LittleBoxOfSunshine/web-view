#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebView>
#include <QUrl>
#include <QLayout>
#include <iostream>
#include <QList>
#include <QNetworkCookie>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QString>

#include <QApplication>

#include "cookiejar.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QList<QNetworkCookie> getCookies();
    ~MainWindow();

public slots:
    void replyHandler(QNetworkReply* reply);

private:
    Ui::MainWindow *ui;

    QWebView* webview;
    QVBoxLayout* webviewLayout;
    CookieJar* jar;
};

#endif // MAINWINDOW_H
