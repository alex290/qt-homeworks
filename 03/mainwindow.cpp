#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conect_db = new DialogDb(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_add_db_triggered()
{
    conect_db->show();
}
