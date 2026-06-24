#ifndef CPUWIDGET_H
#define CPUWIDGET_H

#include <QWidget>

class CpuWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CpuWidget(QWidget *parent = nullptr);
};

#endif // CPUWIDGET_H