//
// Created by Știube Denis on 08.04.2024.
//

#ifndef LAB_7_ISTVAN_VECTORITERATOR_H
#define LAB_7_ISTVAN_VECTORITERATOR_H
//
// Created by Știube Denis on 05.04.2024.
//
#define LAB_7_ISTVAN_VECTOR_ITERATOR_H
#include "Pet.h"

template<typename ElementT>
class Iterator;

template<typename ElementT>
class VectorDinamic{

    friend class Iterator<ElementT>;
private:
    int size;
    int cap;
    ElementT* elemente;

public:
    VectorDinamic(): size{0}, cap{5}, elemente{new ElementT[5]}{}

    VectorDinamic(VectorDinamic& ot);

    int getSize();

    ElementT& get(int poz) const;
    
    int getCap();

    VectorDinamic<ElementT>& operator=(VectorDinamic<ElementT>&& ot) {
        if (this == &ot) {
            return *this;
        }
        delete[] elemente;
        // Copy the data pointer from other
        elemente = ot.elemente;
        size = ot.size;
        cap = ot.cap;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        ot.elemente = nullptr;
        ot.size = 0;
        ot.cap = 0;
        return *this;
    }

    ElementT& operator[](const int& poz) const;

    /*
Move constructor
Apelat daca construim un nou vector dintr-un r-value (ex temporary)
Obiectul ot nu se mai foloseste astfel se poate refolosi interiorul lui
*/
    VectorDinamic<ElementT>(VectorDinamic&& ot) noexcept;

    void redim();

    Iterator<ElementT> IteratorVector(){
        return Iterator<ElementT>(*this);
    }

    Iterator<ElementT> begin(){
        return Iterator<ElementT>(*this, 0);
    }

    Iterator<ElementT> end(){
        return Iterator<ElementT>(*this, size);
    }

    void add(const ElementT& newElem);

    void erase(const Iterator<ElementT>& it);

    ~VectorDinamic(){
        delete[] elemente;
    }
};

template<typename ElementT>
VectorDinamic<ElementT>::VectorDinamic(VectorDinamic<ElementT> &ot) {
    this->cap = ot.cap;
    this->size = ot.size;
    this->elemente = new ElementT[ot.size];
    for (int i = 0; i < ot.size; i++){
        this->elemente[i] = ot.elemente[i];
    }
}

template<typename ElementT>
ElementT& VectorDinamic<ElementT>::get(int poz) const {
    return elemente[poz];
}

template<typename ElementT>
int VectorDinamic<ElementT>::getSize() {
    return size;
}

template<typename ElementT>
int VectorDinamic<ElementT>::getCap() {
    return cap;
}

template<typename ElementT>
ElementT& VectorDinamic<ElementT>::operator[](const int& poz) const{
    return elemente[poz];
}

template<typename ElementT>
void VectorDinamic<ElementT>::redim() {
    auto newElemente = new ElementT[2*cap];
    for (int i = 0; i < size; i++){
        newElemente[i] = this->elemente[i];
    }
    delete[] elemente;
    elemente = newElemente;
    cap *= 2;
}

template<typename ElementT>
void VectorDinamic<ElementT>::add(const ElementT &newElem) {
    if (size == cap)
        redim();
    elemente[size++] = newElem;
}

template<typename ElementT>
void VectorDinamic<ElementT>::erase(const Iterator<ElementT>& it) {
    for (int i = it.curent; i < size-1; i++){
        elemente[i] = elemente[i+1];
    }
    size--;
}

template<typename ElementT>
VectorDinamic<ElementT> ::VectorDinamic(VectorDinamic<ElementT> &&ot) noexcept{
        // Copy the data pointer from other
        elemente = ot.elemente;
        size = ot.size;
        cap = ot.cap;

        // Release the data pointer from the source object so that
        // the destructor does not free the memory multiple times.
        ot.elemente = nullptr;
        ot.size = 0;
        ot.cap = 0;
}

//
// Created by Știube Denis on 05.04.2024.
//

template<typename ElementT>
class Iterator{
    friend class VectorDinamic<ElementT>;
private:

    Iterator() noexcept : curent{0}{}
    Iterator<ElementT>& operator=(const Iterator<ElementT>& it) = default;
    Iterator(VectorDinamic<ElementT>& v): vector{v}{}
    Iterator(VectorDinamic<ElementT>& v, const int& curent) noexcept: vector{v}, curent{curent} {}

    VectorDinamic<ElementT>& vector;
    int curent;

public:

    void prim();

    void urmator();

    ElementT& operator*();

    bool operator!=(const Iterator<ElementT>& it);

    bool operator==(const Iterator<ElementT>& it);

    bool operator<(const Iterator<ElementT>& it);

    bool operator>(const Iterator<ElementT>& it);

    Iterator<ElementT>& operator+(const int& poz);

    Iterator<ElementT>& operator-(const int& poz);

    Iterator<ElementT>& operator--();

    Iterator<ElementT>& operator++();

};

template<typename ElementT>
Iterator<ElementT>& Iterator<ElementT>::operator++() {
    curent++;
    return *this;
}

template<typename ElementT>
Iterator<ElementT>& Iterator<ElementT>::operator--() {
    curent--;
    return *this;
}

template<typename ElementT>
Iterator<ElementT>& Iterator<ElementT>::operator+(const int &poz) {
    curent += poz;
    return *this;
}

template<typename ElementT>
Iterator<ElementT>& Iterator<ElementT>::operator-(const int &poz) {
    curent -= poz;
    return *this;
}

template<typename ElementT>
void Iterator<ElementT>::prim() {
    curent = 0;
}

template<typename ElementT>
void Iterator<ElementT>::urmator() {
    curent++;
}

template<typename ElementT>
ElementT& Iterator<ElementT>::operator*() {
    return vector[curent];
}

template<typename ElementT>
bool Iterator<ElementT>::operator!=(const Iterator<ElementT> &it) {
    if (curent != it.curent)
        return true;
    return false;
}

template<typename ElementT>
bool Iterator<ElementT>::operator==(const Iterator<ElementT> &it) {
    if (curent == it.curent)
        return true;
    return false;
}

template<typename ElementT>
bool Iterator<ElementT>::operator>(const Iterator<ElementT> &it) {
    return this->curent > it.curent;
}

template<typename ElementT>
bool Iterator<ElementT>::operator<(const Iterator<ElementT> &it) {
    return this->curent < it.curent;
}

#endif

