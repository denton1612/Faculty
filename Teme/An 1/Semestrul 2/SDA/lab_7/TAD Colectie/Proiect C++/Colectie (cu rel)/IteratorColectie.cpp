#include "IteratorColectie.h"
#include "Colectie.h"
#include <iostream>
using namespace std;


IteratorColectie::IteratorColectie(const Colectie& c): col{c} {
    this->curent = col.rad;
}

TElem IteratorColectie::element(){
	if(valid()){
        while (curent != -1) {
            stiva.push(curent);
            curent = col.st[curent];
        }
        curent = stiva.top();
        stiva.pop();
        return col.val[curent];
    }
    stiva.pop();
}

bool IteratorColectie::valid() const {
    return curent != -1 or !stiva.empty();
}

void IteratorColectie::urmator() {
    curent = col.dr[curent];
}

void IteratorColectie::prim() {
    while (!stiva.empty())
        stiva.pop();
    curent = col.rad;
}
