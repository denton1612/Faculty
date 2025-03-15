//
// Created by Știube Denis on 24.06.2024.
//

#ifndef SIMULARE_AGRICOLE_REPO_H
#define SIMULARE_AGRICOLE_REPO_H
#include "../Domain/Utilaj.h"
#include "../Utils/utils.h"
#include "../Exceptions/Exceptii.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <map>
using std::vector;
using std::ifstream;
using std::ofstream;
using std::map;

class FileRepo {
private:
    string filename;
    vector<Utilaj> utilaje;
    void loadFromFile();

public:
    FileRepo(const string& filename): filename{filename} {
        loadFromFile();
    }

    void saveToFile();

    void addUtilaj(const Utilaj& newUtilaj);

    int findUtilaj(const int id);

    void deleteUtilaj(const int id);

    void updateUtilaj(const int id, const Utilaj& utilaj);

    vector<Utilaj>& getAll() {
        return utilaje;
    }

    vector<Utilaj> getAllCopy() {
        return utilaje;
    }

    unsigned int getSize() const{
        return utilaje.size();
    }
};


#endif //SIMULARE_AGRICOLE_REPO_H
