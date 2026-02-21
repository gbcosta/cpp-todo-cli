cmake_minimum_required(VERSION 3.14)
project(cppTodoCli)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(ftxui 
    GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui
    GIT_TAG main
)

FetchContent_MakeAvailable(ftxui)

add_executable(cppTodoCli src/main.cpp)

target_link_libraries(cppTodoCli PRIVATE ftxui::screen ftxui::dom ftxui::component)
