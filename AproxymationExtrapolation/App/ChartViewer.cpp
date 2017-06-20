#include "ChartViewer.h"
#include "ui_ChartViewer.h"
#include <algorithm>

ChartViewer::ChartViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ChartViewer)
{
    ui->setupUi(this);
    setupConnectionForZoom();

    ui->horizontalScrollBar->setRange(-500, 500);
    ui->verticalScrollBar->setRange(0, 500);

    // initialize axis range (and scroll bar positions via signals we just connected):
    ui->customPlot->xAxis->setRange(0, 10, Qt::AlignCenter);
    ui->customPlot->yAxis->setRange(0, 500, Qt::AlignCenter);
}

ChartViewer::~ChartViewer()
{
    delete ui;
}

void ChartViewer::setResult(const QVector<double> &p_x, const QVector<double> &p_y)
{
    updateAxis(p_x, p_y);
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setPen(QPen(Qt::blue));
    ui->customPlot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->customPlot->graph()->setData(p_x, p_y);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->replot();
}

void ChartViewer::setInputPoints(const QVector<double> &p_x, const QVector<double> &p_y)
{
    updateAxis(p_x, p_y);
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setPen(QPen(Qt::red));
    ui->customPlot->graph()->setData(p_x, p_y);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom); // cos ze skalaS
    ui->customPlot->replot();
}

void ChartViewer::horzScrollBarChanged(int value)
{
    if (qAbs(ui->customPlot->xAxis->range().center() - value / 100.0) > 0.01)
    {
        ui->customPlot->xAxis->setRange(value / 100.0, ui->customPlot->xAxis->range().size(), Qt::AlignCenter);
        ui->customPlot->replot();
    }
}

void ChartViewer::vertScrollBarChanged(int value)
{
    if (qAbs(ui->customPlot->yAxis->range().center() + value / 100.0) > 0.01)
    {
        ui->customPlot->yAxis->setRange(-value / 100.0, ui->customPlot->yAxis->range().size(), Qt::AlignCenter);
        ui->customPlot->replot();
    }
}

void ChartViewer::xAxisChanged(QCPRange range)
{
    ui->horizontalScrollBar->setValue(qRound(range.center() * 100.0));
    ui->horizontalScrollBar->setPageStep(qRound(range.size() * 100.0));
}

void ChartViewer::yAxisChanged(QCPRange range)
{
    ui->verticalScrollBar->setValue(qRound(-range.center() * 100.0));
    ui->verticalScrollBar->setPageStep(qRound(range.size() * 100.0));
}

void ChartViewer::setupConnectionForZoom()
{
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
}

void ChartViewer::updateAxis(const QVector<double> &p_x, const QVector<double> &p_y)
{
    double possition1 = p_x[0];
    double possition2 = p_x.back();
    ui->customPlot->xAxis->setRange(possition1, possition2);
    possition1 = p_y[0];
    possition2 = *std::max_element(p_y.constBegin(), p_y.constEnd());
    ui->customPlot->yAxis->setRange(possition1, possition2);
}
