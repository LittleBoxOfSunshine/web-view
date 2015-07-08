#include "cookiejar.h"

CookieJar::CookieJar(QObject *parent) :
    QNetworkCookieJar(parent)
{
    this->loadCookiesFromDisk();
}

void CookieJar::setAutoSave(bool autoSave){
    this->autoSave = autoSave;
}


#include <iostream>

bool CookieJar::saveCookiesToDisk(){
    std::ofstream output("cookies.dat");

    this->purgeOldCookies();

    if(output){
        QList<QNetworkCookie> cookies = this->allCookies();

        std::cout << "\nSAVING COOKIES" << std::endl << std::endl;

        for(QNetworkCookie cookie: cookies)
            if(!cookie.isSessionCookie()){
                std::cout << cookie.toRawForm().data() << std::endl;
                output << cookie.toRawForm().data() << this->COOKIE_DELIMITER;
            }

        output.close();
        return true;
    }
    else{
        return false;
    }
}

#include <QDebug>

bool CookieJar::loadCookiesFromDisk(){
    std::ifstream input("cookies.dat");

    if(input){
        QList<QNetworkCookie> cookies;

        std::string cookieData;

        std::cout << "\nLOADING COOKIES" << std::endl << std::endl;

        while(getline(input, cookieData, this->COOKIE_DELIMITER)){
            std::cout << cookieData << std::endl;

            int seperatorIndex = -1;

            for(int i=0; i<cookieData.length(); i++)
                if(cookieData[i] == '='){
                    seperatorIndex = i;
                    break;
                }
            //TODO: if seperatorIndex = -1 cookie is malformed

            QByteArray name(cookieData.c_str(), seperatorIndex);

            seperatorIndex++;

            QByteArray data(cookieData.c_str()+seperatorIndex, cookieData.length() - seperatorIndex);

            qDebug() << "NAME => " << name;
            qDebug() << "DATA => " << data;

            cookies.append(QNetworkCookie(name, data));
        }

        this->setAllCookies(cookies);

        return true;
    }
    else{
        return false;
    }
}

/**
 * This function comes from the official qt demo at
 *      http://doc.qt.io/qt-5/qtwebkitexamples-webkitwidgets-browser-cookiejar-cpp.html
 */
void CookieJar::purgeOldCookies(){

    QList<QNetworkCookie> cookies = allCookies();
    if (cookies.isEmpty())
        return;
    int oldCount = cookies.count();
    QDateTime now = QDateTime::currentDateTime();
    for (int i = cookies.count() - 1; i >= 0; --i) {
        if (!cookies.at(i).isSessionCookie() && cookies.at(i).expirationDate() < now)
            cookies.removeAt(i);
    }
    if (oldCount == cookies.count())
        return;
    setAllCookies(cookies);
    //This last line from the example was omitted as it is not relevant to the function of this project?
    //emit cookiesChanged();
}

CookieJar::~CookieJar(){
    //TODO: if cookies are enabled check
    this->saveCookiesToDisk();
}
