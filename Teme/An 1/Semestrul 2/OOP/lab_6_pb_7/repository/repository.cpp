//
// Created by Știube Denis on 31.03.2024.
//

#include "repository.h"

void Repository::addMedicament(const Medicament &newMedicament) {
    auto gasit = findMedicament(newMedicament.getDenumire(), newMedicament.getProducator());
    if (gasit || newMedicament.getDenumire().empty() || newMedicament.getProducator().empty() || newMedicament.getSubst().empty() || newMedicament.getPret() < 0)
        throw Error( "Medicamentul exista deja!");
    lista.push_back(newMedicament);
}

void Repository::deleteMedicament(const Medicament& medicament) {
    auto it = std::find_if(lista.begin(), lista.end(), [&](Medicament& m){
        return m == medicament;
    });
    auto gasit = findMedicament(medicament.getDenumire(), medicament.getProducator());
    if (!gasit)
        throw Error("Medicamentul nu exista!");
    lista.erase(it);
}

bool Repository::findMedicament(const std::string &denumire, const std::string &prod) {
    auto it = std::find_if(lista.begin(), lista.end(), [&](Medicament& m){
        return (m.getDenumire() == denumire && m.getProducator() == prod);
    });
    if (it == lista.end())
        return false;
    return true;
}

void Repository::updateMedicament(const Medicament &oldMedicament, const Medicament &newMedicament) {
    auto it = std::find_if(lista.begin(), lista.end(), [&oldMedicament](Medicament& m){return m == oldMedicament;});
    if (it == getAll().end())
        throw Error("Medicamentul nu exista!");
    lista.erase(it);
    lista.insert(it, newMedicament);
}


vector<Medicament>& Repository::getAll() {
    return lista;
}

vector<Medicament> Repository::getAllCopy() {
    return lista;
}