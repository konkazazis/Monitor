cmake_minimum_required(VERSION 3.20)
project(sys_monitor VERSION 0.1.0 LANGUAGES CXX)

# Require C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- Fetch Dependencies ---
include(FetchContent)

# FTXUI
FetchContent_Declare(
  ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

# CLI11
FetchContent_Declare(
  cli11
  GIT_REPOSITORY https://github.com/CLIUtils/CLI11
  GIT_TAG v2.4.0
)
FetchContent_MakeAvailable(cli11)

# --- Executable ---
add_executable(monitor
    src/main.cpp
    src/system.cpp
    src/processor.cpp
    src/memory.cpp
    src/parser.cpp
)

target_link_libraries(monitor PRIVATE 
    ftxui::screen
    ftxui::dom
    ftxui::component
    CLI11::CLI11
)   

target_include_directories(monitor PRIVATE ${CMAKE_SOURCE_DIR}/include)   