#include "monitor/processor.h"
#include "monitor/parser.h"


namespace monitor { 
    std::string Processor::GetUsage() { 
        std::string reading = readFile("/proc/stat");
        return reading; 
    }
}