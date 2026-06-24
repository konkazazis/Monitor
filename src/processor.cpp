#include "monitor/processor.h"
#include "monitor/parser.h"
#include <sstream>

namespace monitor
{
    CpuSnapshot takeSnapshot()
    {
        std::string line = readFirstLine("/proc/stat");
        std::istringstream ss(line);
        CpuSnapshot s;
        std::string label;
        ss >> label >> s.user >> s.nice >> s.system >> s.idle >> s.iowait >> s.irq >> s.softirq >> s.steal;
        return s;
    }

    float Processor::GetUsage()
    {
        CpuSnapshot s2 = takeSnapshot();

        long idle1 = m_lastSnapshot.idle + m_lastSnapshot.iowait;
        long idle2 = s2.idle + s2.iowait;

        long total1 = m_lastSnapshot.user + m_lastSnapshot.nice + m_lastSnapshot.system + m_lastSnapshot.idle + m_lastSnapshot.iowait + m_lastSnapshot.irq + m_lastSnapshot.softirq + m_lastSnapshot.steal;

        long total2 = s2.user + s2.nice + s2.system + s2.idle + s2.iowait + s2.irq + s2.softirq + s2.steal;

        long idle_diff = idle2 - idle1;
        long total_diff = total2 - total1;

        m_lastSnapshot = s2;

        if (total_diff == 0)
            return 0.0f;
        return (float)(total_diff - idle_diff) / total_diff * 100.0f;
    }
}