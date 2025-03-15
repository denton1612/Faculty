//
// Created by Știube Denis on 27.06.2024.
//

#ifndef EXAMENOFICIAL_FILEREPO_H
#define EXAMENOFICIAL_FILEREPO_H
#include "../Domain/Parcare.h"
#include <vector>
#include <algorithm>
#include <exception>
#include <fstream>

using namespace std;
using std::vector;


class FileRepo {
private:
    string filename;
    vector<Parcare> parcari;
    void loadFromFile();
    void saveToFile();
public:

    // constructor
    FileRepo(const string & f): filename{f} {
        loadFromFile();
    }

    // adauga o noua parcare
    void addParcare(const Parcare & newp);

    // modifica o parcare cu valorile altei parcari
    void updateParcare(const Parcare & newp);

    // returneaza parcarea cu adresa data
    Parcare findParcare(const string adresa);

    // returneaza vectorul de parcari
    vector<Parcare> & getAll(){
        return parcari;
    }
    vector<Parcare> getAllCopy() {
        return parcari;
    }

    // returneaza nr parcarilor
    int getSize() {
        return parcari.size();
    }
};


#endif //EXAMENOFICIAL_FILEREPO_H
