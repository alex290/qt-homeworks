#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->rb_spot->setText("Спотовый рынок");
    ui->rb_spot->setChecked(true);
    ui->rb_futures->setText("Фьючерсный рынок");

    // ============================
    ui->cmB_coin->addItem("BTCUSDT");
    ui->cmB_coin->addItem("ETHUSDT");
    ui->cmB_coin->addItem("ADAUSDT");
    ui->cmB_coin->addItem("DOGEUSDT");
    ui->cmB_coin->addItem("BNBUSDT");
    // ============================

    ui->prg_click->setFormat("%v");
    ui->prg_click->setMinimum(0);
    ui->prg_click->setMaximum(10);
    ui->prg_click->setValue(procentClick);

    ui->btn_togle->setText("Включить отслеживание");
    ui->btn_togle->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClickPlus()
{
    procentClick ++;
    if (procentClick > 10) {
        procentClick = 0;
    }
    ui->prg_click->setValue(procentClick);
}


void MainWindow::on_btn_togle_toggled(bool checked)
{
    if (checked) {
        ui->btn_togle->setText("Выключить отслеживание");
    } else
    {
        ui->btn_togle->setText("Включить отслеживание");
    }
    ClickPlus();
}


void MainWindow::on_rb_spot_clicked()
{
    ClickPlus();
}


void MainWindow::on_rb_futures_clicked()
{
    ClickPlus();
}


void MainWindow::on_cmB_coin_activated(int index)
{
    ClickPlus();
}

