#include "tests/tests.h"
#include "ui/FarmacieGUI.h"
#include "ui/RetetaGUI.h"
#include "service/service.h"
using namespace std;


int main(int argc, char** argv) {
    testAll();
    Repository repo;
    InFileRepository repoF{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_10-11(GUI)/farmacie.txt"};
    Reteta reteta;
    Service s{repoF, reteta};
    QApplication a{argc, argv};
    FarmacieGUI farmaciegui{s};
    RetetaGUI retetagui{s};
    farmaciegui.run();
    retetagui.show();
    return QApplication::exec();
}
