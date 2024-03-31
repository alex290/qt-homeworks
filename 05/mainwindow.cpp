#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timerWatch = new Stopwatch(this);
    ui->qpB_round->setEnabled(false);
    connect(timerWatch, &Stopwatch::UpdateTime, this, &MainWindow::UpdateTime);
    connect(timerWatch, &Stopwatch::AddRound, this, &MainWindow::AddRound);
    ui->qpB_start->setStyleSheet("background-color: #c6f6b4");
    on_qpB_clear_clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_qpB_start_toggled(bool checked)
{
    if (checked)
    {
        ui->qpB_start->setText("Стоп");
        ui->qpB_round->setEnabled(true);
        timerWatch->StartTimer();
        ui->qpB_start->setStyleSheet("background-color: #f6bfb3");
    }
    else
    {
        ui->qpB_start->setText("Старт");
        ui->qpB_round->setEnabled(false);
        ui->qpB_start->setStyleSheet("background-color: #c6f6b4");
        timerWatch->StopTimer();
    }
}

void MainWindow::UpdateTime(const long& sec)
{
    double sec_dec = static_cast<double>(sec) / 10;
    ui->qLb_time->setText(QString::number(sec_dec));
}

void MainWindow::on_qpB_clear_clicked()
{
    ui->qLb_time->setText(QString::number(0));
    timerWatch->ClearSecond();
    ui->qTBr_round->clear();
}

void MainWindow::on_qpB_round_clicked()
{
    timerWatch->NewRound();
}

void MainWindow::AddRound(const long& sec, const size_t& round)
{
    double sec_dec = static_cast<double>(sec) / 10;
    ui->qTBr_round->append(QString("Круг %1, время: %2 сек").arg(round).arg(sec_dec));
}
