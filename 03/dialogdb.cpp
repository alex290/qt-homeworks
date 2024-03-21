#include "dialogdb.h"
#include "ui_dialogdb.h"

DialogDb::DialogDb(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogDb)
{
    ui->setupUi(this);
}

DialogDb::~DialogDb()
{
    delete ui;
}
