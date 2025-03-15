//
// Created by Știube Denis on 05.04.2024.
//

#ifndef LAB_7_LIST_H
#define LAB_7_LIST_H

#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/Domain/medicament.h"

template<typename ElemType>
class Iterator;

template<typename ElemType>
class VectorDinamic{

    friend class Iterator<ElemType>;
private:
    int size;
    int cap;
    ElemType* elemente;

public:
    VectorDinamic(): size{0}, cap{5}, elemente{new ElemType[5]}{}

    VectorDinamic(const VectorDinamic& ot);

    int getSize();

    int getCap();

    ElemType& operator[](const int& poz) const;

    void redim();

    Iterator<ElemType> IteratorVector(){
        return Iterator<ElemType>(*this);
    }

    Iterator<ElemType> begin(){
        return Iterator<ElemType>(*this, 0);
    }

    Iterator<ElemType> end(){
        return Iterator<ElemType>(*this, size);
    }

    void push_back(const ElemType& newElem);

    void erase(const Iterator<ElemType>& it);

    ~VectorDinamic(){
        delete[] elemente;
    }
};

template<typename ElemType>
VectorDinamic<ElemType>::VectorDinamic(const VectorDinamic<ElemType> &ot) {
    this->cap = ot.cap;
    this->size = ot.size;
    this->elemente = new ElemType[ot.size];
    for (int i = 0; i < ot.size; i++){
        this->elemente[i] = ot.elemente[i];
    }
}

template<typename ElemType>
int VectorDinamic<ElemType>::getSize() {
    return size;
}

template<typename ElemType>
int VectorDinamic<ElemType>::getCap() {
    return cap;
}

template<typename ElemType>
ElemType& VectorDinamic<ElemType>::operator[](const int& poz) const{
    return elemente[poz];
}

template<typename ElemType>
void VectorDinamic<ElemType>::redim() {
    auto newElemente = new ElemType[2*cap];
    for (int i = 0; i < size; i++){
        newElemente[i] = this->elemente[i];
    }
    delete[] elemente;
    elemente = newElemente;
    cap *= 2;
}

template<typename ElemType>
void VectorDinamic<ElemType>::push_back(const ElemType &newElem) {
    if (size == cap)
        redim();
    elemente[size++] = newElem;
}

template<typename ElemType>
void VectorDinamic<ElemType>::erase(const Iterator<ElemType>& it) {
    for (int i = it.curent; i < size-1; i++){
        elemente[i] = elemente[i+1];
    }
    size--;
}


#endif //LAB_7_LIST_H
