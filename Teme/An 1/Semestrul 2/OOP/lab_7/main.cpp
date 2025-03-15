#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/Tests/tests.h"
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/UI/ui.h"
using namespace std;


int main() {
    Repository repo;
    Service s{repo};
    UI console{s};
//    console.Run();
    testAll();
    return 0;
}