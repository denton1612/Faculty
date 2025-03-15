//
// Created by Știube Denis on 18.05.2024.
//

#include "repo.h"

void repo::addProcesor(const procesor &p) {
    if (std::find(procesoare.begin(), procesoare.end(), p) != procesoare.end())
        throw eroare("Procesorul deja exista!");
    procesoare.push_back(p);
    saveToFileProcesor();
}

void repo::addPlacaDeBaza(const placaDeBaza &pb) {
    if (std::find(placiDeBaza.begin(), placiDeBaza.end(), pb) != placiDeBaza.end())
        throw eroare("Placa de baza deja exista!");
    placiDeBaza.push_back(pb);
    saveToFilePlacaDeBaza();
}

void repo::loadFromFileProcesor() {
    ifstream in(filename1);
    string line;
    string nume;
    unsigned int nrThread;
    string soclu;
    unsigned int pret;
    while (getline(in, line)){
        readLineProcesor(line, nume, nrThread, soclu, pret);
        procesoare.push_back(procesor{nume, nrThread, soclu, pret});
    }
}

void repo::loadFromFilePlacaDeBaza() {
    ifstream in(filename2);
    string line;
    string nume, soclu;
    unsigned int pret;
    while (getline(in, line)) {
        readLinePlacaDeBaza(line, nume, soclu, pret);
        placiDeBaza.push_back(placaDeBaza{nume, soclu, pret});
    }
}

void repo::saveToFileProcesor() {
    ofstream out(filename1);
    for (procesor & pr : procesoare) {
        out << pr.getNume() << "," << to_string(pr.getNrThread()) << "," << pr.getSoclu() << "," << to_string(pr.getPret()) << '\n';
    }
}

void repo::saveToFilePlacaDeBaza() {
    ofstream out(filename2);
    for (auto & pb : placiDeBaza) {
        out << pb.getNume() << "," << pb.getSoclu() << "," << to_string(pb.getPret()) << '\n';
    }
}