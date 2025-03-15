cmake_minimum_required(VERSION 3.27)
project(lab_7_istvan)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab_7_istvan main.cpp
        Pet.cpp
        Pet.h
        VectorDinamicTemplate.h
        Vector_iterator.cpp
        VectorIterator.h
)
