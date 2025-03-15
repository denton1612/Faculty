#include "Iterator.h"
#include "DO.h"
#include <iostream>
#include <exception>
using namespace std;

DO::DO(Relatie r) {
    this->cp = 10;
    this->e = new TElem[10];
    this->n = 0;
    this->r = r;
}

//creste capacitatea dictionarului
/*
 * Complexitate:
 * Se executa n pasi pentru copierea elementelor in zona nou aloca
 * BC = AC = WC = Theta(n), n - dimensiunea dictionarului
 * Overall complexity: Theta(n), n - dimensiunea dictionarului
*/
void DO::redim() {
    TElem* e_nou = new TElem[this->cp*2];
    for (int i = 0; i < n; i++){
        e_nou[i] = e[i];
    }
    cp *= 2;
    delete[] e;
    e = e_nou;
}

//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
/*
 * Complexitate:
 * BC: elementul de pe poz mijloc din dictionar are cheia c - Theta(1)
 * WC: elementul nou trebuie inserat chair dupa primul element al dictionarului - Theta(log2(n)+n), n - dimensiunea dictionarului
 * AC: Theta(log2(n)+n), n - dimensiunea dictionarului
 * Overall complexity: O(log2(n)+n), n - dimensiunea dictionarului
 */
TValoare DO::adauga(TCheie c, TValoare v) {
    if (!dim()) {
        e[0] = make_pair(c, v);
        n++;
        return NULL_TVALOARE;
    }
    if (r(c, e[0].first) && !r(e[0].first, c)) {
        if (dim() == cp)
            redim();
        for (int i = dim() - 1; i >= 0; i--)
            e[i+1] = e[i];
        e[0] = make_pair(c, v);
        n++;
        return NULL_TVALOARE;
    }
    if (r(e[dim() - 1].first, c) && !r(c, e[dim()-1].first)) {
        if (dim() == cp)
            redim();
        e[dim()] = make_pair(c, v);
        n++;
        return NULL_TVALOARE;
    }
    int start = 0, end = dim(), m;
    while (end - start > 1) {
        m = (start + end) / 2;
        if (r(e[m].first, c) && r(c, e[m].first)) {
            TValoare vechi = e[m].second;
            e[m] = make_pair(c, v);
            return vechi;
        }
        if (r(c, e[m].first)) {
            end = m;
        } else {
            start = m;
        }
    }
    if (r(c, e[start].first) && r(e[start].first, c)){
        TValoare vechi = e[start].second;
        e[start] = make_pair(c, v);
        return vechi;
    }
    if(r(c, e[start+1].first), r(e[start+1].first, c)){
        TValoare vechi = e[start+1].second;
        e[start+1] = make_pair(c, v);
        return vechi;
    }
    for (int i = dim()-1; i >= start+1; i--){
        e[i+1] = e[i];
    }
    e[start+1] = make_pair(c, v);
    n++;
    return NULL_TVALOARE;
}


//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
/*
 * Complexitate:
 * BC: elementul de pe poz mijloc din dictionar are cheia c - Theta(1)
 * WC: elementul cautat se afla pe prima, respectiv ultima pozitie din dictionar - Theta(log2(n)), n - dimensiunea dictionarului
 * AC: Theta(log2(n)), n - dimensiunea dictionarului
 * Overall complexity: O(log2(n)), n - dimensiunea dictionarului
 */
TValoare DO::cauta(TCheie c) const {
    if (!dim())
        return NULL_TVALOARE;
    int start = 0, end = dim(), m;
    while (start != end){
        m = (start + end) / 2;
        if (r(e[m].first, c) && r(c, e[m].first)){
            return e[m].second;
        }
        if (r(c, e[m].first)){
            end = m - 1;
        }
        else{
            start = m + 1;
        }
        if (end < 0 || start > dim()-1)
            return NULL_TVALOARE;
    }
    if(r(e[start].first, c) && r(c, e[start].first))
        return e[start].second;
    return NULL_TVALOARE;

}

//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
/*
 * Complexitate:
 * BC: elementul ce trebuie sters se afla chiar pe poz mij din dictionar - Theta(1)
 * WC: elementul ce trebuie sters se afla chiar dupa primul element al dictionarului - Theta(log2(n)+n), n - dimensiunea dictionarului
 * AC: O(log2(n)+n), n - dimensiunea dictionarului
 * Overall complexity: O(log2(n)+n), n - dimensiunea dictionarului
 */
TValoare DO::sterge(TCheie c) {
    if (!dim())
        return NULL_TVALOARE;
    int start = 0, end = dim(), m;
    while (start != end){
        m = (start + end) / 2;
        if (r(e[m].first, c) && r(c, e[m].first)){
            TValoare vechi = e[m].second;
            for (int i = m; i < dim()-1; i++)
                e[i] = e[i+1];
            n--;
            return vechi;
        }
        if (r(c, e[m].first)){
            end = m - 1;
        }
        else{
            start = m + 1;
        }
        if (end < 0 || start > dim()-1)
            return NULL_TVALOARE;
    }
    if (r(e[start].first, c) && r(c, e[start].first)){
        TValoare vechi = e[start].second;
        for (int i = start; i < dim()-1; i++)
            e[i] = e[i+1];
        n--;
        return vechi;
    }
    return NULL_TVALOARE;
}

// Returneaza un vector ce contine toate valorile perechilor dictionarului
/*
 * Complexitate:
 * BC=WC=AC=Theta(n), n - dimensiunea dictionarului
 * Overall complexity = Theta(n), n - dimensiunea dictionarului
 */
vector<TValoare> DO::multimeaValorilor() const {
    vector<TValoare> valori;
    for (int i = 0; i < dim(); i++){
        valori.push_back(e[i].second);
    }
    return valori;
}

//returneaza numarul de perechi (cheie, valoare) din dictionar
/*
 * Complexitate:
 * BC=AC=WC=Theta(1)
 * Overall complexity: Theta(1)
 */
int DO::dim() const {
    return n;
}

//verifica daca dictionarul e vid
/*
 * Complexitate:
 * BC=AC=WC=Theta(1)
 * Overall complexity: Theta(1)
 */
bool DO::vid() const {
    if (!dim())
        return true;
    return false;
}

Iterator DO::iterator() const {
    return Iterator(*this);
}

DO::~DO() {
    delete[] e;
}
