#include "mainwindow.h"
#include "ui_mainwindow.h"

//Initialize constants
const QString MainWindow::HELP_URL = "http://webview.bmcatech.com/help.php";
const QString MainWindow::CACHE_DIR = "cache";
const QString MainWindow::COOKIE_DIR = "cookie";
const QString MainWindow::CONFIG_DIR = "config";
const QString MainWindow::CONFIG_PATH = "manager.conf";
const QString MainWindow::DATA_PATH = "manager.dat";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadSettings();
    initializeUI();

    //Connect All Menu Buttons to their functions

    //File Menu
    connect(ui->actionImport, SIGNAL(triggered()), this, SLOT(importView()));
    connect(ui->actionExport, SIGNAL(triggered()), this, SLOT(exportView()));
    connect(ui->actionBackup, SIGNAL(triggered()), this, SLOT(backup()));
    connect(ui->actionCopy_Filesystem, SIGNAL(triggered()), this, SLOT(copyFilesystem()));
    connect(ui->actionRepair_Filesystem, SIGNAL(triggered()), this, SLOT(repairFilesystem()));
    connect(ui->actionPreferences, SIGNAL(triggered()), this, SLOT(preferences()));

    //View Menu
    connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newView()));
    connect(ui->actionCreate_Launcher_Shortcut, SIGNAL(triggered()), this, SLOT(createShortcut()));
    connect(ui->actionRemove, SIGNAL(triggered()), this, SLOT(removeView()));
    connect(ui->actionDuplicate, SIGNAL(triggered()), this, SLOT(duplicateView()));

    /*
    //Group Menu
    connect(ui->actionNew_2, SIGNAL(triggered()), this, SLOT(newGroup()));
    connect(ui->actionRemove_2, SIGNAL(triggered()), this, SLOT(removeGroup()));
    connect(ui->actionDuplicate_2, SIGNAL(triggered()), this, SLOT(duplicateGroup()));
    */

    //Help Menu
    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(about()));
    connect(ui->actionWebView_Website, SIGNAL(triggered()), this, SLOT(website()));
    connect(ui->actionView_Logs, SIGNAL(triggered()), this, SLOT(viewLogs()));

    //Update Settings Button
    connect(ui->updateSettingsButton, SIGNAL(clicked()), this, SLOT(updateSettings()));

}

void MainWindow::loadSettings(){

}

void MainWindow::initializeUI(){

}

void MainWindow::updateSettings(){

}

void MainWindow::saveSettings(){

}

void MainWindow::switchEditorTarget(){

}

//File Menu Actions

void MainWindow::importView(){

}

void MainWindow::exportView(){

}

void MainWindow::backup(){

}

void MainWindow::copyFilesystem(){

}

void MainWindow::repairFilesystem(){
/*
#ifdef _WIN32

#elif __linux__

#elif __APPLE__

#endif
*/
    //load system specific app data path
    QString dataPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    dataPath+="/";

    qDebug() << "DATA PATH: " << dataPath;

    //check if directory structure exists, if it doesn't, create it
    checkDirAndCreate(dataPath);
    checkDirAndCreate(dataPath+CACHE_DIR);
    checkDirAndCreate(dataPath+COOKIE_DIR);
    checkDirAndCreate(dataPath+CONFIG_DIR);

    //config and data table io objects
    QFile configF(dataPath+CONFIG_PATH);
    QFile dataTableF(dataPath+DATA_PATH);

    //Containers for loaded settings
    QMap<QString, QString> config;
    QList<QString> viewIDS;

    //if config file exists load it else create empty file
    if(configF.exists()){
       configF.open(QIODevice::ReadOnly | QIODevice::Text);
       while(!configF.atEnd()){
           QList<QString> pair = QString(configF.readLine()).split("=");
           config.insert(pair[0], pair[1]);
       }
    }
    else{
        configF.open(QIODevice::WriteOnly | QIODevice::Text);
        configF.close();
    }

    //if config file exists load it else create empty file
    if(dataTableF.exists()){
       configF.open(QIODevice::ReadOnly | QIODevice::Text);
       while(!configF.atEnd()){
           viewIDS.append(QString(configF.readLine()));
       }
    }
    else{
        dataTableF.open(QIODevice::WriteOnly | QIODevice::Text);
        dataTableF.close();
    }

    //Scan for propery directory structure of any existing views
    for(QString element: viewIDS){
        if(!QDir(dataPath+CACHE_DIR+"/"+element).exists())
            QDir().mkdir(dataPath+CACHE_DIR+"/"+element);

        if(!QDir(dataPath+COOKIE_DIR+"/"+element).exists())
            QDir().mkdir(dataPath+COOKIE_DIR+"/"+element);

        QFile viewConfig(dataPath+CONFIG_PATH+"/"+element+".conf");

        if(!viewConfig.exists()){
            dataTableF.open(QIODevice::WriteOnly | QIODevice::Text);
            dataTableF.close();
        }
    }

    //Locate orphaned views (config file exists but isn't in manager table or cache/cookies exist without config)
    for(QString element: viewIDS){
        //TODO: Scan for all files and directories not stored in the table
    }
        //if no cache/cookies directories create those and append view to manager table
        //if no config, cache/cookies are unusable so remove them
}

void MainWindow::checkDirAndCreate(QString path){
    if(!QDir(path).exists()){
        QDir().mkdir(path);
        qDebug() << path << " not found, creating...";
    }
    else{
        qDebug() << path << " exists";
    }
}

void MainWindow::preferences(){

}

//View Menu Actions

void MainWindow::newView(){

}

void MainWindow::createShortcut(){

}

void MainWindow::removeView(){

}

void MainWindow::duplicateView(){

}

/*
//Group Menu Actions

void MainWindow::newGroup(){

}

void MainWindow::removeGroup(){

}

void MainWindow::duplicateGroup(){

}
*/

//Help Menu Actions

void MainWindow::about(){

}

void MainWindow::website(){
    QDesktopServices::openUrl(QUrl(HELP_URL));
}

void MainWindow::viewLogs(){

}

MainWindow::~MainWindow()
{
    delete ui;
}
