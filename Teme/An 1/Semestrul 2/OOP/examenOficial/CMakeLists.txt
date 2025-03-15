cmake_minimum_required(VERSION 3.28)
project(examenOficial)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.5.3/macos/lib/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(examenOficial main.cpp
        Domain/Parcare.cpp
        Domain/Parcare.h
        Tests/tests.cpp
        Tests/tests.h
        FileRepo/FileRepo.cpp
        FileRepo/FileRepo.h
        Service/service.cpp
        Service/service.h
        Utils/utils.cpp
        Utils/utils.h
        GUI/gui.cpp
        GUI/gui.h
        GUI/parcaregui.cpp
        GUI/parcaregui.h
        Observer/Observer.cpp
        Observer/Observer.h)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(
        examenOficial
        Qt::Core
        Qt::Gui
        Qt::Widgets
)