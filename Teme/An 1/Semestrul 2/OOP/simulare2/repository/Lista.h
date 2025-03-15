//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULARE2_LISTA_H
#define SIMULARE2_LISTA_H
#include "../domain/Apartament.h"
#include "../eroare.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
using namespace std;

class Lista {
private:
    vector<Apartament> aps;
    string filename;
    void loadFromFile();
    void saveToFile();

public:
    Lista(const string & filename): filename{filename} {
        loadFromFile();
    }

    vector<Apartament> getAllCopie() {
        return aps;
    }

    vector<Apartament> &getAll() {
        return aps;
    }

    void adauga(Apartament & ap);

    void sterge(Apartament & ap);

    int getSize() {
        return aps.size();
    }
};

#endif //SIMULARE2_LISTA_H
