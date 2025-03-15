#include <iostream>
#include "teste/teste.h"
#include "repository/Lista.h"
#include "service/service.h"
#include "ui/Console.h"
#include <QApplication>

int main(int argc, char** argv) {
    testAll();
    Lista l{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare2/apartamente"};
    service s{l};
    QApplication a{argc, argv};
    Console gui{s};
    gui.show();
    return a.exec();
}
