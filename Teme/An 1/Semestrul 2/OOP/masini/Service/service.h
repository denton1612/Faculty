//
// Created by Știube Denis on 26.06.2024.
//

#ifndef MASINI_SERVICE_H
#define MASINI_SERVICE_H
#include "../FileRepo/FileRepo.h"
#include <stack>
using namespace std;

class service {
private:
    FileRepo & repo;
    stack<vector<Car>> undoList;
    stack<vector<Car>> redoList;

public:
    service() = delete;
    service(FileRepo & r): repo{r} {

    }
    service(const service & ot) = delete;
    void deleteCarService(const string & nri);
    vector<Car> sortNri();
    void plus();
    void minus();
    void undo();
    void redo();
    vector<Car> & getAll() {
        return repo.getAll();
    }
    vector<Car> getAllCopy() {
        return repo.getAllCopy();
    }
    int getSize() {
        return repo.getSize();
    }
    ~service() = default;
};


#endif //MASINI_SERVICE_H
