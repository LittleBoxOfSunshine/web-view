
#include "view.h"
#include <QApplication>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QListWidget>

#include <QNetworkCookie>
#include <QStandardPaths>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    qDebug() << QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);

    /*
    ////
    foreach (QNetworkCookie cookie, w.getCookies())
    {
        if(cookie.name() == "connect.sid") //loging cookie
        {
           // QApplication::getInstance().setLoginCookie(cookie); //here i save the login cookie in a class QNetworkCookie*
            qDebug() << "cookie loaded";
        }
        else
        {
            qDebug() << "Error loading the login cookie: " << cookie.name();
        }
    }
    ////
    */

    return a.exec();
}
