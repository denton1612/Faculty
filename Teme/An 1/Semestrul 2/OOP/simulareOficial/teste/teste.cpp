//
// Created by Știube Denis on 20.05.2024.
//

#include "teste.h"

void testDomain() {
    Elev e1{1234, "Stiube Denis", "Scoala 1", "dm"};
    assert(e1.getNume() == "Stiube Denis");
    assert(e1.getNr() == 1234);
    Elev e2{1234, "Stiube Denis", "Scoala 1", "dm"};
    assert(e1 == e2);
}

void testRepo() {
    Lista l{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulareOficial/teste/test.txt"};
    assert(l.getSize() == 4);
    assert(l.getAll()[0].getNume() == "Stiube Denis");
    assert(l.getAll()[1].getNr() == 1432);
    assert(l.getAll()[0].getAteliere() == "dm");
    assert(l.getAll()[1].getScoala() == "Scoala 4");
    Elev e1{1234, "Stiube Denis", "Scoala 1", "dm"};
    assert(l.findByNume("Stiube Denis") == e1);
}

void testService() {
    Lista l{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulareOficial/teste/test.txt"};
    Service s{l};
    assert(s.getAll()[0].getNume() == "Stiube Denis");
    assert(s.getAll()[1].getNr() == 1432);
    s.sortareNume();
    assert(s.getAll()[0].getNr() == 1432);
    assert(s.getAll()[1].getNr() == 4356);
    assert(s.getAll()[2].getNr() == 2314);
    assert(s.getAll()[3].getNr() == 1234);
    assert(s.getAll()[2].getNume() == "Robert Marius");
    assert(s.find("Robert Marius") == s.getAll()[2]);
    vector<string> ateliere2 = s.getAteliere(s.getAll()[2]);
    assert(ateliere2.size() == 1);
    assert(ateliere2[0] == "informatica");
    vector<string> ateliere3 = s.getAteliere(s.getAll()[3]);
    assert(ateliere3.size() == 2);
    assert(ateliere3[0] == "desen+pictura" and ateliere3[1] == "muzica");
}

void testUtils() {
    string s = "1234";
    assert(to_int(s) == 1234);
    s = "1";
    assert(to_int(s) == 1);
    s = "12300";
    assert(to_int(s) == 12300);
}

void testAll() {
    testDomain();
    testRepo();
    testService();
    testUtils();
}