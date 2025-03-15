//
// Created by Știube Denis on 31.03.2024.
//

#include "repository.h"

void Repository::addMedicament(const Medicament &newMedicament) {
    for (Medicament& m : lista){
        if (m == newMedicament) {
            throw Error("Medicamentul exista deja!");
        }
    }
    lista.push_back(newMedicament);
}

void Repository::deleteMedicament(const int& poz) {
    if ((lista.begin()+poz) > lista.end()-1)
        throw Error("Nu exista acest medicament!");
    lista.erase(lista.begin()+poz);
}

void Repository::updatePret(const int& poz, const double &newPret) {
    Medicament old = lista[poz];
    Medicament newMedicament{old.getDenumire(), newPret, old.getProducator(), old.getSubst()};
    lista[poz] = newMedicament;
}

void Repository::updateSubst(const int& poz, const string &newSubst) {
    Medicament old = lista[poz];
    Medicament newMedicament{old.getDenumire(), old.getPret(), old.getProducator(), newSubst};
    lista[poz] = newMedicament;
}

Medicament& Repository::operator[](const int& poz) {
    return lista[poz];
}

VectorDinamic<Medicament> Repository::getAll() const {
    return lista;
}