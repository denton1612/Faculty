#include "IteratorMultime.h"
#include "Multime.h"

void IteratorMultime::deplasare() {
    while (curent == NIL){
        poz++;
        if (poz == multime.m)
            break;
        curent = multime.td[poz];
    }
}

IteratorMultime::IteratorMultime(const Multime& m) : multime(m){
	poz = 0;
    curent = multime.td[poz];
    deplasare();
}


void IteratorMultime::prim() {
    poz = 0;
    curent = multime.td[poz];
	deplasare();
}


void IteratorMultime::urmator() {
    if (!valid())
        throw std::exception();
    curent = curent->urm;
    deplasare();
}


TElem IteratorMultime::element() const {
    if (!valid())
        throw std::exception();
    return curent->e;
}

bool IteratorMultime::valid() const {
    return poz != multime.m;
}
