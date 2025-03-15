//
// Created by Știube Denis on 18.05.2024.
//

#include "teste.h"
#include <assert.h>
#include "../domain/procesor.h"
#include "../domain/placaDeBaza.h"
#include "../repository/repo.h"

void test_domain() {
    procesor p{"amd", 16, "am12", 400};
    placaDeBaza pb{"asus", "am23", 350};
    assert(p.getNume() == "amd");
    assert(p.getNrThread() == 16);
    assert(pb.getSoclu() == "am23");
    assert(pb.getPret() == 350);
}

void test_addRepoProcesor() {
    repo r{"test1.txt", "test2.txt"};
    assert(r.getProcesoareSize() == 0);
    assert(r.getPlaciSize() == 0);
    procesor p{"amd", 16, "am12", 400};
    r.addProcesor(p);
    assert(r.getProcesoareSize() == 1);
    clearFile("test1.txt");
    clearFile("test2.txt");
}

void test_all() {
    test_domain();
    test_addRepoProcesor();
}