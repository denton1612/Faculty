#include "Colectie.h"
#include "IteratorColectie.h"
#include <iostream>

using namespace std;

bool rel(TElem e1, TElem e2) {
    return e1 <= e2;
}

void Colectie::initSpLiber() {
    primLiber = 0;
    for (int i = 0; i < cp; i++) {
        st[i] = i+1;
    }
    st[cp-1] = -1;
}

int Colectie::aloca() {
    int i = primLiber;
    primLiber = st[primLiber];
    return i;
}

void Colectie::dealoca(int i) {
    st[i] = primLiber;
    primLiber = i;
}

int Colectie::maxim(int p) const{
    if (dr[p] == -1)
        return p;
    return maxim(dr[p]);
}

int Colectie::minim(int p) const{
    if (st[p] == -1)
        return p;
    return minim(st[p]);
}

int Colectie::diferenta() const {
    if (dim() == 0)
        return -1;
    return val[maxim(rad)] - val[minim(rad)];
}

int Colectie::adaugaRec(int p, int e) {
    if (p == -1)
        p = creeazaNod(e);
    else
        if (rel(e, val[p]))
            st[p] = adaugaRec(st[p], e);
        else
            dr[p] = adaugaRec(dr[p], e);
    return p;
}

int Colectie::stergeRec(int r, int e) {
    if(r == -1)
        return -1;
    if(rel(e, val[r]) and rel(val[r], e)) {
            int temp;
            if (st[r] != -1 and dr[r] != -1) {
                temp = minim(dr[r]);
                val[r] = val[temp];
                dr[r] = stergeRec(dr[r], val[r]);
                return r;
            }
            else {
                temp = r;
                int repl;
                if (st[r] == -1)
                    repl = dr[r];
                else
                    repl = st[r];
                dealoca(temp);
                return repl;
            }
        }
    else if(rel(e, val[r])){
        st[r] = stergeRec(st[r], e);
        return r;
    }
    else  {
        dr[r] = stergeRec(dr[r], e);
        return r;
    }
}

int Colectie::cautaRec(int p, int e) const{
    if (p == -1 or val[p] == e)
        return p;
    if (rel(e, val[p]))
        return cautaRec(st[p], e);
    else
        return cautaRec(dr[p], e);
}

void Colectie::redim() {
    auto valNou = new TElem [2*cp];
    auto stNou = new int [2*cp];
    auto drNou = new int [2*cp];
    for (int i = 0; i < cp; i++) {
        valNou[i] = val[i];
        stNou[i] = st[i];
        drNou[i] = dr[i];
    }
    delete[] val;
    delete[] st;
    delete[] dr;
    val = valNou;
    st = stNou;
    dr = drNou;
    for (int i = cp; i < 2*cp-1; i++) {
        st[i] = i+1;
    }
    primLiber = cp;
    cp *= 2;
    st[cp-1] = -1;
}

int Colectie::creeazaNod(TElem e) {
    if (primLiber == -1)
        redim();
    int i = aloca();
    val[i] = e;
    st[i] = -1;
    dr[i] = -1;
    return i;
}

Colectie::Colectie() {
    this->cp = 10;
    this->lg = 0;
    this->rad = -1;
    this->val = new TElem[cp];
    this->st = new int[cp];
    this->dr = new int[cp];
    initSpLiber();
}

void Colectie::adauga(TElem e) {
    rad = adaugaRec(rad, e);
    lg++;
}


bool Colectie::sterge(TElem e) {
    if (cauta(e)){
        rad = stergeRec(rad, e);
        lg--;
        return true;
    }
    return false;
}


bool Colectie::cauta(TElem elem) const {
	int p = cautaRec(rad, elem);
    return p != -1;
}


int Colectie::nrAparitii(TElem elem) const {
    int p = rad;
    int fr = 0;
    while (cautaRec(p, elem) != -1) {
        fr++;
        p = st[cautaRec(p, elem)];
    }
    return fr;
}



int Colectie::dim() const {
    return lg;
}


bool Colectie::vida() const {
    return !lg;
}


IteratorColectie Colectie::iterator() const{
	return IteratorColectie(*this);
}


Colectie::~Colectie() {
    delete[] val;
    delete[] st;
    delete[] dr;
}
