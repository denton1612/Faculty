cmake_minimum_required(VERSION 3.28)
project(simulare_1)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.8.0/macos/lib/cmake")

add_executable(simulare_1 main.cpp
        domain/procesor.h
        domain/procesor.cpp
        domain/placaDeBaza.h
        domain/placaDeBaza.h
        domain/placaDeBaza.cpp
        teste/teste.cpp
        teste/teste.h
        repository/repo.cpp
        repository/repo.h
        validare/eroare.cpp
        validare/eroare.h
        utils/utils.cpp
        utils/utils.h
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(simulare_1
        Qt::Core
        Qt::Gui
        Qt::Widgets
)