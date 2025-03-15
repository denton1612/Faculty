#include <iostream>
#include <QApplication>
#include "Teste/teste.h"
#include "Controller/Controller.h"
#include "GUI/GUI.h"

int main(int argc, char** argv) {
    testAll();
    QApplication a{argc, argv};
    FileRepo repo{"utilaje.txt"};
    Controller c{repo};
    GUI gui{c};
    gui.show();
    QApplication::exec();
    return 0;
}
