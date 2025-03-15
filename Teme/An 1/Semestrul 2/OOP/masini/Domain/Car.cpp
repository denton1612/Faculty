//
// Created by Știube Denis on 26.06.2024.
//

#include "Car.h"

ofstream & operator<<(ofstream & out, const Car& car) {
    out << car.nri << ", " << car.denumire << ", " << car.an << ", " << car.tip;
    return out;
}