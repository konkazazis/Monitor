#include "monitor/parser.h"
#include <fstream>
#include <sstream>

namespace monitor {
    std::string readFile(const std::string& path) {
        std::ifstream file(path);
        std::stringstream buffer;
        if (file.is_open()) {
            buffer << file.rdbuf();
        }
        return buffer.str();
    }
}   