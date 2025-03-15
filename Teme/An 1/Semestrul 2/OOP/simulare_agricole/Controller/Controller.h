//
// Created by Știube Denis on 25.06.2024.
//

#ifndef SIMULARE_AGRICOLE_CONTROLLER_H
#define SIMULARE_AGRICOLE_CONTROLLER_H
#include "../Repository/Repo.h"
#include "../Exceptions/Exceptii.h"
#include <utility>
using namespace std;

class Controller {

private:
    FileRepo repo;
    map<string, int> tipuri;
    void reloadTipuri();

public:
    Controller(FileRepo & repo): repo{repo} {
        reloadTipuri();
    }

    void addUtilajService(const int id, const string & denumire, const string & tip, const int cilindri);

    void deleteUtilajService(const int id);

    void sortUtilaje();

    map<string, int> & getTipuri() {
        return tipuri;
    }
    unsigned int getSize() const {
        return repo.getSize();
    }
    vector<Utilaj> & getAll() {
        return repo.getAll();
    }
};


#endif //SIMULARE_AGRICOLE_CONTROLLER_H
