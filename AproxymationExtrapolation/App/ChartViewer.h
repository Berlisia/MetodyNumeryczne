#ifndef CHARTVIEWER_H
#define CHARTVIEWER_H

#include <QDialog>
#include "Src/qcustomplot.h"

namespace Ui {
class ChartViewer;
}

class ChartViewer : public QDialog
{
    Q_OBJECT

public:
    explicit ChartViewer(QWidget *parent = 0);
    ~ChartViewer();

    void setResult(const QVector<double>& p_x, const QVector<double>& p_y);
    void setInputPoints(const QVector<double>& p_x, const QVector<double>& p_y);

private slots:
    void horzScrollBarChanged(int value);
    void vertScrollBarChanged(int value);
    void xAxisChanged(QCPRange range);
    void yAxisChanged(QCPRange range);

private:
    void setupConnectionForZoom();
    void updateAxis(const QVector<double> &p_x, const QVector<double> &p_y);

    Ui::ChartViewer *ui;
};

#endif // CHARTVIEWER_H
