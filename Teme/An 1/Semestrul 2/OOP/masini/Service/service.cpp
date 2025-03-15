//
// Created by Știube Denis on 26.06.2024.
//

#include "service.h"

void service::deleteCarService(const std::string &nri) {
    undoList.push(getAllCopy());
    repo.deleteCar(nri);
}

void service::plus() {
    undoList.push(getAllCopy());
    for (auto & c : repo.getAll()) {
        c.incrementAn();
    }
    repo.saveInFile();
}

void service::minus() {
    undoList.push(getAllCopy());
    for (auto & c : repo.getAll()) {
        c.decrementAn();
    }
    repo.saveInFile();
}

void service::undo() {
    if (undoList.empty())
        throw exceptions("Nu se poate face undo!");
    redoList.push(getAllCopy());
    getAll() = undoList.top();
    repo.saveInFile();
    undoList.pop();
}

void service::redo() {
    if (redoList.empty())
        throw exceptions("Nu se poate face redo!");
    getAll() = redoList.top();
    repo.saveInFile();
    redoList.pop();
}

vector<Car> service::sortNri() {
    vector<Car> rez = getAllCopy();
    std::sort(rez.begin(), rez.end(), [](const Car & c1, const Car & c2) {
        return c1.getNri() < c2.getNri();
    });
    return rez;
}