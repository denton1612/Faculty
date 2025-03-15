//
// Created by Știube Denis on 31.03.2024.
//

#include "service.h"


void Service::addMedicament(const string& denumire, const double& pret, const string& producator,
                            const string& subst) {
    Medicament newMedicament{denumire, pret, producator, subst};
    repo.addMedicament(newMedicament);
}

void Service::deleteMedicament(const int& poz) {
    repo.deleteMedicament(poz-1);
}

void Service::updatePret(const int& poz, const double& newPret) {
    repo.updatePret(poz-1, newPret);
}

void Service::updateSubst(const int& poz, const string& newSubst) {
    repo.updateSubst(poz-1, newSubst);
}

bool Service::findMedicament(const string& denumire, const string& producator) const {
    VectorDinamic<Medicament> medicamente = getAll();
    for (Medicament& m : medicamente){
        if (m.getDenumire() == denumire && m.getProducator() == producator)
            return true;
    }
    return false;
}

VectorDinamic<Medicament> Service::filtruPret(const double &pret) const {
    VectorDinamic<Medicament> medicamenteFiltrate;
    for (Medicament& m : getAll()){
        if (m.getPret() == pret)
            medicamenteFiltrate.push_back(m);
    }
    return medicamenteFiltrate;
}

VectorDinamic<Medicament> Service::filtruSubst(const string &subst) const {
    VectorDinamic<Medicament> medicamenteFiltrate;
    for (Medicament& m : getAll()){
        if (m.getSubst() == subst)
            medicamenteFiltrate.push_back(m);
    }
    return medicamenteFiltrate;
}

VectorDinamic<Medicament> Service::sortareDenumire() {
    VectorDinamic<Medicament> sortat = getAll();
    auto sorted = false;
    while (!sorted){
        sorted = true;
        for (int i = 0; i < sortat.getSize()-1; i++){
            if (sortat[i].getDenumire() > sortat[i+1].getDenumire()){
                sorted = false;
                swap(sortat[i], sortat[i+1]);
            }
        }
    }
    return sortat;
}

VectorDinamic<Medicament> Service::sortareProducator() {
    VectorDinamic<Medicament> sortat = getAll();
    auto sorted = false;
    while (!sorted){
        sorted = true;
        for (int i = 0; i < sortat.getSize()-1; i++){
            if (sortat[i].getProducator() > sortat[i+1].getProducator()){
                sorted = false;
                swap(sortat[i], sortat[i+1]);
            }
        }
    }
    return sortat;
}

VectorDinamic<Medicament> Service::sortareSubstPret() {
    VectorDinamic<Medicament> sortat = getAll();
    auto sorted = false;
    while (!sorted){
        sorted = true;
        for (int i = 0; i < sortat.getSize()-1; i++){
            if (sortat[i].getPret() > sortat[i+1].getPret()){
                sorted = false;
                swap(sortat[i], sortat[i+1]);
            }
        }
    }
    sorted = false;
    while (!sorted){
        sorted = true;
        for (int i = 0; i < sortat.getSize()-1; i++){
            if (sortat[i].getSubst() > sortat[i+1].getSubst()){
                sorted = false;
                swap(sortat[i], sortat[i+1]);
            }
        }
    }
    return sortat;
}

