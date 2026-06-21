#include <iostream>
#include "CLI/CLI.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "monitor/system.h"

int main(int argc, char** argv) {
    // CLI Parsing
    CLI::App app{"System Resource Monitor"};
    int refresh_rate{1};
    app.add_option("-r,--refresh", refresh_rate, "Refresh rate in seconds");
    CLI11_PARSE(app, argc, argv);

    // FTXUI Setup
    monitor::System sys;
    auto root = ftxui::Renderer([&] {
        return ftxui::vbox({
            ftxui::text("CPU: " + std::to_string(sys.cpu.GetUsage())),
            ftxui::text("RAM: " + std::to_string(sys.ram.GetUsage())),
            ftxui::text("Press Ctrl+C to exit")
        });
    });

    auto screen = ftxui::ScreenInteractive::FitComponent();
    screen.Loop(root);

    return 0;
}   