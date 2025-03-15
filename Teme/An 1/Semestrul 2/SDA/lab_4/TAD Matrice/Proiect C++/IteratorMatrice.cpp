//
// Created by Știube Denis on 25.04.2024.
//

#include "IteratorMatrice.h"

IteratorMatrice::IteratorMatrice(const Matrice &m, const int& j): m{m}, j{j} {
    if (j >= m.nrColoane() || j < 0)
        throw exception();
    prim();
}

void IteratorMatrice::prim() {
    i = 0;
}

void IteratorMatrice::urmator() {
    if (valid())
        i++;
    else
        throw exception();
}

bool IteratorMatrice::valid() {
    if (i == m.nrLinii())
        return false;
    return true;
}

TElem IteratorMatrice::element() {
    if (valid())
        return m.element(i, j);
    throw exception();
}


