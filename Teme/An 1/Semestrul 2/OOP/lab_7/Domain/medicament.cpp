//
// Created by Știube Denis on 29.03.2024.
//

#include "medicament.h"
#include <iostream>
using namespace std;

string Medicament::getDenumire() const {
    return denumire;
}

double Medicament::getPret() const {
    return pret;
}

string Medicament::getProducator() const {
    return producator;
}

string Medicament::getSubst() const {
    return subst;
}

void Medicament::setPret(const double &newPret) {
    this->pret = newPret;
}

void Medicament::setSubst(const string& newSubst) {
    this->subst = newSubst;
}

bool Medicament::operator==(const Medicament &ot) {
    if (denumire == ot.denumire && pret == ot.pret && producator == ot.producator && subst == ot.subst)
        return true;
    return false;
}

bool Medicament::operator!=(const Medicament &ot) {
    return !(*this == ot);
}
