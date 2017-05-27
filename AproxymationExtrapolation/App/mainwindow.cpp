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
    ui->valueGet->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setResult(const QVector<double>& p_x, const QVector<double>& p_y)
{
    m_chartViewer->setResult(p_x,p_y);
    ui->valueGet->setEnabled(true);
}

void MainWindow::setInputPoints(const QVector<double>& p_x, const QVector<double>& p_y)
{
    m_chartViewer.reset();
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

void MainWindow::showFactors(std::pair<double, double> p_factors)
{
    ui->factorA->setText(QString::number(p_factors.first));
    ui->factorB->setText(QString::number(p_factors.second));
}

void MainWindow::showAccuracyFactors(std::map<Factor, double> p_factors)
{  
    ui->standardErrorOfEstymation->setText(QString::number(p_factors[Factor::standardErrorOfEstymation]));
    ui->standardDeviationForRegresionLine->setText(QString::number(p_factors[Factor::standardDeviationForRegresionLine]));
    ui->coefficientOfdetermination->setText(QString::number(p_factors[Factor::coefficientOfdetermination]));
    ui->correlationCoefficient->setText(QString::number(p_factors[Factor::correlationCoefficient]));
}

void MainWindow::clear()
{
    ui->factorA->clear();
    ui->factorB->clear();

    ui->coefficientOfdetermination->clear();
    ui->correlationCoefficient->clear();
    ui->standardDeviationForRegresionLine->clear();
    ui->standardErrorOfEstymation->clear();

    ui->valueDisplay->clear();

    //m_chartViewer->done(1);
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

void MainWindow::setConnectionForValueGetter()
{

}
