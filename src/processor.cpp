#include "monitor/processor.h"
#include "monitor/parser.h"


namespace monitor { 
    std::string Processor::GetUsage() { 
        std::string firstLine = readFirstLine("/proc/stat");
        return firstLine; 
    }
}