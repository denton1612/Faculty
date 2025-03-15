//
// Created by Știube Denis on 26.06.2024.
//

#include "tests.h"

void testDomain() {
    Car c{"BH32SDA", "bmw", 2010, "sedan"};
    assert(c.getDenumire() == "bmw");
    assert(c.getNri() == "BH32SDA");
    c.incrementAn();
    c.incrementAn();
    assert(c.getAn() == 2012);
    c.decrementAn();
    assert(c.getAn() == 2011);
}

void testFileRepo() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/masini/Tests/cars.txt"};
    assert(repo.getSize() == 6);
    vector<Car> copy = repo.getAllCopy();
    try {
        repo.deleteCar("BH");
        assert(false);
    }
    catch (exceptions & err) {
        assert(err.getMesaj() == "Masina nu exista!");
    }
    repo.deleteCar("BH32SDA");
    assert(repo.getSize() == 5);
    assert(repo.getAll()[0].getNri() == "BH16AMD");
    ofstream out{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/masini/Tests/cars.txt"};
    for (auto & car: copy) {
        out << car << '\n';
    }
    out.close();
}

void testService() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/masini/Tests/cars.txt"};
    service s{repo};
    assert(s.getSize() == 6);
    vector<Car> copy = repo.getAllCopy();
    s.deleteCarService("BH16AMD");
    assert(s.getSize() == 5);
    assert(s.getAll()[0].getNri() == "BH32SDA");
    assert(s.getAll()[1].getNri() == "AB20ATH");
    ofstream out{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/masini/Tests/cars.txt"};
    for (auto & car: copy) {
        out << car << '\n';
    }
    out.close();
    s.getAll() = copy;
    s.plus();
    s.plus();
    for (int i = 0; i < s.getSize(); i++) {
        assert(s.getAll()[i].getAn() == copy[i].getAn() + 2);
    }
    s.minus();
    s.minus();
    for (int i = 0; i < s.getSize(); i++) {
        assert(s.getAll()[i].getAn() == copy[i].getAn());
    }
    s.plus();
    s.plus();
    s.undo();
    s.undo();
    for (int i = 0; i < s.getSize(); i++) {
        assert(s.getAll()[i].getAn() == copy[i].getAn());
    }
    s.redo();
    for (int i = 0; i < s.getSize(); i++) {
        assert(s.getAll()[i].getAn() == copy[i].getAn() + 1);
    }
    s.redo();
    try {
        s.redo();
        assert(false);
    }
    catch (exceptions & err) {
        assert(true);
    }
}

void testAll() {
    testDomain();
    testFileRepo();
    testService();
}