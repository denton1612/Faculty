cmake_minimum_required(VERSION 3.28)
project(simulare2)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.8.0/macos/lib/cmake")

add_executable(simulare2 main.cpp
        domain/Apartament.cpp
        domain/Apartament.h
        teste/teste.cpp
        teste/teste.h
        repository/Lista.cpp
        repository/Lista.h
        eroare.h
        utils/utils.cpp
        utils/utils.h
        service/service.cpp
        service/service.h
        ui/Console.cpp
        ui/Console.h)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(simulare2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)