cmake_minimum_required(VERSION 3.27)
project(lab_2_4 C)

set(CMAKE_C_STANDARD 23)

add_executable(lab_2_4 main.c
        domain/oferte.c
        domain/oferte.h
        utils/utils.c
        utils/utils.h
        teste/teste.c
        teste/teste.h
        list/lista.c
        list/lista.h
        service/service.c
        service/service.h
        ui/ui.c
        ui/ui.h
)
