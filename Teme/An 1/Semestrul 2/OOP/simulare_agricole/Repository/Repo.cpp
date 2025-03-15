//
// Created by Știube Denis on 24.06.2024.
//

#include "Repo.h"

void FileRepo::loadFromFile() {
    ifstream in(filename);
    string line;
    int id, cilindri;
    string denumire, tip;
    while (getline(in, line)) {
        int pos = line.find(", ");
        auto text = line.substr(0, pos);
        id = to_int(text);
        line.erase(0, pos+2);
        pos = line.find(", ");
        denumire = line.substr(0, pos);
        line.erase(0, pos+2);
        pos = line.find(", ");
        tip = line.substr(0, pos);
        line.erase(0, pos+2);
        cilindri = to_int(line);
        utilaje.push_back(Utilaj{id, denumire, tip, cilindri});
    }
    in.close();
}

void FileRepo::saveToFile() {
    ofstream out(filename);
    string line;
    for (auto & u : utilaje) {
        line = "";
        line += std::to_string(u.getId()) + ", " + u.getDenumire() + ", " + u.getTip() + ", " + std::to_string(u.getCilindri());
        out << line << '\n';
    }
    out.close();
}

void FileRepo::addUtilaj(const Utilaj &newUtilaj) {
    if (findUtilaj(newUtilaj.getId()) != -1)
        throw RepoException("Utilajul exista deja!");
    utilaje.push_back(newUtilaj);
    saveToFile();
}

void FileRepo::deleteUtilaj(const int id) {
    int pos = findUtilaj(id);
    if (pos == -1)
        throw RepoException("Utilajul nu exista, deci nu poate fi sters!");
    utilaje.erase(utilaje.begin()+pos);
    saveToFile();
}

int FileRepo::findUtilaj(const int id) {
    auto it = std::find_if(utilaje.begin(), utilaje.end(), [&id](Utilaj & u) {
        return u.getId() == id;
    });
    if (it == utilaje.end())
        return -1;
    return it-utilaje.begin();
}

void FileRepo::updateUtilaj(const int id, const Utilaj &utilaj) {
    int pos = findUtilaj(id);
    utilaje[pos] = utilaj;
}