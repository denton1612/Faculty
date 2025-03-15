//
// Created by Știube Denis on 27.06.2024.
//

#include "service.h"

void service::addService(const std::string adr, const int linii, const int col, const std::string stare) {
    repo.addParcare(Parcare{adr, linii, col, stare});
}

void service::updateService(const std::string adr, const int linii, const int col,
                            const std::string stare) {
    if (linii < 1 || linii > 5 || col < 1 || col > 5 || stare.size() != linii * col || !valid(stare))
        throw std::exception();
    repo.updateParcare(Parcare{adr, linii, col, stare});
}

Parcare service::findService(const std::string adresa) {
    return repo.findParcare(adresa);
}

string service::randomStare(const int linii, const int col) {
    string stare = "";
    string date = "X-";
    int p;
    for (int i = 0; i < linii * col; i++) {
        p = rand() % 2;
        stare += date[p];
    }
    return stare;
}