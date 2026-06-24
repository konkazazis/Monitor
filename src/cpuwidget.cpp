#include "cpuwidget.h"
#include "monitor/processor.h"
#include "monitor/parser.h"
#include <iostream>
#include <thread>
#include <chrono>

CpuWidget::CpuWidget(QWidget *parent) : QWidget(parent)
{
    monitor::CpuSnapshot s1 = monitor::takeSnapshot();
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    monitor::CpuSnapshot s2 = monitor::takeSnapshot();

    float usage = monitor::Processor::GetUsage(s1, s2);
    std::cout << "CPU usage: " << usage << "%\n";
}