//
// Created by Știube Denis on 26.06.2024.
//

#ifndef MASINI_CAR_H
#define MASINI_CAR_H
#include <string>
#include <fstream>
using namespace std;

class Car {
private:
    string nri;
    string denumire;
    int an;
    string tip;
public:
    Car(const string nri, const string den, const int an, const string tip): nri{nri}, denumire{den}, an{an}, tip{tip} {}
    string getNri() const {
        return nri;
    }
    string getDenumire() const {
        return denumire;
    }
    int getAn() const {
        return an;
    }
    string getTip() const {
        return tip;
    }
    void incrementAn() {
        an++;
    }
    void decrementAn() {
        an--;
    }
    friend std::ofstream& operator<< (ofstream & out, const Car& c);
};

#endif //MASINI_CAR_H
