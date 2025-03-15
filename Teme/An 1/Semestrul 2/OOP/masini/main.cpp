#include <iostream>
#include "../masini/Tests/tests.h"
#include "GUI/gui.h"
#include <QApplication>

int main(int argc, char** argv) {
    QApplication a(argc, argv);
    testAll();
    FileRepo repo {"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/masini/cars.txt"};
    service s{repo};
    gui gui{s};
    gui.show();
    return QApplication::exec();
    return 0;
}
