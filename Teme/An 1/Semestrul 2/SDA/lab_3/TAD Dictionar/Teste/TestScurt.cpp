#include "TestScurt.h"
#include <assert.h>
#include "Dictionar.h"
#include "IteratorDictionar.h"

void testColectiaValorilor(){
    Dictionar d;
    for (int i = 0; i < 50; i++)
        d.adauga(i, i);
    vector<TValoare> valori = d.colecțiaValorilor();
    for (int i = 0; i < valori.size(); i++)
        assert(valori[i] == i);
    IteratorDictionar it = d.iterator();
    it.prim();
    while (it.valid()){
        TCheie c = it.element().first;
        d.sterge(c);
        it.urmator();
    }
    valori = d.colecțiaValorilor();
    assert(valori.empty());
}

void testAll() { //apelam fiecare functie sa vedem daca exista
	Dictionar d;
	assert(d.vid() == true);
	assert(d.dim() == 0); //adaug niste elemente
	assert(d.adauga(5,5)==NULL_TVALOARE);
	assert(d.adauga(1,111)==NULL_TVALOARE);
	assert(d.adauga(10,110)==NULL_TVALOARE);
	assert(d.adauga(7,7)==NULL_TVALOARE);
	assert(d.adauga(1,1)==111);
	assert(d.adauga(10,10)==110);
	assert(d.adauga(-3,-3)==NULL_TVALOARE);
	assert(d.dim() == 5);
	assert(d.cauta(10) == 10);
	assert(d.cauta(16) == -1);
	assert(d.sterge(1) == 1);
	assert(d.sterge(6) == -1);
	assert(d.dim() == 4);


	TElem e;
	IteratorDictionar id = d.iterator();
	id.prim();
	int s1 = 0, s2 = 0;
	while (id.valid()) {
		e = id.element();
		s1 += e.first;
		s2 += e.second;
		id.urmator();
	}
	assert(s1 == 19);
	assert(s2 == 19);

}

