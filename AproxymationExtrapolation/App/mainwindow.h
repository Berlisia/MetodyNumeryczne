#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Src/Accuracy.h"
#include "ChartViewer.h"
#include "Src/Calculator.h"

#include <memory>
#include <utility>

namespace Ui
{
class MainWindow;
}
class DataBase;
class QMessageBox;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DataBase& p_dataBase, QWidget *parent = 0);
    ~MainWindow();

    void setResult(const QVector<double> &p_x, const QVector<double> &p_y);
    void setInputPoints(const QVector<double> &p_x, const QVector<double> &p_y);
    void showFileOk();
    void showFactors(FunctionFactors p_factors);
    void showAccuracyFactors(std::map<Factor, double> p_factors);
    void showValueYFromValueX(double p_valueY);
    void clear();

signals:
    void applyNewFile();
    void calculatePressed();
    void YValueTriggered(double);

public slots:
    void showFileError();

private slots:
    void loadFile();

private:
    void setupMenu();
    void setConnectionForValueGetter();

    DataBase& m_dataBase;
    Ui::MainWindow *ui;
    std::unique_ptr<QMessageBox> m_messageBox;
    std::unique_ptr<ChartViewer> m_chartViewer;
};

#endif // MAINWINDOW_H
