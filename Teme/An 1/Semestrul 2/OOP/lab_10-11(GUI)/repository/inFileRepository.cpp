//
// Created by Știube Denis on 19.04.2024.
//

#include "inFileRepository.h"

InFileRepository::InFileRepository(const string& filename) : Repository(), filename{filename}{
    loadFromFile();
}

void InFileRepository::loadFromFile() {
    ifstream in(filename);
    if (!in.is_open())
        throw Error("Nu s-a putut deschide fisierul!");
    string denumire, producator, subst;
    double pret;
    in >> denumire;
    in >> pret;
    in >> producator;
    in >> subst;
    while (!in.eof()) {
        Medicament m1{denumire, pret, producator, subst};
        Repository::addMedicament(m1);
        in >> denumire;
        in >> pret;
        in >> producator;
        in >> subst;
    }
    in.close();
}

void InFileRepository::saveToFile() {
    ofstream out(filename);
    for (auto& m : getAll()){
        out << m.getDenumire() << " " << m.getPret() << " " << m.getProducator() << " " << m.getSubst() << '\n';
    }
    out.close();
}
