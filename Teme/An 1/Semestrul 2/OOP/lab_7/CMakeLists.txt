cmake_minimum_required(VERSION 3.27)
project(lab_7)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab_7 main.cpp
        Domain/medicament.cpp
        Domain/medicament.h
        Repository/repository.cpp
        Repository/repository.h
        Service/service.cpp
        Tests/tests.cpp
        Tests/tests.h
        UI/ui.cpp
        List/list.cpp
        List/list.h
        Service/service.h
        UI/ui.h
        List/iterator.cpp
        List/iterator.h
        Validare/Validare.cpp
        Validare/Validare.h
        Validare/Validare.h)
