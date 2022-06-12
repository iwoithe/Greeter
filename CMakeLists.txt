cmake_minimum_required(VERSION 3.20)
project(Greet VERSION 0.1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Core Gui Quick Widgets REQUIRED)
set(QT_LIBRARIES
    Qt5::Core
    Qt5::Gui
    Qt5::Quick
    Qt5::Widgets
)

include_directories(PUBLIC
    "${PROJECT_SOURCE_DIR}/src"
)

add_subdirectory(src)

