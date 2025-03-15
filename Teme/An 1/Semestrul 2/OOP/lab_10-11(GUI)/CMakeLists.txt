cmake_minimum_required(VERSION 3.28)
project(lab_6_pb_7)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "/Users/stiubedenis/Downloads/Qt/6.8.0/macos/lib/cmake")


add_executable(lab_6_pb_7 main.cpp
        domain/Medicament.cpp
        domain/Medicament.h
        tests/tests.cpp
        tests/tests.h
        repository/repository.cpp
        repository/repository.h
        service/service.cpp
        service/service.h
        ui/FarmacieGUI.cpp
        ui/FarmacieGUI.h
        validare/errors.cpp
        validare/errors.h
        reteta/reteta.cpp
        reteta/reteta.h
        repository/inFileRepository.cpp
        repository/inFileRepository.h
        utils/utils.cpp
        utils/utils.h
        undo/undo.cpp
        undo/undo.h
        repository/repoAbstract.h
        ui/RetetaGUI.cpp
        ui/RetetaGUI.h
        Observer/Observable.cpp
        Observer/Observable.h
        Observer/Observer.h
)

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

target_link_libraries(lab_6_pb_7
        Qt::Core
        Qt::Gui
        Qt::Widgets
)