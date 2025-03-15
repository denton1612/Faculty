//
// Created by Știube Denis on 25.04.2024.
//

#ifndef TAD_MATRICE_ITERATORMATRICE_H
#define TAD_MATRICE_ITERATORMATRICE_H
#include "Matrice.h"
#include <exception>
typedef int TElem;
using std::exception;
class Matrice;
class IteratorMatrice{
//    IteratorMatrice(Matrice matrice, const int i);

private:
    IteratorMatrice(const Matrice& m, const int& j);

    const Matrice& m;
    const int j;
    int i;

public:
    friend class Matrice;
    void prim();

    void urmator();

    bool valid();

    TElem element();
};

#endif //TAD_MATRICE_ITERATORMATRICE_H
