#include "IteratorDictionar.h"
#include "Dictionar.h"

using namespace std;


IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	this->curent = d.prim;
}


void IteratorDictionar::prim() {
	curent = dict.prim;
}

void IteratorDictionar::urmator() {
    if (!valid())
        throw std::exception();
	curent = curent->urmator();
}

void IteratorDictionar::precedent() {
    if (!valid())
        throw std::exception();
    curent = curent->precedent();
}

TElem IteratorDictionar::element() const{
    if (!valid())
	    throw std::exception();
    return curent->elem();
}

bool IteratorDictionar::valid() const {
	if (curent != nullptr)
        return true;
	return false;
}

