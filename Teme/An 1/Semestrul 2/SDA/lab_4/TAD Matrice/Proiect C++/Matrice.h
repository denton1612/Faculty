#pragma once

#include <exception>
#include "IteratorMatrice.h"

typedef int TElem;
typedef struct {
    int i;
    int j;
    TElem val;
} Triplet;

#define NULL_TELEMENT 0

class IteratorMatrice;

class Matrice {

    friend class IteratorMatrice;
private:
	int cp;
    Triplet *e;
    int *urm;
    int prim;
    int primLiber;
    int nrLin;
    int nrCol;

    // initializeaza lista de spatiilor libere (la inceput toate spatiile din vectorul de elemente sunt goale)
    void initSpLiber(int cp);

    // returneaza o pozitie libera din lista de spatii libere (pentru inserare)
    int aloca();

    // elibereaza spatiului ocupat de nodul de pe poz i (inserreaza noua poz libera in lista de spatii libere)
    void dealoca(int i);

    // redimensioneaza cele 2 tablouri dinamice ale listei (cand vectorul de elemente este plin)
    void redimensionare();

    // creeaza un nod, ii aloca spatiu si returneaza pozitia pe care oferita lui
    int creeazaNod(int i, int j, TElem val);

    // returneaza poz reala
    int poz_reala(int i, int j) const;

public:
	//constructor
	//se arunca exceptie daca nrLinii<=0 sau nrColoane<=0
	Matrice(int nrLinii, int nrColoane);

	//destructor
	~Matrice(){
        delete[] e;
        delete[] urm;
    };

	//returnare element de pe o linie si o coloana
	//se arunca exceptie daca (i,j) nu e pozitie valida in Matrice
	//indicii se considera incepand de la 0
	TElem element(int i, int j) const;

	// returnare numar linii
	int nrLinii() const;

	// returnare numar coloane
	int nrColoane() const;

	// modificare element de pe o linie si o coloana si returnarea vechii valori
	// se arunca exceptie daca (i,j) nu e o pozitie valida in Matrice
	TElem modifica(int i, int j, TElem);

    // returneaza un iterator pe matrice care itereaza pe o coloana
    IteratorMatrice iterator(const int& j) const;

};







