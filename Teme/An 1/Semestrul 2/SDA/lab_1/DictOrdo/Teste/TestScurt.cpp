#include <assert.h>

#include "../Proiect/DO.h"
#include "../Proiect/Iterator.h"

#include <exception>
#include <vector>
using namespace std;

bool relatie1(TCheie cheie1, TCheie cheie2) {
    if (cheie1 <= cheie2) {
        return true;
    }
    else {
        return false;
    }
}

void testAll(){
    DO dictOrd = DO(relatie1);
    assert(dictOrd.dim() == 0);
    assert(dictOrd.vid());
    dictOrd.adauga(1,2);
    assert(dictOrd.dim() == 1);
    vector<TValoare> valori = dictOrd.multimeaValorilor();
    assert(valori.size() == 1);
    assert(valori[0] == 2);
    assert(!dictOrd.vid());
    assert(dictOrd.cauta(1)!=NULL_TVALOARE);
    TValoare v = dictOrd.adauga(1,3);
    valori = dictOrd.multimeaValorilor();
    assert(v == 2);
    assert(valori.size() == 1);
    assert(dictOrd.cauta(1) == 3);
    Iterator it = dictOrd.iterator();
    it.prim();
    while (it.valid()){
    	TElem e = it.element();
    	assert(e.second != NULL_TVALOARE);
    	it.urmator();
    }
    assert(dictOrd.sterge(1) == 3);
    assert(dictOrd.vid());
}

void testMultimeaValorilor(){
    DO d = DO(relatie1);
    vector<TValoare> valori = d.multimeaValorilor();
    assert(valori.size() == 0);
    d.adauga(2, 3);
    valori = d.multimeaValorilor();
    assert(d.dim() == 1);
    assert(valori.size() == 1);
    assert(d.sterge(2) == 3);
    valori = d.multimeaValorilor();
    assert(valori.empty());
    for (int i = 0; i < 200; i++){
        d.adauga(i, 2*i);
    }
    valori = d.multimeaValorilor();
    assert(valori.size() == 200);
    for (int i = 0; i < 200; i++){
        assert(valori[i] == 2*i);
    }
}
