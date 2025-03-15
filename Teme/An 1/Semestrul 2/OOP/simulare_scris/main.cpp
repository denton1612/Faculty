#include <iostream>
#include <string>
#include <list>
using namespace std;

class Smoothy {
private:
    int pret;
public:
    Smoothy(int & pret): pret{pret} {

    }
    int getPret() {
        return pret;
    }
    virtual string descriere() = 0;
};

class DecoratorSmoothy {
    pri
};