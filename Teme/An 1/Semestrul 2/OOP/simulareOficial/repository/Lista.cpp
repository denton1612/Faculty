//
// Created by Știube Denis on 20.05.2024.
//

#include "Lista.h"

void Lista::loadFromFile() {
    ifstream in(filename);
    string line;
    while (getline(in, line)) {
        int pos = line.find(", ");
        auto text = line.substr(0, pos);
        int nr = to_int(text);
        line.erase(0, pos+2);
        pos = line.find(", ");
        auto nume = line.substr(0, pos);
        line.erase(0, pos+2);
        pos = line.find(", ");
        auto scoala = line.substr(0, pos);
        line.erase(0, pos+2);
        auto ateliere = line;
        Elev e{nr, nume, scoala, ateliere};
        elevi.push_back(e);
    }
}

Elev Lista::findByNume(string nume) {
    for (auto el : elevi) {
        if (el.getNume() == nume)
            return el;
    }
}

vector<Elev> & Lista::getAll() {
    return elevi;
}

int Lista::getSize() {
    return elevi.size();
}