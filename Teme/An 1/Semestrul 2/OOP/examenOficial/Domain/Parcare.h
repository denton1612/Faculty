//
// Created by Știube Denis on 27.06.2024.
//

#ifndef EXAMENOFICIAL_PARCARE_H
#define EXAMENOFICIAL_PARCARE_H
#include <string>
using namespace std;

class Parcare {
private:
    string adresa;
    int linii, col;
    string stare;

public:

    // constructor cu stare default
    Parcare(const string & adresa, const int linii, const int col): adresa{adresa}, linii{linii}, col{col} {
        for (int i = 0; i < linii * col; i++)
            stare.push_back('-');
    }

    // constructor cu stare data
    Parcare(const string & adresa, const int linii, const int col, const string & stare): adresa{adresa}, linii{linii}, col{col}, stare{stare} {}
    string getAdresa() const{
        return adresa;
    }

    // get ere
    int getLinii() const{
        return linii;
    }

    int getCol() const{
        return col;
    }
    string getStare() const{
        return stare;
    }

    // set err
    void setLinii(const int l) {
        linii = l;
    }
    void setCol(const int c) {
        col = c;
    }
    void setStare(const string s) {
        stare = s;
    }
};


#endif //EXAMENOFICIAL_PARCARE_H
