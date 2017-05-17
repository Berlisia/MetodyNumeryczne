#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Src/qcustomplot.h"
#include <memory>
#include <utility>

namespace Ui {
class MainWindow;
}
class DataBase;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(DataBase& p_dataBase, QWidget *parent = 0);
    ~MainWindow();

    void setResult(const QVector<double> &p_x, const QVector<double> &p_y);
    void setInputPoints(const QVector<double> &p_x, const QVector<double> &p_y);
    void showFileOk();
    void showFactors(std::pair<double, double> p_factors);

signals:
    void applyNewFile();
    void calculatePressed();

public slots:
    void showFileError();

private slots:
    void horzScrollBarChanged(int value);
    void vertScrollBarChanged(int value);
    void xAxisChanged(QCPRange range);
    void yAxisChanged(QCPRange range);
    void loadFile();

private:
    void setupMenu();
    void setupConnectionForZoom();
    void updateAxis();

    DataBase& m_dataBase;
    Ui::MainWindow *ui;
    std::unique_ptr<QMessageBox> m_messageBox;
};

#endif // MAINWINDOW_H
