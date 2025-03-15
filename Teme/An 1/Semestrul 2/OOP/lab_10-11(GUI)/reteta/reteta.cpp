//
// Created by Știube Denis on 14.04.2024.
//

#include "reteta.h"

void Reteta::addMedicament(const Medicament &med) {
    lista.push_back(med);
}

void Reteta::deleteAll() {
    lista.clear();
}