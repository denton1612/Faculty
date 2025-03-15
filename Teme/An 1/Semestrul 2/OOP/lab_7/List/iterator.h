//
// Created by Știube Denis on 05.04.2024.
//

#ifndef LAB_7_ITERATOR_H
#define LAB_7_ITERATOR_H
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/List/list.h"

template<typename ElemType>
class Iterator{
    friend class VectorDinamic<ElemType>;
private:

    Iterator() noexcept : curent{0}{}
    Iterator<ElemType>& operator=(const Iterator<ElemType>& it) = default;
    Iterator(VectorDinamic<ElemType>& v): vector{v}{}
    Iterator(VectorDinamic<ElemType>& v, const int& curent) noexcept: vector{v}, curent{curent} {}

    VectorDinamic<ElemType>& vector;
    int curent;

public:

    void prim();

    void urmator();

    ElemType& operator*();

    bool operator!=(const Iterator<ElemType>& it);

    bool operator==(const Iterator<ElemType>& it);

    bool operator<(const Iterator<ElemType>& it);

    bool operator>(const Iterator<ElemType>& it);

    Iterator<ElemType>& operator+(const int& poz);

    Iterator<ElemType>& operator-(const int& poz);

    Iterator<ElemType>& operator--();

    Iterator<ElemType>& operator++();

};

template<typename ElemType>
Iterator<ElemType>& Iterator<ElemType>::operator++() {
    curent++;
    return *this;
}

template<typename ElemType>
Iterator<ElemType>& Iterator<ElemType>::operator--() {
    curent--;
    return *this;
}

template<typename ElemType>
Iterator<ElemType>& Iterator<ElemType>::operator+(const int &poz) {
    curent += poz;
    return *this;
}

template<typename ElemType>
Iterator<ElemType>& Iterator<ElemType>::operator-(const int &poz) {
    curent -= poz;
    return *this;
}

template<typename ElemType>
void Iterator<ElemType>::prim() {
    curent = 0;
}

template<typename ElemType>
void Iterator<ElemType>::urmator() {
    curent++;
}

template<typename ElemType>
ElemType& Iterator<ElemType>::operator*() {
    return vector[curent];
}

template<typename ElemType>
bool Iterator<ElemType>::operator!=(const Iterator<ElemType> &it) {
    if (curent != it.curent)
        return true;
    return false;
}

template<typename ElemType>
bool Iterator<ElemType>::operator==(const Iterator<ElemType> &it) {
    if (curent == it.curent)
        return true;
    return false;
}

template<typename ElemType>
bool Iterator<ElemType>::operator>(const Iterator<ElemType> &it) {
    return this->curent > it.curent;
}

template<typename ElemType>
bool Iterator<ElemType>::operator<(const Iterator<ElemType> &it) {
    return this->curent < it.curent;
}

#endif //LAB_7_ITERATOR_H
