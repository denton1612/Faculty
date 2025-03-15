//
// Created by Știube Denis on 18.05.2024.
//

#ifndef SIMULARE_1_PROCESOR_H
#define SIMULARE_1_PROCESOR_H
#include <string>
using std::string;

class procesor {

private:
    string nume;
    unsigned int nrThread;
    string soclu;
    unsigned int pret;

public:

    // constructor
    procesor(string nume, unsigned int nrThread, string soclu, unsigned int pret): nume{nume}, nrThread{nrThread}, soclu{soclu}, pret{pret} {

    }

    //returneaza numele unui procesor
    string getNume() const;

    // returneaza nr de thread uri
    unsigned int getNrThread() const;

    // returneaza soclul
    string getSoclu() const;

    // returneaza pretul
    unsigned int getPret() const;

    bool operator==(const procesor& p) {
        return nume == p.nume;
    }
};


#endif //SIMULARE_1_PROCESOR_H
