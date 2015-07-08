#include "viewlog.h"
#include "ui_viewlog.h"

viewLog::viewLog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::viewLog)
{
    ui->setupUi(this);
}

viewLog::~viewLog()
{
    delete ui;
}
