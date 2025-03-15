//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULAREOFICIAL_ELEV_H
#define SIMULAREOFICIAL_ELEV_H
#include <string>
#include <vector>
using namespace std;

class Elev {
private:
    int nrMatricol;
    string nume;
    string scoala;
    string ateliere;

public:

    // constructor
    Elev(int nr, string nume, string scoala, string ateliere): nrMatricol{nr}, nume{nume}, scoala{scoala}, ateliere{ateliere} {

    }

    // getter nr
    int getNr() {
        return nrMatricol;
    }

    // getter nume
    string getNume() {
        return nume;
    }

    // getter scoala
    string getScoala() {
        return scoala;
    }

    // getter atelier
    string getAteliere() {
        return ateliere;
    }


    bool operator==(Elev & el);
};


#endif //SIMULAREOFICIAL_ELEV_H
