
#ifndef COOKIEJAR_H
#define COOKIEJAR_H

#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QDateTime>

#include <string>
#include <fstream>

class CookieJar : public QNetworkCookieJar
{
    Q_OBJECT
public:
    explicit CookieJar(QObject *parent = 0);

    void purgeOldCookies();
    void setAutoSave(bool autoSave);
    bool saveCookiesToDisk();
    bool loadCookiesFromDisk();
    ~CookieJar();

    const QList<QNetworkCookie> getCookies(){
        return this->allCookies();
    }

private:
    bool autoSave;
    const char COOKIE_DELIMITER = '\n';

signals:

public slots:

};

#endif // COOKIEJAR_H
