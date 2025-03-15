cmake_minimum_required(VERSION 3.27)
project(DictOrdo)

set(CMAKE_CXX_STANDARD 23)

add_executable(DictOrdo Proiect/App.cpp
        Proiect/DO.cpp
        Proiect/Iterator.cpp
        Teste/TestExtins.cpp
        Teste/TestExtins.h
        Teste/TestScurt.cpp
        Teste/TestScurt.h
        Proiect/DO.h
        Proiect/Iterator.h)
