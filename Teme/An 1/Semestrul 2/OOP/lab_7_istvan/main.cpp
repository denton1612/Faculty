#include <stdlib.h>

#include "VectorIterator.h"
//#include "VectorDinamicTemplate.h"
#include "Pet.h"
#include <assert.h>
#include <vector>

/*
  Functie folosit in teste
  primeste vector prin valoare -> copy constructor
  returneaza prin valoare -> copy constructor sau move constructor
*/
template <typename VectorDinamic>
VectorDinamic testCopyIterate(VectorDinamic v) {
    double totalPrice = 0;
    for (auto el : v) {
        totalPrice += el.getPrice();
    }
    Pet p{ "total","tt",totalPrice };
    v.add(p);
    return v;
}

template <typename VectorDinamic>
void addPets(VectorDinamic& v, int cate) {
    for (int i = 0; i<cate; i++) {
        Pet p{ std::to_string(i) + "_type",std::to_string(i) + "_spec",i + 10.0 };
        v.add(p);
    }
}

/*
Testare constructori / assignment
E template pentru a refolosi la diferite variante de VectorDinamic din proiect
*/
template <typename VectorDinamic>
void testCreateCopyAssign() {
    VectorDinamic v;//default constructor
    addPets(v, 100);
    assert(v.getSize() == 100);
    assert(v.get(50).getType() == "50_type");

    VectorDinamic v2{ v };//constructor de copiere
    assert(v2.getSize() == 100);
    assert(v2.get(50).getType() == "50_type");

    VectorDinamic v3;//default constructor
    v3 = v;//operator=   assignment
    assert(v3.getSize() == 100);
    assert(v3.get(50).getType() == "50_type");

    auto v4 = testCopyIterate(v3);
    assert(v4.getSize() == 101);
    assert(v4.get(50).getType() == "50_type");
}

/*
  Test pentru move constructor si move assgnment
*/
template <typename VectorDinamic>
void testMoveConstrAssgnment() {
    std::vector<VectorDinamic> v;
    //adaugam un vector care este o variabila temporara
    //se v-a apela move constructor
    v.push_back(VectorDinamic{});

    //inseram, la fel se apeleaza move costructor de la vectorul nostru
    v.insert(v.begin(),VectorDinamic{});

    assert(v.size() == 2);

    VectorDinamic v2;
    addPets(v2, 50);

    v2 = VectorDinamic{};//move assignment

    assert(v2.getSize() == 0);

}
template <typename VectorDinamic>
void testAll() {
    testCreateCopyAssign<VectorDinamic>();
    testMoveConstrAssgnment<VectorDinamic>();
}

int main() {
    testAll<VectorDinamic<Pet>>();

    return 0;
}