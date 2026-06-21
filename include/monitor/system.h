#ifndef MONITOR_SYSTEM_H
#define MONITOR_SYSTEM_H
#include "monitor/processor.h"
#include "monitor/memory.h"
namespace monitor { class System { public: Processor cpu; Memory ram; }; }
#endif