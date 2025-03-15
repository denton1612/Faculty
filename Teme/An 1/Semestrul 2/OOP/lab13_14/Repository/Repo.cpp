//
// Created by Știube Denis on 26.05.2024.
//

#include "Repo.h"

void Repo::addMedicament(const Medicament &newMedicament) {
    auto gasit = findMedicament(newMedicament.getDenumire(), newMedicament.getProducator());
    if (gasit || newMedicament.getDenumire().empty() || newMedicament.getProducator().empty() || newMedicament.getSubst().empty() || newMedicament.getPret() < 0)
        throw Error( "Medicamentul exista deja sau nu este valid!");
    lista.push_back(newMedicament);
}

void Repo::deleteMedicament(const Medicament& medicament) {
    auto it = std::find_if(lista.begin(), lista.end(), [&](Medicament& m){
        return m == medicament;
    });
    auto gasit = findMedicament(medicament.getDenumire(), medicament.getProducator());
    if (!gasit || medicament.getDenumire().empty() || medicament.getProducator().empty())
        throw Error("Medicamentul nu exista sau nu este valid!");
    lista.erase(it);
}

bool Repo::findMedicament(const std::string &denumire, const std::string &prod) {
    auto it = std::find_if(lista.begin(), lista.end(), [&](Medicament& m){
        return (m.getDenumire() == denumire && m.getProducator() == prod);
    });
    if (it == lista.end())
        return false;
    return true;
}

void Repo::updateMedicament(const Medicament &oldMedicament, const Medicament &newMedicament) {
    auto it = std::find_if(lista.begin(), lista.end(), [&oldMedicament](Medicament& m){return m == oldMedicament;});
    if (it == getAll().end() || oldMedicament.getDenumire().empty() || oldMedicament.getProducator().empty())
        throw Error("Medicamentul nu exista sau nu este valid!");
    lista.erase(it);
    lista.insert(it, newMedicament);
}


vector<Medicament>& Repo::getAll() {
    return lista;
}

vector<Medicament> Repo::getAllCopy() {
    return lista;
}