//
// Created by Știube Denis on 26.06.2024.
//

#ifndef MASINI_FILEREPO_H
#define MASINI_FILEREPO_H
#include <vector>
#include <fstream>
#include <algorithm>
#include "../Domain/Car.h"
#include "../Exceptions/exceptions.h"
using namespace std;

class FileRepo {
private:
    string filename;
    vector<Car> cars;
    void loadFromFile();

public:
    FileRepo(const string filename): filename{filename} {
        loadFromFile();
    }
    void saveInFile();
    void deleteCar(const string & nri);
    vector<Car> & getAll() {
        return cars;
    }
    vector<Car> getAllCopy() {
        return cars;
    }
    int getSize() {
        return cars.size();
    }
};


#endif //MASINI_FILEREPO_H
