//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULARE2_SERVICE_H
#define SIMULARE2_SERVICE_H
#include "../repository/Lista.h"

class service {
private:
    Lista l;

public:
    service(Lista & l): l{l} {

    }

    void adaugaService(string strada, int supr, int pret);

    void stergeService(string strada, int supr, int pret);

    vector<Apartament> filtreazaSupr(int suprmin, int suprmax);

    vector<Apartament> filtreazaPret(int pretmin, int pretmax);

    int getSize() {
        return l.getSize();
    }

    vector<Apartament> & getAll() {
        return l.getAll();
    }
};


#endif //SIMULARE2_SERVICE_H
