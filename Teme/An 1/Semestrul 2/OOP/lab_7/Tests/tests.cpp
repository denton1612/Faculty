//
// Created by Știube Denis on 29.03.2024.
//

#include "tests.h"

void testDomain(){
    Medicament m1{"d1", 45.3, "p1", "s1"};
    assert(m1.getDenumire() == "d1");
    assert(m1.getPret() == 45.3);
    assert(m1.getProducator() == "p1");
    assert(m1.getSubst() == "s1");
    m1.setPret(55);
    assert(m1.getPret() == 55);
    m1.setSubst("s10");
    assert(m1.getSubst() == "s10");
    Medicament m2{"d1", 55, "p1", "s10"};
    assert(m1 == m2);

}
void testAddRepo(){
    Repository repo;
    assert(repo.getSize() == 0);
    Medicament m1{"d1", 50, "p1", "s1"};
    repo.addMedicament(m1);
    assert(repo.getSize() == 1);
    assert(repo[0].getPret() == 50);
    Medicament m2{"d1", 50, "p1", "s1"};
    try{
        repo.addMedicament(m2);
        assert(false);
    }
    catch (RepositoryError err){
        assert(true);
        assert(err.getMesaj() == "Medicamentul exista deja!");
    }
}

void testDeleteRepo(){
    Repository repo;
    assert(repo.getSize() == 0);
    Medicament m1{"d1", 50, "p1", "s1"};
    repo.addMedicament(m1);
    assert(repo.getSize() == 1);
    repo.deleteMedicament(0);
    assert(repo.getSize() == 0);
    try{
        repo.deleteMedicament(5);
        assert(false);
    }
    catch (RepositoryError err){
        assert(true);
        assert(err.getMesaj() == "Nu exista acest medicament!");
    }
}

void testUpdatePretRepo(){
    Repository repo;
    assert(repo.getSize() == 0);
    Medicament m1{"d1", 50, "p1", "s1"};
    repo.addMedicament(m1);
    assert(repo.getSize() == 1);
    repo.updatePret(0, 75.45);
    assert(repo[0].getPret() == 75.45);
}

void testUpdateSubstRepo(){
    Repository repo;
    assert(repo.getSize() == 0);
    Medicament m1{"d1", 50, "p1", "s1"};
    repo.addMedicament(m1);
    assert(repo.getSize() == 1);
    repo.updateSubst(0, "s10");
    assert(repo[0].getSubst() == "s10");
}

void testGetSizeRepo(){
    Repository repo;
    assert(repo.getSize() == 0);
    Medicament m1{"d1", 50, "p1", "s1"};
    repo.addMedicament(m1);
    Medicament m2{"d2", 100, "p2", "s2"};
    repo.addMedicament(m2);
    assert(repo.getSize() == 2);
}

void testGetAllRepo(){
    Repository repo;
    assert(repo.getSize() == 0);
    Medicament m1{"d1", 50, "p1", "s1"};
    repo.addMedicament(m1);
    Medicament m2{"d2", 100, "p2", "s2"};
    repo.addMedicament(m2);
    assert(repo.getSize() == 2);
    VectorDinamic<Medicament> medicamente = repo.getAll();
    assert(medicamente.getSize() == 2);
    assert(medicamente[0].getPret() == 50);
    assert(medicamente[1].getProducator() == "p2");
    Medicament m3{"d3", 150, "p3", "s5"};
    repo.addMedicament(m3);
    assert(repo.getSize() == 3);
    assert(medicamente.getSize() == 2);
}


void testRepository(){
    testAddRepo();
    testDeleteRepo();
    testUpdatePretRepo();
    testUpdateSubstRepo();
    testGetAllRepo();
    testGetSizeRepo();
}

void testAddService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    assert(service.getSize() == 1);
    service.addMedicament("d2", 45.25, "p2", "s2");
    assert(service.getSize() == 2);
    assert(service.getAll()[1].getDenumire() == "d2");
}

void testDeleteService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    assert(service.getSize() == 1);
    assert(service.getAll()[0].getSubst() == "s1");
    service.deleteMedicament(1);
    assert(service.getSize() == 0);
}

void testUpdatePretService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    assert(service.getSize() == 1);
    assert(service.getAll()[0].getPret() == 67.23);
    service.updatePret(1, 70);
    assert(service.getAll()[0].getPret() == 70);
}

void testUpdateSubstService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    assert(service.getSize() == 1);
    assert(service.getAll()[0].getSubst() == "s1");
    service.updateSubst(1, "s3");
    assert(service.getAll()[0].getSubst() == "s3");
}

void testFindMedicament(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    assert(service.getSize() == 1);
    assert(service.findMedicament("d1", "p1") == true);
    assert(service.findMedicament("10", "pharma") == false);
}

void testFiltruPretService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 50, "p1", "s1");
    assert(service.getSize() == 1);
    service.addMedicament("d2", 100, "p2", "s2");
    service.addMedicament("d3", 50, "p7", "s8");
    assert(service.getSize() == 3);
    VectorDinamic<Medicament> listaFiltrata = service.filtruPret(50);
    assert(listaFiltrata.getSize() == 2);
    assert(service.getSize() == 3);
    assert(listaFiltrata[0].getDenumire() == "d1");
    assert(listaFiltrata[1].getDenumire() == "d3");
}

