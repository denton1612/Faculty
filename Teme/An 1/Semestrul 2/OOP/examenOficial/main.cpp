#include <iostream>
#include <QApplication>
using namespace std;
#include "Tests/tests.h"
#include "GUI/gui.h"

int main(int argc, char** argv) {
    QApplication a{argc, argv};
    testAll();
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/examenOficial/parcari.txt"};
    service s{repo};
    gui gui{s};
    gui.show();
    return QApplication::exec();
}
