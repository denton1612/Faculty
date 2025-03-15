cmake_minimum_required(VERSION 3.28)
project(simulare_agricole)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.8.0/macos/lib/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(simulare_agricole main.cpp
        Domain/Utilaj.cpp
        Domain/Utilaj.h
        Teste/teste.cpp
        Teste/teste.h
        Repository/Repo.cpp
        Repository/Repo.h
        Exceptions/Exceptii.cpp
        Exceptions/Exceptii.h
        Utils/utils.cpp
        Utils/utils.h
        Controller/Controller.cpp
        Controller/Controller.h
        GUI/GUI.cpp
        GUI/GUI.h
        TableModel/TableModel.cpp
        TableModel/TableModel.h)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(
        simulare_agricole
        Qt::Core
        Qt::Gui
        Qt::Widgets
)