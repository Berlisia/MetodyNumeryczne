#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setResult(const QVector<float>& p_x, const QVector<float>& p_y)
{
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(p_x, p_y);

    ui->customPlot->xAxis->setRange(0,10);
    ui->customPlot->yAxis->setRange(0,500);
    ui->customPlot->replot();
}