void testFiltruSubstService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 50, "p1", "s2");
    assert(service.getSize() == 1);
    service.addMedicament("d2", 100, "p2", "s2");
    service.addMedicament("d3", 50, "p7", "s8");
    assert(service.getSize() == 3);
    VectorDinamic<Medicament> listaFiltrata = service.filtruSubst("s2");
    assert(listaFiltrata.getSize() == 2);
    assert(service.getSize() == 3);
    assert(listaFiltrata[0].getDenumire() == "d1");
    assert(listaFiltrata[1].getDenumire() == "d2");
}

void testGetAllService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    service.addMedicament("d2", 45.25, "p2", "s2");
    assert(service.getSize() == 2);
    VectorDinamic<Medicament> med = service.getAll();
    assert(med.getSize() == 2);
    assert(med[0].getDenumire() == "d1");
    assert(med[1].getProducator() == "p2");
}

void testGetSizeService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d1", 67.23, "p1", "s1");
    service.addMedicament("d2", 45.25, "p2", "s2");
    assert(service.getSize() == 2);
}

void testVectorDinamic(){
    VectorDinamic<Medicament> v;
    assert(v.getSize() == 0);
    assert(v.getCap() == 5);
    Medicament m1{"d1", 32.50, "p1", "s1"};
    v.push_back(m1);
    assert(v.getSize() == 1);
    Medicament m2{"d2", 100.25, "p3", "s5"};
    v.push_back(m2);
    assert(v.getSize() == 2);
    assert(v[0] == m1);
    assert(m2 == v[1]);
    Medicament m3{"d3", 75.20, "p3", "s6"};
    Medicament m4{"d4", 80, "p6", "s5"};
    Medicament m5{"d5", 65.35, "p10", "s9"};
    Medicament m6{"d6", 90.10, "p8", "s6"};
    v.push_back(m3);
    v.push_back(m4);
    v.push_back(m5);
    v.push_back(m6);
    assert(v.getSize() == 6);
    assert(v.getCap() == 10);
    v.erase(v.begin()+2);
    assert(v.getSize() == 5);
    assert(v[2] == m4);
}

void testIterator(){
    VectorDinamic<Medicament> v;
    Medicament m1{"d1", 32.50, "p3", "s1"};
    v.push_back(m1);
    assert(v.getSize() == 1);
    Medicament m2{"d2", 100.25, "p3", "s5"};
    v.push_back(m2);
    assert(v.getSize() == 2);
    Iterator<Medicament> it = v.IteratorVector();
    it.prim();
    assert(it == v.begin());
    assert(*it == m1);
    it.urmator();
    assert(*it == m2);
    it.urmator();
    assert(it == v.end());
    assert(!(it == v.begin()));
    it.prim();
    ++it;
    assert(*it == m2);
    it.prim();
    Medicament m3{"d3", 45.25, "p3", "s10"};
    v.push_back(m3);
    assert(v.getSize() == 3);
    for (const auto& m : v){
        assert(m.getProducator() == "p3");
    }
}

void testSortareDenumireService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d3", 50, "p1", "s2");
    assert(service.getSize() == 1);
    service.addMedicament("d1", 100, "p2", "s2");
    service.addMedicament("d2", 50, "p7", "s8");
    assert(service.getSize() == 3);
    assert(service.getAll()[0].getDenumire() == "d3");
    VectorDinamic<Medicament> sortat = service.sortareDenumire();
    assert(sortat[0].getDenumire() == "d1");
    assert(sortat[1].getDenumire() == "d2");
    assert(sortat[2].getDenumire() == "d3");
}

void testSortareProducatorService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d3", 50, "p6", "s2");
    assert(service.getSize() == 1);
    service.addMedicament("d1", 100, "p2", "s2");
    service.addMedicament("d2", 50, "p7", "s8");
    assert(service.getSize() == 3);
    VectorDinamic<Medicament> sortat = service.sortareProducator();
    assert(sortat[0].getProducator() == "p2");
    assert(sortat[1].getProducator() == "p6");
    assert(sortat[2].getProducator() == "p7");
}

void testSortareSubstPretService(){
    Repository repo;
    Service service{repo};
    assert(service.getSize() == 0);
    service.addMedicament("d3", 200, "p6", "s2");
    assert(service.getSize() == 1);
    service.addMedicament("d1", 100, "p2", "s8");
    service.addMedicament("d2", 50, "p7", "s2");
    assert(service.getSize() == 3);
    VectorDinamic<Medicament> sortat = service.sortareSubstPret();
    assert(sortat[0].getSubst() == "s2");
    assert(sortat[0].getPret() == 50);
    assert(sortat[1].getSubst() == "s2");
    assert(sortat[2].getSubst() == "s8");
}

void testService(){
    testAddService();
    testDeleteService();
    testUpdatePretService();
    testUpdateSubstService();
    testFindMedicament();
    testFiltruPretService();
    testFiltruSubstService();
    testSortareDenumireService();
    testSortareProducatorService();
    testSortareSubstPretService();
    testGetAllService();
    testGetSizeService();
}



void testAll() {
    testDomain();
    testIterator();
    testRepository();
    testService();
    testVectorDinamic();
}
