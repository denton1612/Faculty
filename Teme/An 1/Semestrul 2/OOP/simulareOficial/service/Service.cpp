//
// Created by Știube Denis on 20.05.2024.
//

#include "Service.h"

void Service::sortareNume() {
    sort(elevi.getAll().begin(), elevi.getAll().end(), [](Elev & e1, Elev & e2) {
        return e1.getNume() < e2.getNume();
    });
}

void Service::build() {
    ateliere['d'] = "desen+pictura";
    ateliere['f'] = "fotografie";
    ateliere['m'] = "muzica";
    ateliere['i'] = "informatica";
    ateliere['j'] = "jurnalism";
}

vector<string> Service::getAteliere(Elev &e) {
    string ateliereElev = e.getAteliere();
    vector<string> ateliere;
    for (auto a : ateliereElev) {
        ateliere.push_back(this->ateliere[a]);
    }
    return ateliere;
}

Elev Service::find(string nume) {
    return elevi.findByNume(nume);
}

vector<Elev> & Service::getAll() {
    return elevi.getAll();
}