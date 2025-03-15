//
// Created by Știube Denis on 27.06.2024.
//

#include "FileRepo.h"

void FileRepo::loadFromFile() {
    ifstream in(filename);
    string line;
    string adresa;
    int linii, col;
    string stare;
    while (getline(in, line)) {
        int pos = line.find(", ");
        adresa = line.substr(0, pos);
        line.erase(0, pos+2);
        pos = line.find(", ");
        linii = stoi(line.substr(0, pos));
        line.erase(0, pos+2);
        pos = line.find(", ");
        col = stoi(line.substr(0, pos));
        line.erase(0, pos+2);
        stare = line;
        parcari.push_back(Parcare{adresa, linii, col, stare});
    }
    in.close();
}

void FileRepo::saveToFile() {
    ofstream out(filename);
    for (auto & p : parcari)
        out << p.getAdresa() + ", " + to_string(p.getLinii()) + ", " + to_string(p.getCol()) + ", " + p.getStare() + '\n';
    out.close();
}


void FileRepo::addParcare(const Parcare &newp) {
    auto it = std::find_if(parcari.begin(), parcari.end(), [&newp](const Parcare & p) {
        return newp.getAdresa() == p.getAdresa();
    });
    if (it != parcari.end())
        throw std::exception();
    parcari.push_back(newp);
    saveToFile();
}

void FileRepo::updateParcare(const Parcare &newp) {
    for (int i = 0; i < parcari.size(); i++)
        if (parcari[i].getAdresa() == newp.getAdresa())
            parcari[i] = newp;
    saveToFile();
}

Parcare FileRepo::findParcare(const string adresa) {
    auto it = std::find_if(parcari.begin(), parcari.end(), [&](const Parcare & p) {
        return p.getAdresa() == adresa;
    });
    return *it;
}