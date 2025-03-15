#include "Matrice.h"
#include "IteratorMatrice.h"
class IteratorMatrice;

using namespace std;

// Complexitate:
// BC=WC=AC=Theta(cp), cp - capacitatea curenta a tablourilor
void Matrice::initSpLiber(int cp) {
    primLiber = 0;
    for (int i = 0; i < cp - 1; i++)
        urm[i] = i + 1;
    urm[cp-1] = -1;
}

// Complexitate:
// BC=WC=AC=Theta(1) - se sterge primul nod din lista inlantuita a poz libere
int Matrice::aloca() {
    int i = primLiber;
    primLiber = urm[primLiber];
    return i;
}

// Complexitate:
// BC=WC=AC=Theta(1) - se adauga poz i din tablou in lista inlantuita a poz libere (la inceput)
void Matrice::dealoca(int i) {
    urm[i] = primLiber;
    primLiber = i;
}

// Complexitate:
// BC=WC=AC=Theta(cp), cp - capacitatea tablourilor dinamice inainte de redimensionare
void Matrice::redimensionare() {
    auto e_nou = new Triplet [2*cp];
    auto urm_nou = new int [2*cp];
    for (int i = 0; i < cp; i++){
        e_nou[i] = e[i];
        urm_nou[i] = urm[i];
    }
    delete[] e;
    delete[] urm;
    e = e_nou;
    urm = urm_nou;
    primLiber = cp;
    for (int i = cp; i < 2 * cp; i++){
        urm[i] = i + 1;
    }
    urm[2*cp-1] = -1;
    cp *= 2;
}

// Complexitate:
// BC=Theta(1) - nu necesita redimensionare
// WC=Theta(cp) - necesita redimensionare
// AC = 1/cp + 1/cp + ... + 1/cp + 1 = 1/cp * (cp-1) + cp/cp = (2*cp-1)/cp = Theta(1)
int Matrice::creeazaNod(int i, int j, TElem val) {
    if (primLiber == -1){
        redimensionare();
    }
    int poz = aloca();
    e[poz].i = i;
    e[poz].j = j;
    e[poz].val = val;
    urm[poz] = -1;
    return poz;
}

// Complexitate:
// BC=WC=AC=Theta(1)
int Matrice::poz_reala(int i, int j) const {
    return i * nrColoane() + j;
}

// Complexitate:
// BC=WC=AC=Theta(cp)
Matrice::Matrice(int m, int n) {
    if (m <= 0 || n <= 0)
        throw exception();
    nrLin = m;
    nrCol = n;
    cp = 2;
    e = new Triplet [cp];
    urm = new int [cp];
    prim = -1;
    initSpLiber(cp);
}

// Complexitate:
// BC=WC=AC=Theta(1)
int Matrice::nrLinii() const{
	return this->nrLin;
}

// Complexitate:
// BC=WC=AC=Theta(1)
int Matrice::nrColoane() const{
	return this->nrCol;
}

// Complexitate:
// BC=Theta(1)
// WC=Theta(n), n - nr de noduri din lista inlantuita a elem din matrice
// AC=Theta(n), n - nr de noduri din lista inlantuita a elem din matrice
TElem Matrice::element(int i, int j) const{
	if (i >= nrLinii() || j >= nrColoane()) // daca pozitia este in afara matricii, aruncam exceptie
        throw exception();

    // daca lista inlantuita este goala, atunci sigur elementul este nul
    if (prim == -1)
        return NULL_TELEMENT;
    int poz = prim;
    int pozitie = poz_reala(i, j);
    while (poz != -1 && poz_reala(e[poz].i, e[poz].j) < pozitie) // parcurgem lista pana cand ajungem la final sau am ajuns la ultima poz unde
        poz = urm[poz];                                          // am putea gasi elementul
    if (poz_reala(e[poz].i, e[poz].j) == pozitie)                // verificam daca am gasit elementul, in caz afirmativ returnam valoarea, altfel
        return e[poz].val;                                       // cu siguranta elemnentul este nul
    return NULL_TELEMENT;
}

// Complexitate:
// BC=Theta(1)
// WC=Theta(n), n - nr de noduri din lista inlantuita a elem din matrice
// AC=Theta(n), n - nr de noduri din lista inlantuita a elem din matrice
TElem Matrice::modifica(int i, int j, TElem e) {
    if (i >= nrLinii() || j >= nrColoane()) // daca pozitia este in afara matricii, aruncam exceptie
        throw exception();
    int pozitie = poz_reala(i, j);

    // cazul in care modificam un element nenul cu o valoare nenula (cautam si modificam valoarea din nod)
    if (element(i, j) != NULL_TELEMENT && e != NULL_TELEMENT){
        TElem vechi = element(i, j);
        int poz = prim;
        while (poz_reala(this->e[poz].i, this->e[poz].j) < pozitie){
            poz = urm[poz];
        }
        this->e[poz] = Triplet {i, j, e};
        return vechi;
    }

    // cazul in care modificam valoarea unui element nul cu o valoare nenula (trebuie sa inseram un nou nod corespunzator noului element pe poz
    // adecvata
    if (element(i, j) == NULL_TELEMENT && e != NULL_TELEMENT){
        int nou = creeazaNod(i, j, e);
        int prim_1 = prim;
        if (prim_1 == -1){
            prim = nou;
            return NULL_TELEMENT;
        }
        if (pozitie < poz_reala(this->e[prim_1].i, this->e[prim_1].j)) {
            urm[nou] = prim;
            prim = nou;
            return NULL_TELEMENT;
        }
        prim_1 = urm[prim_1];
        int anterior = prim;
        while (prim_1 != - 1 && poz_reala(this->e[prim_1].i, this->e[prim_1].j) < pozitie){
            anterior = prim_1;
            prim_1 = urm[prim_1];
        }
        urm[anterior] = nou;
        urm[nou] = prim_1;
        return NULL_TELEMENT;
    }

    // daca am ajuns aici, inseamna ca noua valoare pentru elementul de pe poz i, j este nula
    // daca elementul oricum era nul, nu trebuie sa facem nimic, in caz contrat trebuie sa stergem din lista nodul
    // corespunzator elementului ce va deveni nul din matrice
    TElem vechi = element(i, j);
    if (vechi == NULL_TELEMENT)
        return NULL_TELEMENT;
    if (this->e[prim].i == i && this->e[prim].j == j){
        int p = prim;
        prim = urm[prim];
        dealoca(p);
        return vechi;
    }
    int anterior = prim;
    int p = urm[prim];
    while (poz_reala(this->e[p].i, this->e[p].j) < pozitie){
        anterior = p;
        p = urm[p];
    }
    urm[anterior] = urm[p];
    dealoca(p);
    return vechi;
}

IteratorMatrice Matrice::iterator(const int &j) const {
    return IteratorMatrice(*this, j);
}

