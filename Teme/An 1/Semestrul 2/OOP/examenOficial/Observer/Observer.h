//
// Created by Știube Denis on 27.06.2024.
//

#ifndef EXAMENOFICIAL_OBSERVER_H
#define EXAMENOFICIAL_OBSERVER_H
#include <vector>
using std::vector;

class Observer {
public:
    virtual void update() = 0;
};

class Observable {
private:
    vector<Observer*> interesati;
public:
    Observable() = default;
    // adugare observator
    void addObserver(Observer* obs);

    // elimina un observator
    void removeObserver(Observer* obs);
protected:
    // notificare observatori pentru a si modifica starea
    void notify();
};


#endif //EXAMENOFICIAL_OBSERVER_H
