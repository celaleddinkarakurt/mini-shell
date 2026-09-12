cmake_minimum_required(VERSION 3.15)
project(TextEditor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(text_editor
    src/main.cpp
    src/terminal.cpp
    src/editor.cpp
    src/file_manager.cpp
    src/command.cpp
    src/app_state.cpp
)