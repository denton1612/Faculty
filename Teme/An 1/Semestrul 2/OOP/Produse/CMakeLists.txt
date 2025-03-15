cmake_minimum_required(VERSION 3.27)
project(Produse)

set(CMAKE_CXX_STANDARD 17)

add_executable(Produse main.cpp
        Domain/Produs.h
        Domain/Produs.cpp
        Teste/teste.h
        Teste/teste.cpp
        Repo/RepoFile.h
        Repo/RepoFile.cpp
        Service/Service.h
        Service/Service.cpp
        Validari/validare.h
        Validari/validare.cpp
        Exception/Exception.h
        TabelModel/TableModel.h
        TabelModel/TableModel.cpp
        GUI/ProdusGui.h
        GUI/ProdusGui.cpp
        Observer/Observer.h
        Observer/Observable.h
        MiniGui/MiniGui.h
        MiniGui/MiniGui.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.5.3/macos/lib/cmake")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(Produse
        Qt::Core
        Qt::Gui
        Qt::Widgets
)