#include "Iterator.h"
#include "DO.h"
#include <exception>
#include <stdexcept>

using namespace std;

Iterator::Iterator(const DO& d) : dict(d){
    this->curent = 0;
}

void Iterator::prim(){
    curent = 0;
}

void Iterator::urmator(){
    curent++;
}

bool Iterator::valid() const{
    if (curent < dict.dim())
        return true;
    return false;
}

TElem Iterator::element() const{
    if(valid())
        return dict.e[curent];
}


