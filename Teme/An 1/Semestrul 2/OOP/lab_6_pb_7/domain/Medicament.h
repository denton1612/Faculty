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

    // constructor medicament
    Medicament(const string& den, const string& prod): denumire{den}, producator{prod}{

    }

    // constructor de copiere
    Medicament (const Medicament& med): denumire{med.denumire}, pret{med.pret}, producator{med.producator}, subst{med.subst}{
//        cout << "Copiere" << '\n';
    }

    // constructorul cu parametrii
    Medicament(string den, double pre, string pro, string sub): denumire{std::move(den)}, pret{pre}, producator{std::move(pro)}, subst{std::move(sub)}{

    }

    // returneaza denumirea unei instante
    [[nodiscard]] string getDenumire() const;

    // returneaza pretul unei instante
    [[nodiscard]] double getPret() const;

    // returneaza producatorul unei instante
    [[nodiscard]] string getProducator() const;

    // returneaza substanta activa unei instante
    [[nodiscard]] string getSubst() const;

    // seteaza o noua valoare pentru pretul unei instante
    // preconditii: newPret de tip double
    void setPret(const double& newPret);

    // seteaza o noua valoare pentru substanta activa a unei instante
    // preconditii: newSubst de tip string
    void setSubst(const string& newSubst);

    // definirea egalitatii intre 2 medicamente
    bool operator==(const Medicament& med) const;
};


#endif //LAB_6_PB_7_MEDICAMENT_H
