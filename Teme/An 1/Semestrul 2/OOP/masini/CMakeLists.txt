cmake_minimum_required(VERSION 3.28)
project(masini)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.5.3/macos/lib/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(masini main.cpp
        Domain/Car.cpp
        Domain/Car.h
        Tests/tests.cpp
        Tests/tests.h
        FileRepo/FileRepo.cpp
        FileRepo/FileRepo.h
        Exceptions/exceptions.cpp
        Exceptions/exceptions.h
        Service/service.cpp
        Service/service.h
        GUI/gui.cpp
        GUI/gui.h
        TableModel/TableModel.cpp
        TableModel/TableModel.h)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(
        masini
        Qt::Core
        Qt::Gui
        Qt::Widgets
)