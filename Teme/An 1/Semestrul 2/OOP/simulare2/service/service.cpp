//
// Created by Știube Denis on 20.05.2024.
//

#include "service.h"

void service::adaugaService(std::string strada, int supr, int pret) {
    if (strada.empty())
        throw eroare("Strada invalida!");
    Apartament ap{strada, supr, pret};
    l.adauga(ap);
}

void service::stergeService(std::string strada, int supr, int pret) {
    if (strada.empty())
        throw eroare("Strada invalida!");
    Apartament ap{strada, supr, pret};
    l.sterge(ap);
}

vector<Apartament> service::filtreazaSupr(int suprmin, int suprmax) {
    vector<Apartament> filtrat;
    for (auto & ap : l.getAll()) {
        if (ap.getSuprafata() >= suprmin and ap.getSuprafata() <= suprmax)
            filtrat.push_back(ap);
    }
    return filtrat;
}

vector<Apartament> service::filtreazaPret(int pretmin, int pretmax) {
    vector<Apartament> filtrat;
    for (auto & ap : l.getAll()) {
        if (ap.getPret() >= pretmin and ap.getPret() <= pretmax)
            filtrat.push_back(ap);
    }
    return filtrat;
}
