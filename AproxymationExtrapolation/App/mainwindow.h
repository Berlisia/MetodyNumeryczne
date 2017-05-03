#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void setResult(const QVector<float> &p_x, const QVector<float> &p_y);
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
