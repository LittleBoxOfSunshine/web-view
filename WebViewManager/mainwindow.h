#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include <QStandardPaths>
#include <QFile>
#include <QDir>
#include <QMap>

#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    static const QString HELP_URL;

    static const QString CACHE_DIR;

    static const QString COOKIE_DIR;

    static const QString CONFIG_DIR;

    static const QString CONFIG_PATH;

    static const QString DATA_PATH;

    explicit MainWindow(QWidget *parent = 0);
    void initializeUI();
    void loadSettings();
    void saveSettings();
    void switchEditorTarget();
    ~MainWindow();

public slots:
    //File Menu Actions

    void importView();
    void exportView();
    void backup();
    void copyFilesystem();
    void repairFilesystem();
    void preferences();

    //View Menu Actions

    void newView();
    void createShortcut();
    void removeView();
    void duplicateView();

/*
    //Group Menu Actions

    void newGroup();
    void removeGroup();
    void duplicateGroup();
*/

    //Help Menu Actions

    void about();
    void website();
    void viewLogs();

    //Update Settings
    void updateSettings();

private:
    Ui::MainWindow *ui;

    void checkDirAndCreate(QString path);
};

#endif // MAINWINDOW_H
