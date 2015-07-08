#include "view.h"
#include "ui_mainwindow.h"

#include "cookiejar.h"

#include <QDebug>
#include <QApplication>
#include <QNetworkDiskCache>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    //Manager to allow use of cookiejar
    QNetworkAccessManager* nam = new QNetworkAccessManager;

   //Used for debug, prints out all cookies after each request is finished
   connect(nam, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyHandler(QNetworkReply*)));

    //create and assign cookiejar to nam
    jar = new CookieJar();
    nam->setCookieJar(jar);

    //create webview and assign nam to it
    webview = new QWebView();
    webview->page()->setNetworkAccessManager(nam);

    //Enable Caching
    QNetworkDiskCache* cache = new QNetworkDiskCache;
    cache->setCacheDirectory("./cache/");
    cache->setMaximumCacheSize(500*1024*1024);//500MB
    nam->setCache(cache);

    QUrl url("https://www.google.com/calendar");
    //QUrl url("http://localhost:8888/gui/");

    //
    //webview->page()->networkAccessManager()->cookieJar()->setCookiesFromUrl(jar->getCookies(), url);
    //

    webview->load(url);
    webview->show();

    //place webview on screen
    ui->setupUi(this);
    setCentralWidget(webview);

}

//Used for debug, prints out all cookies after each request is finished
void MainWindow::replyHandler(QNetworkReply *reply){
        const QList<QNetworkCookie> cookies2 = jar->getCookies();

    std::cout << std::endl << "HTTP STATUS CODE: " << reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    std::cout << " " << reply->attribute(QNetworkRequest::HttpReasonPhraseAttribute).toByteArray().data() << "\nCookies After HTTP: " << std::endl << std::endl;

    for(QNetworkCookie cookie: cookies2)
        std::cout << cookie.name().data() << " => " << cookie.value().data() << std::endl;


}

QList<QNetworkCookie> MainWindow::getCookies(){
    return jar->getCookies();
}

MainWindow::~MainWindow()
{
    delete webview;
    delete ui;
    delete jar;
}
