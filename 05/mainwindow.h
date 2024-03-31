#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void on_qpB_start_toggled(bool checked);

    void UpdateTime(const long& sec);

    void on_qpB_clear_clicked();

    void on_qpB_round_clicked();

private:
    Ui::MainWindow* ui;
    Stopwatch* timerWatch;
};
#endif  // MAINWINDOW_H
