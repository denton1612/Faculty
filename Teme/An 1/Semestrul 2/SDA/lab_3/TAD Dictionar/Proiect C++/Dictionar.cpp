#include "Dictionar.h"
#include <iostream>
#include <utility>
#include "IteratorDictionar.h"

/*
 * Complexitate: Theta(1)
 */
Nod::Nod(TElem e, Pnod pre, Pnod urm) {
    this->e = e;
    this->pre = pre;
    this->urm = urm;
}

TElem Nod::elem() {
    return e;
}

Pnod Nod::urmator() {
    return urm;
}

Pnod Nod::precedent() {
    return pre;
}

/*
 * Complexitate: Theta(1)
 */
Dictionar::Dictionar() {
	prim = nullptr;
    ultim = nullptr;
    n = 0;
}

/*
 * Complexitate: AC=BC=WC=Overall complexity=Theta(n), n - dimensiunea dictionarului
 */
Dictionar::~Dictionar() {
	while(prim != nullptr){
        Pnod p = prim->urmator();
        delete prim;
        prim = p;
    }
}

/*
 * Complexitate:
 * BC: Theta(1) - 'prima' pereche din dictionar (de unde incepe parcurgerea iteratorului) contine cheia c
 * WC: Theta(n) - toate cheile din dictionar sunt diferite de cheia c
 * AC: Theta(n)
 * Overall complexity: O(n) - liniara
 */
TValoare Dictionar::adauga(TCheie c, TValoare v){
    if (prim == nullptr && ultim == nullptr){
        prim = new Nod(TElem(c, v), nullptr, nullptr);
        ultim = prim;
        n++;
        return NULL_TVALOARE;
    }
    Pnod p = prim;
    while (p != nullptr){
        if (p->elem().first == c){
            TValoare vechi = p->elem().second;
            TElem nou = TElem (c, v);
            p->e = nou;
            return vechi;
        }
        p = p->urmator();
    }
    Pnod nod_nou = new Nod(TElem(c, v), ultim, nullptr);
    ultim->urm = nod_nou;
    ultim = nod_nou;
    n++;
    return NULL_TVALOARE;
}



//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
/*
 * Complexitate:
 * BC: Theta(1) - nodul de pe prima pozitie din dictionar are ca informatie utila o pereche ce contine cheia dupa care se cauta
 * WC: Theta(n) - toate cheile din dictionar sunt diferite de cheia c
 * AC: Theta(n)
 * Overall complexity: O(n) - liniara
 */
TValoare Dictionar::cauta(TCheie c) const{
    Pnod p = prim;
    while (p != nullptr && p->elem().first != c){
        p = p->urmator();
    }
    if (p == nullptr)
        return NULL_TVALOARE;
    else
        return p->elem().second;
}

/*
 * Complexitate:
 * BC: Theta(1) - 'prima'/'ultima' pereche din dictionar (de unde incepe/se termina parcurgerea iteratorului) contine cheia c
 * WC: Theta(n) - toate cheile din dictionar sunt diferite de cheia c
 * AC: Theta(n)
 * Overall complexity: O(n) - liniara
 */
TValoare Dictionar::sterge(TCheie c){
    if (prim == nullptr && ultim == nullptr)
        return NULL_TVALOARE;
    if (dim() == 1 && prim->elem().first == c){
        TValoare vechi = prim->elem().second;
        delete prim;
        prim = nullptr;
        ultim = nullptr;
        n--;
        return vechi;
    }
    if (prim->elem().first == c){
        TValoare vechi = prim->elem().second;
        prim->urmator()->pre = nullptr;
        Pnod nou_prim = prim->urmator();
        delete prim;
        prim = nou_prim;
        n--;
        return vechi;
    }
    if (ultim->elem().first == c){
        TValoare vechi = ultim->elem().second;
        ultim->precedent()->urm = nullptr;
        Pnod nou_ultim = ultim->precedent();
        delete ultim;
        ultim = nou_ultim;
        n--;
        return vechi;
    }
    Pnod p = prim;
    while (p != nullptr){
        if (p->elem().first == c){
            TValoare vechi = p->elem().second;
            p->urmator()->pre = p->precedent();
            p->precedent()->urm = p->urmator();
            delete p;
            n--;
            return vechi;
        }
        p = p->urmator();
    }
    return NULL_TVALOARE;
}

/*
 * Complexitate: Theta(n), n - dimensiunea dictionarului
 */
vector<TValoare> Dictionar::colecțiaValorilor() const {
    Pnod p = prim;
    vector<TValoare> valori;
    while (p != nullptr){
        valori.push_back(p->elem().second);
    }
    return valori;
}

/*
 * Complexitate: Theta(1)
 */
int Dictionar::dim() const {
//    Pnod p = prim;
//    int n = 0;
//    while (p != nullptr){
//        n++;
//        p = p->urmator();
//    }
    return n;
}

/*
 * Complexitate: Theta(1)
 */
bool Dictionar::vid() const{
	if (!dim())
	    return true;
    return false;
}


IteratorDictionar Dictionar::iterator() const {
	return IteratorDictionar(*this);
}


