#ifndef VIEWLOG_H
#define VIEWLOG_H

#include <QWidget>

namespace Ui {
class viewLog;
}

class viewLog : public QWidget
{
    Q_OBJECT

public:
    explicit viewLog(QWidget *parent = 0);
    ~viewLog();

private:
    Ui::viewLog *ui;
};

#endif // VIEWLOG_H
