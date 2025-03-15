//
// Created by Știube Denis on 25.06.2024.
//

#include "Controller.h"

void Controller::reloadTipuri() {
    for (auto & u : repo.getAll()) {
        tipuri[u.getTip()]++;
    }
}

void Controller::addUtilajService(const int id, const std::string &denumire, const std::string &tip,
                                  const int cilindri) {
    if (cilindri != 1 and cilindri != 2 and cilindri != 4 and cilindri != 8)
        throw ServiceException("Numarul de cilindri poate fi 1, 2, 4 sau 8!");
    repo.addUtilaj(Utilaj{id, denumire, tip, cilindri});
}

void Controller::deleteUtilajService(const int id) {
    int pos = repo.findUtilaj(id);
    int cilindri = repo.getAll()[pos].getCilindri();
    int contor = 0;
    for (auto & u : repo.getAll()) {
        if (u.getCilindri() == cilindri)
            contor++;
    }
    if (contor == 1)
        throw ServiceException("Stergerea nu se poate efectua!");
    repo.deleteUtilaj(id);
}

void Controller::sortUtilaje() {
    std::sort(repo.getAll().begin(), repo.getAll().end(), [](Utilaj & u1, Utilaj & u2) {
       return make_pair(u1.getTip(), u1.getDenumire()) < make_pair(u2.getTip(), u2.getDenumire());
    });
}