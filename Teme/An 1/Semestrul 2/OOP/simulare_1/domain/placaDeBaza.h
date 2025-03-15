//
// Created by Știube Denis on 18.05.2024.
//

#ifndef SIMULARE_1_PLACADEBAZA_H
#define SIMULARE_1_PLACADEBAZA_H
#include <string>
using std::string;

class placaDeBaza {

private:
    string nume;
    string soclu;
    unsigned int pret;

public:
    // constructor
    placaDeBaza(string nume, string soclu, unsigned int pret): nume{nume}, soclu{soclu}, pret{pret} {

    }

    // returneaza numele
    string getNume() const;

    // returneaza soclul
    string getSoclu() const;

    // returneaza pretul
    unsigned int getPret() const;

    bool operator==(const placaDeBaza& pb) {
        return nume == pb.nume;
    }
};


#endif //SIMULARE_1_PLACADEBAZA_H
