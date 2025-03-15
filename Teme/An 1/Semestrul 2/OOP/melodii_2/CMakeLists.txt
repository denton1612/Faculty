cmake_minimum_required(VERSION 3.28)
project(melodii_2)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.5.3/macos/lib/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

add_executable(melodii_2 main.cpp
        Domain/Song.cpp
        Domain/Song.h
        Tests/tests.cpp
        Tests/tests.h
        FileRepository/RepoFIle.cpp
        FileRepository/RepoFIle.h
        Exceptions/Error.cpp
        Exceptions/Error.h
        Service/Service.cpp
        Service/Service.h
        Validator/Validator.cpp
        Validator/Validator.h
        GUI/gui.cpp
        GUI/gui.h
        TableModel/TableModel.cpp
        TableModel/TableModel.h
        GUI/drawing.cpp
        GUI/drawing.h)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(
        melodii_2
        Qt::Core
        Qt::Gui
        Qt::Widgets
)