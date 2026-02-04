cmake_minimum_required(VERSION 4.1)
project(somenewqt6)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(somenewqt6 main.cpp)
target_link_libraries(somenewqt6
        Qt::Core
        Qt::Gui
        Qt::Widgets
)

