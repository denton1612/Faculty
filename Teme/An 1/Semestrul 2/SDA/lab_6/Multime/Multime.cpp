#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>

int hashcode(TElem e){
    return abs(e);
}

int Multime::d(TElem e) const{
    return hashcode(e) % m;
}

Multime::Multime() {
	m = MAX;
    for (int i = 0; i < m; i++)
        td[i] = NIL;
    size = 0;
}

/*
 * In ipoteza dispersiei uniforme simple, complexitatea medie este Theta(1);
 * Caz defavorabil: Theta(n)
 */
bool Multime::adauga(TElem elem) {
    if (cauta(elem))
	    return false;
    int i = d(elem);
    Pnod nou = new Nod(elem, td[i]);
    td[i] = nou;
    size++;
    return true;
}

/*
 * In ipoteza dispersiei uniforme simple, complexitatea medie este Theta(1);
 * Caz defavorabil: Theta(n)
 */
bool Multime::sterge(TElem elem) {
	if (!cauta(elem))
	    return false;
    size--;
    int i = d(elem);
    Pnod prim = td[i];
    if (prim->e == elem){
        td[i] = td[i]->urm;
        return true;
    }
    Pnod ant = prim;
    prim = prim->urm;
    while (prim->e != elem){
        ant = prim;
        prim = prim->urm;
    }
    Pnod urm = prim->urm;
    delete prim;
    ant->urm = urm;
    return true;
}

/*
 * In ipoteza dispersiei uniforme simple, complexitatea medie este Theta(1);
 * Caz defavorabil: Theta(n)
 */
bool Multime::cauta(TElem elem) const{
    int i = d(elem);
    Pnod prim = td[i];
    while (prim != NIL){
        if (prim->e == elem)
            return true;
        prim = prim->urm;
    }
	return false;
}

/*
 * Theta(1)
 */
int Multime::dim() const {
    return size;
}

bool Multime::vida() const {
    return !dim();
}

/*
 * BC=WC=AC=Theta(n)
 */
Multime::~Multime() {
	for (int i = 0; i < m; i++){
        Pnod prim = td[i];
        while (prim != NIL){
            Pnod urm = prim->urm;
            delete prim;
            prim = urm;
        }
    }
}

IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

void Multime::intersectie(const Multime &b) {
    IteratorMultime it = iterator();
    it.prim();
    while (it.valid()) {
        if (!b.cauta(it.element()))
            sterge(it.element());
        it.urmator();
    }
}
