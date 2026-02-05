cmake_minimum_required(VERSION 4.1)
project(somenewqt6)
option(USE_BUNDLED_LIBS "Use bundled libraries instead of system libraries" ON)
set(CMAKE_CXX_STANDARD 26)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
if(USE_BUNDLED_LIBS)
    add_subdirectory(vendor/SDL EXCLUDE_FROM_ALL)
    add_subdirectory(vendor/SDL_image EXCLUDE_FROM_ALL)
    add_subdirectory(vendor/SDL_ttf EXCLUDE_FROM_ALL)
else()
    find_package(SDL3 REQUIRED)
    find_package(SDL3_image REQUIRED)
    find_package(SDL3_ttf REQUIRED)
endif()

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(somenewqt6 main.cpp
        login.cpp
        login.hpp
        login.ui
        register.cpp
        register.hpp
        register.ui
        home.cpp
        home.hpp
        home.ui
        sdl3game1_desc.cpp
        sdl3game1_desc.hpp
        sdl3game1_desc.ui
        sdl3game2_desc.cpp
        sdl3game2_desc.hpp
        sdl3game2_desc.ui
        sdl3game3_desc.cpp
        sdl3game3_desc.hpp
        sdl3game3_desc.ui
        sdl3game4_desc.cpp
        sdl3game4_desc.hpp
        sdl3game4_desc.ui
)
add_library(games SHARED
        sdl3game1.cpp
        sdl3game1.hpp
)
target_link_libraries(games PRIVATE
        SDL3::SDL3
        SDL3_image::SDL3_image
        SDL3_ttf::SDL3_ttf
)
target_link_libraries(somenewqt6
        Qt::Core
        Qt::Gui
        Qt::Widgets
        games
)

