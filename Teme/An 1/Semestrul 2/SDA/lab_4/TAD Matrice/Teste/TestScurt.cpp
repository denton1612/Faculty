#include "TestScurt.h"
#include <assert.h>
#include "Matrice.h"
#include <iostream>

using namespace std;

void testAll() { //apelam fiecare functie sa vedem daca exista
	Matrice m(4,4);
	assert(m.nrLinii() == 4);
	assert(m.nrColoane() == 4);
	//adaug niste elemente
	m.modifica(1,1,5);
	assert(m.element(1,1) == 5);
	m.modifica(1,1,6);
    m.modifica(2, 1, 10);
	assert(m.element(1,2) == NULL_TELEMENT);
    IteratorMatrice it = m.iterator(1);
    assert(it.element() == 0);
    it.urmator();
    assert(it.element() == 6);
    it.urmator();
    assert(it.element() == 10);
    it.urmator();
    assert(it.element() == 0);
    it.urmator();
    assert(!it.valid());
    try{
        auto it1 = m.iterator(10);
        assert(false);
    }
    catch (exception&){
        assert(true);
    }
}
