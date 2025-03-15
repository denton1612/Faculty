#include <iostream>
#include <QApplication>
#include "Tests/tests.h"
#include "GUI/gui.h"
using namespace std;

int main(int argc, char** argv) {
    QApplication a{argc, argv};
    testAll();
    RepoFIle repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/melodii_2/songs.txt"};
    Validator v;
    Service s{repo, v};
    gui gui{s};
    gui.show();
    return QApplication::exec();
}
