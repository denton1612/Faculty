//
// Created by Știube Denis on 20.05.2024.
//

#include "teste.h"

void testDomain() {
    Apartament ap1{"Hasdeu", 50, 100000};
    assert(ap1.getPret() == 100000);
    assert(ap1.getStrada() == "Hasdeu");
    Apartament ap2{"Hasdeu", 50, 100000};
    assert(ap1 == ap2);
}

void testRepo() {
    Lista l{"../teste/t.txt"};
    assert(l.getSize() == 0);
    Apartament ap{"Hasdeu", 50, 100000};
    l.adauga(ap);
    assert(l.getSize() == 1);
    assert(l.getAll()[0].getSuprafata() == 50);
    try {
        l.adauga(ap);
        assert(false);
    }
    catch(eroare & er) {
        assert(er.getMesaj() == "Apartamentul exista deja!");
    }
    Apartament ap1 = Apartament{"Marasti", 60, 150000};
    l.adauga(ap1);
    assert(l.getSize() == 2);
    try{
        l.sterge(ap);
        assert(l.getSize() == 1);
    }
    catch (eroare & er) {
        assert(er.getMesaj() == "Apartamentul nu exista!");
    }
    clearFile("../teste/t.txt");
}

void testService() {
    Lista l{"../teste/t.txt"};
    service s{l};
    assert(s.getSize() == 0);
    s.adaugaService("Manastur", 60, 120000);
    s.adaugaService("Zorilor", 70, 130000);
    try {
        s.adaugaService("", 60, 10000);
        assert(false);
    }
    catch (eroare & er) {
        assert(er.getMesaj() == "Strada invalida!");
    }
    assert(s.getSize() == 2);
    s.stergeService("Manastur", 60, 120000);
    assert(s.getSize() == 1);
    assert(s.getAll()[0].getStrada() == "Zorilor");
    s.adaugaService("Manastur", 60, 120000);
    s.adaugaService("Grigorescu", 90, 230000);
    assert(s.getSize() == 3);
    vector<Apartament> filtrat = s.filtreazaSupr(50, 80);
    assert(filtrat.size() == 2);
    assert(filtrat[0].getPret() == 130000);
    filtrat = s.filtreazaPret(100000, 150000);
    assert(filtrat.size() == 2);
    assert(filtrat[1].getStrada() == "Manastur");
    clearFile("../teste/t.txt");
}

void testAll() {
    testDomain();
    testRepo();
    testService();
}