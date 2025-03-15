//
// Created by Știube Denis on 23.05.2024.
//

#ifndef LAB_6_PB_7_OBSERVABLE_H
#define LAB_6_PB_7_OBSERVABLE_H
#include <vector>
#include <algorithm>
#include "Observer.h"
using std::vector;

class Observer;

class Observable {
private:
    vector<Observer*> interesati;
public:
    Observable() = default;
    // adugare observator
    virtual void addObserver(Observer* obs);

    // elimina un observator
    virtual void removeObserver(Observer* obs);
protected:
    // notificare observatori pentru a si modifica starea
    virtual void notify();
};


#endif //LAB_6_PB_7_OBSERVABLE_H
