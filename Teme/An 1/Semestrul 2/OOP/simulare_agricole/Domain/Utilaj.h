//
// Created by Știube Denis on 24.06.2024.
//

#ifndef SIMULARE_AGRICOLE_UTILAJ_H
#define SIMULARE_AGRICOLE_UTILAJ_H
#include <string>
using std::string;

class Utilaj {
private:
    int id;
    string denumire;
    string tip;
    int cilindri;

public:
    Utilaj(const int id, const string& denumire, const string& tip, const int cil): id{id}, denumire{denumire}, tip{tip}, cilindri{cil} {

    }

    int getId() const{
        return id;
    }

    string getDenumire() const{
        return denumire;
    }

    string getTip() const{
        return tip;
    }

    int getCilindri() const{
        return cilindri;
    }

    void setId(const int& id) {
        this->id = id;
    }

    void setDenumire(const string& denumire) {
        this->denumire = denumire;
    }

    void setTip(const string& tip) {
        this->tip = tip;
    }

    void setCilindri(const int& cilindri) {
        this->cilindri = cilindri;
    }
};


#endif //SIMULARE_AGRICOLE_UTILAJ_H
