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

    connect(ui->openButton, SIGNAL(pressed()), this, SLOT(loadFile()));
    connect(ui->calculateButton, SIGNAL(pressed()), this, SIGNAL(calculatePressed()));
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
    m_chartViewer.reset();
    m_chartViewer = std::make_unique<ChartViewer>(this);
    m_chartViewer->setInputPoints(p_x, p_y);
    m_chartViewer->show();
}

void MainWindow::showFileError()
{
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->critical(0, "Error", "I can't open file!");
    m_messageBox->setFixedSize(500, 200);
    m_messageBox->show();
}

void MainWindow::showFileOk()
{
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->setText("Data has been imported.");
    m_messageBox->addButton(QMessageBox::Ok);
    m_messageBox->show();
}

void MainWindow::showFactors(std::pair<double, double> p_factors)
{
    m_messageBox = std::make_unique<QMessageBox>();
    m_messageBox->setText("A = " + QString::number(p_factors.first) + " B = " + QString::number(p_factors.second));
    m_messageBox->addButton("OK", QMessageBox::AcceptRole);
    m_messageBox->show();
}

void MainWindow::showAccuracyFactors(std::map<Factor, double> p_factors)
{
    std::unique_ptr<QStandardItemModel> model = std::make_unique<QStandardItemModel>(4, 2, this);
    const QStringList headerList = {"Błąd standardowy estymacji", "Odchylenie standardowe",
                              "Współczynnik determinacji", "Współczynnik korelacji"};
    model->setVerticalHeaderLabels(headerList);
    model->setHeaderData(0, Qt::Vertical, QObject::tr("Błąd standardowy estymacji"));

    std::unique_ptr<QStandardItem> Sr = std::make_unique<QStandardItem>(QString::number(p_factors[Factor::standardErrorOfEstymation]));
    std::unique_ptr<QStandardItem> Syx = std::make_unique<QStandardItem>(QString::number(p_factors[Factor::standardDeviationForRegresionLine]));
    std::unique_ptr<QStandardItem> r2 = std::make_unique<QStandardItem>(QString::number(p_factors[Factor::coefficientOfdetermination]));
    std::unique_ptr<QStandardItem> r = std::make_unique<QStandardItem>(QString::number(p_factors[Factor::correlationCoefficient]));
    model->setItem(0,0,Sr.get());
    model->setItem(1,0,Syx.get());
    model->setItem(2,0,r2.get());
    model->setItem(3,0,r.get());

    ui->accuracyView->setModel(model.get());

//    m_messageBox = std::make_unique<QMessageBox>();
//    m_messageBox->setText("sumOfsquaresOfDeviations St = " + QString::number(p_factors[Factor::sumOfsquaresOfDeviations]) + "\n" +
//                          "standardDeviation Sy = " + QString::number(p_factors[Factor::standardDeviation]) + "\n" +
//                          "standardErrorOfEstymation Sr = " + QString::number(p_factors[Factor::standardErrorOfEstymation]) + "\n" +
//                          "standardDeviationForRegresionLine Sy/x = " + QString::number(p_factors[Factor::standardDeviationForRegresionLine]) + "\n" +
//                          "correlationCoefficient r = " + QString::number(p_factors[Factor::correlationCoefficient]));
//    m_messageBox->addButton("OK",QMessageBox::AcceptRole);
//    m_messageBox->show();
}

void MainWindow::loadFile()
{
    m_dataBase.setDataFileName(QFileDialog::getOpenFileName());
    emit applyNewFile();
}

void MainWindow::setupMenu()
{
    QMenu* mainMenu = new QMenu(tr("&Menu"), this);
    QMainWindow::menuBar()->addMenu(mainMenu);
    mainMenu->addAction(tr("&Open"), this, SLOT(loadFile()));
    mainMenu->addAction(tr("&Calculate"), this, SIGNAL(calculatePressed()));
    mainMenu->addAction(tr("&Quit"), this, SLOT(close()));
}
