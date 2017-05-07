#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Src/DataBase.h"
#include <QFileDialog>
#include <QString>
#include <cmath>
#include <memory>


MainWindow::MainWindow(DataBase& p_dataBase, QWidget *parent) :
    m_dataBase(p_dataBase),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMenu();
    setupConnectionForZoom();

    ui->horizontalScrollBar->setRange(-500, 500);
    ui->verticalScrollBar->setRange(0, 500);

    // initialize axis range (and scroll bar positions via signals we just connected):
    ui->customPlot->xAxis->setRange(0, 10, Qt::AlignCenter);
    ui->customPlot->yAxis->setRange(0, 500, Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setResult(const QVector<double>& p_x, const QVector<double>& p_y)
{
    updateAxis();
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setPen(QPen(Qt::blue));
    ui->customPlot->graph()->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->customPlot->graph()->setData(p_x, p_y);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->replot();
}

void MainWindow::setInputPoints(const QVector<double>& p_x, const QVector<double>& p_y)
{
    ui->customPlot->addGraph();
    ui->customPlot->graph()->setPen(QPen(Qt::red));
    ui->customPlot->graph()->setData(p_x, p_y);
    ui->customPlot->axisRect()->setupFullAxesBox(true);
    ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);
    ui->customPlot->replot();
}

void MainWindow::showFileError()
{
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->critical(0,"Error","I can't open file!");
    m_messageBox->setFixedSize(500,200);
    m_messageBox->show();
}

void MainWindow::showFileOk()
{
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->setText("Data has been imported.");
    m_messageBox->addButton(QMessageBox::Ok);
    m_messageBox->show();
}

void MainWindow::showFactors(std::pair<float, float> p_factors)
{
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->setText("A = " + QString::number(p_factors.first) + " B = " + QString::number(p_factors.second));
    m_messageBox->addButton("OK", QMessageBox::AcceptRole);
    m_messageBox->show();
}

void MainWindow::horzScrollBarChanged(int value)
{
  if (qAbs(ui->customPlot->xAxis->range().center()-value/100.0) > 0.01)
  {
    ui->customPlot->xAxis->setRange(value/100.0, ui->customPlot->xAxis->range().size(), Qt::AlignCenter);
    ui->customPlot->replot();
  }
}

void MainWindow::vertScrollBarChanged(int value)
{
  if (qAbs(ui->customPlot->yAxis->range().center()+value/100.0) > 0.01)
  {
    ui->customPlot->yAxis->setRange(-value/100.0, ui->customPlot->yAxis->range().size(), Qt::AlignCenter);
    ui->customPlot->replot();
  }
}

void MainWindow::xAxisChanged(QCPRange range)
{
  ui->horizontalScrollBar->setValue(qRound(range.center()*100.0));
  ui->horizontalScrollBar->setPageStep(qRound(range.size()*100.0));
}

void MainWindow::yAxisChanged(QCPRange range)
{
  ui->verticalScrollBar->setValue(qRound(-range.center()*100.0));
  ui->verticalScrollBar->setPageStep(qRound(range.size()*100.0));
}

void MainWindow::loadFile()
{
    m_dataBase.setDataFileName(QFileDialog::getOpenFileName().toStdString());
    emit applyNewFile();
}

void MainWindow::setupMenu()
{
    QMenu * mainMenu = new QMenu(tr("&Menu"), this);
    QMainWindow::menuBar()->addMenu(mainMenu);
    mainMenu->addAction(tr("&Open"), this, SLOT(loadFile()));
    mainMenu->addAction(tr("&Calculate"), this, SIGNAL(calculatePressed()));
    mainMenu->addAction(tr("&Quit"), this, SLOT(close()));
}

void MainWindow::setupConnectionForZoom()
{
    connect(ui->horizontalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(horzScrollBarChanged(int)));
    connect(ui->verticalScrollBar, SIGNAL(valueChanged(int)), this, SLOT(vertScrollBarChanged(int)));
    connect(ui->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(xAxisChanged(QCPRange)));
    connect(ui->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), this, SLOT(yAxisChanged(QCPRange)));
}

void MainWindow::updateAxis()
{
    double possition1 = m_dataBase.getVectorOfOrdinates()[0];
    double possition2 = m_dataBase.getVectorOfOrdinates().back();
    ui->customPlot->xAxis->setRange(possition1, possition2);
    possition1 = m_dataBase.getVectorOfSevered()[0];
    possition2 = m_dataBase.getVectorOfSevered().back();
    ui->customPlot->yAxis->setRange(possition1, possition2);
}


