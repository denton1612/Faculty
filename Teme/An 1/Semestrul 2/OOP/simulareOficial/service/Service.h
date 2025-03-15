//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULAREOFICIAL_SERVICE_H
#define SIMULAREOFICIAL_SERVICE_H
#include "../repository/Lista.h"
#include <algorithm>
#include <map>
using namespace std;

class Service {
private:
    Lista & elevi;
    map<char, string> ateliere;

    // construieste dictionarul ce contine codificarea atelierelor
    void build();

public:
    Service(Lista & l): elevi{l} {
        build();
    }

    // sorteaza elevii
    void sortareNume();

    // cauta un elev dupa nume
    Elev find(string nume);

    // returneaza atelierele unui elev
    vector<string> getAteliere(Elev & e);

    // returneaza elevii
    vector<Elev> & getAll();
};


#endif //SIMULAREOFICIAL_SERVICE_H
