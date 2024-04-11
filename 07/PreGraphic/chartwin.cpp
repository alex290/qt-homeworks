#include "chartwin.h"
#include "ui_chartwin.h"

ChartWin::ChartWin(QWidget* parent) : QDialog(parent), ui(new Ui::ChartWin)
{
    ui->setupUi(this);

    chart = new QChart();
    chart->legend()->setVisible(false);

    chartView = new QChartView(chart);

    layout = new QGridLayout;
    ui->qw_Chart->setLayout(layout);
    layout->addWidget(chartView);
    chartView->show();

    ptrGraph = new QLineSeries(this);
}

ChartWin::~ChartWin()
{
    delete ui;
}

void ChartWin::ShGraph(QVector<double>& res)
{
    //Перед новой отрисовкой очистим графики
    if (chart->series().isEmpty() == false)
    {
        ptrGraph->clear();
        //Удаляем серии из графика
        chart->removeSeries(ptrGraph);
    }

    //создадим контейнеры для хранения данных
    QVector<double> x;
    QVector<double> y;

    // Забираем первые 1000 данных так как частота равна 1000 hz (1 секунда)
    for (int indx = 0; indx < 1000; indx++)
    {
        if (indx < res.size())
        {
            ptrGraph->append(indx, res[indx]);
        }
    }

    chart->addSeries(ptrGraph);
    chartView->chart()->createDefaultAxes();
    chartView->show();
}
