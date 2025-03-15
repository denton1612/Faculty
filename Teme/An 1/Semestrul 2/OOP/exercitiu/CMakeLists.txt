cmake_minimum_required(VERSION 3.28)
project(exercitiu)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.5.3/macos/lib/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(exercitiu main.cpp)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(
        exercitiu
        Qt::Core
        Qt::Gui
        Qt::Widgets
)