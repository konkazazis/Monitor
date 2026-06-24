#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include "CLI/CLI.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/dom/elements.hpp"
#include "monitor/system.h"

int main(int argc, char **argv)
{
    CLI::App app{"System Resource Monitor"};
    int refresh_rate{1};
    app.add_option("-r,--refresh", refresh_rate, "Refresh rate in seconds");
    CLI11_PARSE(app, argc, argv);

    monitor::System sys;
    std::atomic<float> cpu_usage{0.0f};
    auto screen = ftxui::ScreenInteractive::FitComponent();

    std::thread updater([&]
                        {
        while (true) {
            std::this_thread::sleep_for(std::chrono::seconds(refresh_rate));
            cpu_usage = sys.cpu.GetUsage();
            screen.PostEvent(ftxui::Event::Custom);
    } });

    updater.detach();

    auto root = ftxui::Renderer([&]
                                { return ftxui::vbox({ftxui::text("CPU: " + std::to_string(cpu_usage.load()) + "%"),
                                                      ftxui::text("Press Ctrl+C to exit")}); });

    screen.Loop(root);

    return 0;
}