#include <iostream>
#include <QApplication>
#include "teste/teste.h"
#include "gui/GUI.h"

int main(int argc, char** argv) {
    testAll();
    QApplication a{argc, argv};
    Lista l{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulareOficial/elevi.txt"};
    Service s{l};
    GUI console{s};
    console.show();
    return QApplication::exec();
}
