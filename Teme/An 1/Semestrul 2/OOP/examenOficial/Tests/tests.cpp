//
// Created by Știube Denis on 27.06.2024.
//

#include "tests.h"

void testDomain() {
    Parcare p{"1 eroilor", 3, 3};
    assert(p.getLinii() == 3);
    assert(p.getCol() == 3);
    assert(p.getAdresa() == "1 eroilor");
    Parcare p1{"1 eroilor", 2, 2, "----"};
    assert(p1.getStare() == "----");
    assert(p.getStare() == "---------");
    p1.setCol(3);
    assert(p1.getCol() == 3);
}

void testFileRepo() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/examenOficial/Tests/parcari.txt"};
    assert(repo.getSize() == 5);
    vector<Parcare> copy = repo.getAllCopy();
    Parcare p{"100 memo", 3, 3};
    Parcare p1{"100 memo", 3, 4};
    repo.addParcare(p);
    try {
        repo.addParcare(p1);
        assert(false);
    }
    catch (std::exception &) {
        assert(true);
    }
    assert(repo.getSize() == 6);
    assert(repo.getAll()[5].getAdresa() == "100 memo");
    Parcare p2{"100 memo", 2, 2};
    repo.updateParcare(p2);
    assert(repo.getAll()[5].getLinii() == 2);
    assert(repo.getAll()[5].getStare() == "----");
    ofstream out("/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/examenOficial/Tests/parcari.txt");
    for (auto & p : copy) {
        out << p.getAdresa() + ", " + to_string(p.getLinii()) + ", " + to_string(p.getCol()) + ", " + p.getStare() + '\n';
    }
    out.close();
}

void testService() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/examenOficial/Tests/parcari.txt"};
    service s{repo};
    assert(s.getSize() == 5);
    vector<Parcare> copy = repo.getAllCopy();
    s.addService("100 baciu", 3, 2, "X-X-X-");
    assert(s.getSize() == 6);
    assert(s.getAll()[5].getStare() == "X-X-X-");
    ofstream out("/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/examenOficial/Tests/parcari.txt");
    for (auto & p : copy) {
        out << p.getAdresa() + ", " + to_string(p.getLinii()) + ", " + to_string(p.getCol()) + ", " + p.getStare() + '\n';
    }
    out.close();
    string stare = s.randomStare(3, 3);
    assert(stare.size() == 9);
    for (auto & c : stare)
        assert(c == 'X' or c == '-');
    auto p = s.findService("3 baciu");
    assert(p.getStare() == "X--XXX");
}

void testAll() {
   testDomain();
   testFileRepo();
   testService();
}