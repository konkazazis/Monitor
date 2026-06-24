#include "monitor/parser.h"
#include <fstream>
#include <sstream>

namespace monitor {
    std::string readFirstLine(const std::string& path) {
        std::ifstream file(path);
        std::string firstLine;
            if (file.is_open()) {
                std::getline(file, firstLine);
            }
                return firstLine;
}
}   