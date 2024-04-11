#ifndef CHARTWIN_H
#define CHARTWIN_H

#include <QDialog>
///Подключаем все что нужно для графиков
#include <QLineSeries>
#include <QtCharts>
#include <QChartView>

namespace Ui
{
class ChartWin;
}

class ChartWin : public QDialog
{
    Q_OBJECT

public:
    explicit ChartWin(QWidget* parent = nullptr);
    ~ChartWin();

    void ShGraph(QVector<double>& res);

private:
    Ui::ChartWin* ui;

    QChart* chart;
    QChartView* chartView;
    QGridLayout* layout;
    QLineSeries* ptrGraph;
};

#endif  // CHARTWIN_H
