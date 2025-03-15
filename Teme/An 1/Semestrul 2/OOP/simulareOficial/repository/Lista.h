//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULAREOFICIAL_LISTA_H
#define SIMULAREOFICIAL_LISTA_H
#include "../domain/Elev.h"
#include "../utils/utils.h"
#include <fstream>
using namespace std;

class Lista {
private:
    vector<Elev> elevi;
    string filename;

    // incarca datele din fisier
    void loadFromFile();

public:
    Lista(const string filename): filename{filename} {
        loadFromFile();
    }

    // returneaza un elev dupa nume
    Elev findByNume(string nume);

    // retunreaza elevii
    vector<Elev> & getAll();

    // returneaza nr elevilor
    int getSize();
};


#endif //SIMULAREOFICIAL_LISTA_H
