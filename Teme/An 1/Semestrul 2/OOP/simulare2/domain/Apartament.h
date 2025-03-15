//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULARE2_APARTAMENT_H
#define SIMULARE2_APARTAMENT_H
#include <string>
using namespace std;

class Apartament {
private:
    string strada;
    int suprafata;
    int pret;

public:
    Apartament(string  strada, int  suprafata, int  pret): suprafata{suprafata}, strada{strada}, pret{pret} {

    }

    int getSuprafata() {
        return suprafata;
    }

    string getStrada() {
        return strada;
    }

    int getPret() {
        return pret;
    }

    bool operator==(Apartament ap) {
        return (suprafata == ap.getSuprafata() and strada == ap.getStrada() and pret == ap.getPret());
    }

};


#endif //SIMULARE2_APARTAMENT_H
