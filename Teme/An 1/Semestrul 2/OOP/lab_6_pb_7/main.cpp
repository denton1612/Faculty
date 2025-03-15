#include "tests/tests.h"
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_6_pb_7/ui/UI.h"
using namespace std;


int main() {
    Repository repo;
    InFileRepository repoF{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_6_pb_7/farmacie.txt"};
    Reteta reteta;
    Service s{repoF, reteta};
    UI console{s};
    console.Run();
    testAll();
    return 0;
}
