//
// Created by Știube Denis on 24.06.2024.
//

#include "teste.h"

void testDomain() {
    Utilaj u1{1, "utb", "tractor", 4};
    assert(u1.getCilindri() == 4);
    assert(u1.getId() == 1);
    u1.setDenumire("utb 650");
    assert(u1.getDenumire() == "utb 650");
    assert(u1.getTip() == "tractor");
}

void testUtils() {
    string s = "1024";
    assert(to_int(s) == 1024);
    s = "1";
    assert(to_int(s) == 1);
}

void testFile() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt"};
    vector<Utilaj> utilaje = repo.getAll();
    assert(repo.getSize() == 5);
    for (int i = 0; i < repo.getSize(); i++) {
        assert(utilaje[i].getId() == i+1);
    }
    assert(utilaje[0].getTip() == "tractor");
    assert(utilaje[3].getCilindri() == 2);
    ofstream out("/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt");
    out.close();
    repo.saveToFile();
}

void testFind() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt"};
    assert(repo.findUtilaj(1) == 0);
    assert(repo.findUtilaj(4) == 3);
    assert(repo.findUtilaj(10) == -1);
}

void testAdd() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt"};
    assert(repo.getSize() == 5);
    Utilaj u{7, "utb1000", "tractor", 8};
    repo.addUtilaj(u);
    assert(repo.getSize() == 6);
    assert(repo.getAll()[repo.getSize()-1].getId() == 7);
    assert(repo.getAll()[repo.getSize()-1].getTip() == "tractor");
    try {
        repo.addUtilaj(Utilaj{2, "xyz", "masina", 4});
        assert(false);
    }
    catch (RepoException & err) {
        assert(err.getMesaj() == "Utilajul exista deja!");
    }
}

void testDelete() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt"};
    repo.deleteUtilaj(7);
    assert(repo.getSize() == 5);
    assert(repo.getAll()[repo.getSize()-1].getId() == 5 and repo.getAll()[repo.getSize()-1].getCilindri() == 1);
    try {
        repo.deleteUtilaj(11);
        assert(false);
    }
    catch (RepoException & err) {
        assert(err.getMesaj() == "Utilajul nu exista, deci nu poate fi sters!");
    }
}

void testUpdate() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt"};
    assert(repo.getSize() == 5);
    repo.updateUtilaj(1, Utilaj{1, "utb600", "tractor", 8});
    assert(repo.getAll()[repo.findUtilaj(1)].getId() == 1);
    assert(repo.getAll()[repo.findUtilaj(1)].getDenumire() == "utb600");
    repo.updateUtilaj(1, Utilaj{1, "utb650", "tractor", 4});
}

void testTipuri() {
    FileRepo repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/simulare_agricole/Teste/test.txt"};
    Controller c{repo};
    assert(c.getSize() == 5);
    assert(c.getTipuri()["tractor"] == 2);
    assert(c.getTipuri()["drujba"] == 1);
    assert(c.getTipuri()["combina"] == 1);
}

void testFileRepo() {
    testFile();
    testFind();
    testAdd();
    testDelete();
    testUpdate();
}

void testController() {
    testTipuri();
}

void testAll() {
    testDomain();
    testFileRepo();
    testController();
    testUtils();
}