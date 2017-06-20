#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Src/DataBase.h"

#include <QFileDialog>
#include <QString>
#include <QMessageBox>
#include <QStandardItemModel>
#include <cmath>
#include <memory>


MainWindow::MainWindow(DataBase& p_dataBase, QWidget* parent):
    QMainWindow(parent),
    m_dataBase(p_dataBase),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setResult(const QVector<double>& p_x, const QVector<double>& p_y)
{
    m_chartViewer->setResult(p_x,p_y);
}

void MainWindow::setInputPoints(const QVector<double>& p_x, const QVector<double>& p_y)
{
    ui->calculator->setDisabled(false);
    m_chartViewer = std::make_unique<ChartViewer>(this);
    m_chartViewer->setInputPoints(p_x, p_y);
    m_chartViewer->show();
}

void MainWindow::showFileError()
{
    m_messageBox.reset();
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->critical(0, "Error", "I can't open file!");
    m_messageBox->setFixedSize(500, 200);
    m_messageBox->show();
}

void MainWindow::showFileOk()
{
    m_messageBox.reset();
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->setText("Data has been imported.");
    m_messageBox->addButton(QMessageBox::Ok);
    m_messageBox->show();
}

void MainWindow::showFactors(const FunctionFactors& p_factors, const Compartments& p_compartments)// TODO
{
    ui->tableWidget->setRowCount(p_factors.size());
    ui->tableWidget->setColumnCount(1);
    for(int i = 0; i < p_factors.size(); i++)
    {
        double firstX = m_dataBase.getVectorOfOrdinates()[p_compartments[i].first];
        double secondX = m_dataBase.getVectorOfOrdinates()[p_compartments[i].second];
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem(QString::number(p_factors[i].first) +
                                                            " * exp(" +
                                                            QString::number(p_factors[i].second) +
                                                            " * x)  " +
                                                            "dla " +
                                                            QString::number(firstX) +
                                                            " < x < " +
                                                            QString::number(secondX)));
    }
    ui->tableWidget->show();
    ui->tableWidget->verticalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->setVisible(true);
    ui->tableWidget->setColumnWidth(0, 1000);

}

void MainWindow::showAccuracyFactors(AccuracyFactors p_factors, const Compartments& p_compartments)
{  
//    ui->standardErrorOfEstymation->setText(QString::number(p_factors[Factor::standardErrorOfEstymation]));
//    ui->standardDeviationForRegresionLine->setText(QString::number(p_factors[Factor::standardDeviationForRegresionLine]));
//    ui->coefficientOfdetermination->setText(QString::number(p_factors[Factor::coefficientOfdetermination]));
//    ui->correlationCoefficient->setText(QString::number(p_factors[Factor::correlationCoefficient]));
    ui->tableWidgetAccuracy->setRowCount(p_factors.size());
    ui->tableWidgetAccuracy->setColumnCount(1);
    for(int i = 0; i < p_factors.size(); i++)
    {
        double firstX = m_dataBase.getVectorOfOrdinates()[p_compartments[i].first];
        double secondX = m_dataBase.getVectorOfOrdinates()[p_compartments[i].second];
        ui->tableWidgetAccuracy->setItem(i, 0, new QTableWidgetItem(QString::number(
                                                                        p_factors[i][Factor::correlationCoefficient]) +
                                                            " dla " +
                                                            QString::number(firstX) +
                                                            " < x < " +
                                                            QString::number(secondX)));
    }
    ui->tableWidgetAccuracy->show();
    ui->tableWidgetAccuracy->verticalHeader()->hide();
    ui->tableWidgetAccuracy->horizontalHeader()->hide();
    ui->tableWidgetAccuracy->setVisible(true);
    ui->tableWidgetAccuracy->setColumnWidth(0, 1000);

    ui->calculator->setDisabled(true);
}

void MainWindow::clear()
{
    ui->tableWidget->clearContents();
}

void MainWindow::loadFile()
{
    m_dataBase.setDataFileName(QFileDialog::getOpenFileName());
    emit applyNewFile();
}

void MainWindow::setupMenu()
{
    connect(ui->open, SIGNAL(triggered(bool)), this, SLOT(loadFile()));
    connect(ui->calculator, SIGNAL(triggered(bool)), this, SIGNAL(calculatePressed()));
}
