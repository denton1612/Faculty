cmake_minimum_required(VERSION 3.28)
project(simulareOficial)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.8.0/macos/lib/cmake")

add_executable(simulareOficial main.cpp
        domain/Elev.cpp
        domain/Elev.h
        teste/teste.cpp
        teste/teste.h
        repository/Lista.cpp
        repository/Lista.h
        utils/utils.cpp
        utils/utils.h
        service/Service.cpp
        service/Service.h
        gui/GUI.cpp
        gui/GUI.h
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(simulareOficial
        Qt::Core
        Qt::Gui
        Qt::Widgets
)