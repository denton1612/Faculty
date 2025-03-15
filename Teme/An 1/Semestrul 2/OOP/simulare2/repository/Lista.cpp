//
// Created by Știube Denis on 20.05.2024.
//

#include "Lista.h"

void Lista::loadFromFile() {
    ifstream in(filename);
    string strada;
    int supr, pret;
    while (!in.eof()) {
        in >> strada >> supr >> pret;
        if (strada == "")
            break;
        aps.push_back(Apartament{strada, supr, pret});
    }
    in.close();
}

void Lista::saveToFile() {
    ofstream out(filename);
    for (auto ap : aps) {
        out << ap.getStrada() << ' ' << ap.getSuprafata() << ' ' << ap.getPret() << '\n';
    }
    out.close();
}

void Lista::adauga(Apartament &ap) {
    auto it = find(aps.begin(), aps.end(), ap);
    if (it != aps.end())
        throw eroare("Apartamentul exista deja!");
    aps.push_back(ap);
    saveToFile();
}

void Lista::sterge(Apartament & ap) {
    auto it = std::find(aps.begin(), aps.end(), ap);
    if (it == aps.end()) {
        throw eroare("Apartamentul nu exista!");
    }
    aps.erase(it);
    saveToFile();
}