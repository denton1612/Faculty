/*
 * FARMACIE
 * Creati o aplicatie care permite:
 * - gestiunea unei liste de medicamente. Medicament: denumire, pret, producator, substanta activa
 * - adaugare, stergere, modificare si afisare medicamente
 * - cautare medicament
 * - filtrare medicamente dupa pret, subst activa
 * - sortare medicamente dupa: denumire, producator, subst activa, pret
 */

#ifndef LAB_6_PB_7_MEDICAMENT_H
#define LAB_6_PB_7_MEDICAMENT_H
#include <string>
#include <utility>
#include <iostream>
using std::cout;
using std::string;

class Medicament {

private:
    string denumire;
    double pret;
    string producator;
    string subst;

public:
    // constructorul default
    Medicament() = default;

    // constructor de copiere
    Medicament (const Medicament& med): denumire{med.denumire}, pret{med.pret}, producator{med.producator}, subst{med.subst}{
        cout << "Copiere" << '\n';
    }

    // constructorul cu parametrii
    Medicament(string den, double pre, string pro, string sub): denumire{std::move(den)}, pret{pre}, producator{std::move(pro)}, subst{std::move(sub)}{

    }

    // returneaza denumirea unei instante
    string getDenumire() const;

    // returneaza pretul unei instante
    double getPret() const;


    // returneaza producatorul unei instante
    string getProducator() const;

    // returneaza substanta activa unei instante
    string getSubst() const;

    // seteaza o noua valoare pentru pretul unei instante
    // preconditii: newPret de tip double
    void setPret(const double& newPret);

    // seteaza o noua valoare pentru substanta activa a unei instante
    // preconditii: newSubst de tip string
    void setSubst(const string& newSubst);

    bool operator==(const Medicament& ot);

    bool operator!=(const Medicament& ot);
};


#endif //LAB_6_PB_7_MEDICAMENT_H
