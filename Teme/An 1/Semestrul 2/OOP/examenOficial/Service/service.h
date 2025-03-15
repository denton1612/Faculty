//
// Created by Știube Denis on 27.06.2024.
//

#ifndef EXAMENOFICIAL_SERVICE_H
#define EXAMENOFICIAL_SERVICE_H
#include "../FileRepo/FileRepo.h"
#include "../Utils/utils.h"
#include "../Observer/Observer.h"

class service:  public Observable{
private:
    FileRepo & repo;
public:

    // constructor
    service(FileRepo & repo): repo{repo} {}

    // adauga o parcare cu datele date
    void addService(const string adr, const int linii, const int col, const string stare);

    // modifica o parcare cu valorile date (dupa adresa = id)
    void updateService(const string adr, const int linii, const int col, const string stare);

    // returneaza parcarea cu adresa data
    Parcare findService(const string adresa);

    // returneaza o stare random corecta
    string randomStare(const int linii, const int col);

    // returneaza vectorul cu parcari
    vector<Parcare> & getAll() {

        return repo.getAll();
    }
    int getSize() {
        return repo.getSize();
    }
};


#endif //EXAMENOFICIAL_SERVICE_H
