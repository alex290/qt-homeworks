#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_togle_toggled(bool checked);

    void on_rb_spot_clicked();

    void on_rb_futures_clicked();

    void on_cmB_coin_activated(int index);

private:
    Ui::MainWindow *ui;

    int procentClick{0};

    void ClickPlus();
};
#endif // MAINWINDOW_H
