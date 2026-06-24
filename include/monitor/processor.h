#ifndef MONITOR_PROCESSOR_H
#define MONITOR_PROCESSOR_H

namespace monitor
{
    struct CpuSnapshot
    {
        long user, nice, system, idle, iowait, irq, softirq, steal;
    };

    CpuSnapshot takeSnapshot();

    class Processor
    {
    public:
        float GetUsage();

    private:
        CpuSnapshot m_lastSnapshot;
    };
}

#endif