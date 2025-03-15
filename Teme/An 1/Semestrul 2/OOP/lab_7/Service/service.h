//
// Created by Știube Denis on 31.03.2024.
//

#ifndef LAB_6_PB_7_SERVICE_H
#define LAB_6_PB_7_SERVICE_H
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/Repository/repository.h"
#include <algorithm>
using std::swap;
using std::string;
using std::sort;
using std::distance;
class Service{

private:
    Repository& repo;

public:
    // anulam constructorul default fara parametrii
    Service() = delete;

    Service(const Service& service) = delete;

    // constructorul ce primeste ca parametru un obiect de tip repository
    explicit Service(Repository& repository): repo{repository}{}

    // adauga un nou medicament in vectorul de medicamente
    // param denumire(string): denumirea
    // param pret(double): pretul
    // pararm producator(string): producatorul
    // param subst(string): substanta
    void addMedicament(const string& denumire, const double& pret, const string& producator, const string& subst);

    // sterge medicamentul de pe pozitia poz din vectorul de medicamente
    // param poz(int): pozitia medicamentului din vector ce va fi sters
    void deleteMedicament(const int& poz);

    // modifica pretul medicamentului de pe pozitia poz din vectorul de medicamente
    // param poz(int): pozitia medicamentului din vector ce va fi modificat
    // param newPret(double): noul pret al medicamentului
    void updatePret(const int& poz, const double& newPret);

    // modifica substanta medicamentului de pe pozitia poz din vectorul de medicamente
    // param poz(int): pozitia medicamentului din vector ce va fi modificat
    // param newSubst(string): noua substanta a medicamentului
    void updateSubst(const int& poz, const string& newSubst);

    // verifica daca exista un medicament in vectorul de medicamente
    // param denumire(string): denumirea medicamentului cautat
    // param producator(string): producatorul medicamentului cautat
    [[nodiscard]] bool findMedicament(const string& denumire, const string& producator) const;

    // returneaza vectorul de medicamente din repository
    [[nodiscard]] VectorDinamic<Medicament> getAll() const{
        return repo.getAll();
    }

    // filtreaza vectorul de medicamente dupa pret
    // param pret(double): pretul pentru filtrare
    [[nodiscard]] VectorDinamic<Medicament> filtruPret(const double& pret) const;

    // filtreaza vectorul de medicamente dupa substanta activa
    // param subst(string): substanta pentru filtrare
    [[nodiscard]] VectorDinamic<Medicament> filtruSubst(const string& subst) const;

    // sorteaza vectorul de medicamente dupa denumire
    VectorDinamic<Medicament> sortareDenumire();

    // sorteaza vectorul de medicamente dupa producator
    VectorDinamic<Medicament> sortareProducator();

    // sorteaza vectorul de medicamente dupa substanta activa + pret
    VectorDinamic<Medicament> sortareSubstPret();

    // returneaza dimensiunea vectorului de medicamente
    [[nodiscard]] int getSize() const{
        return repo.getSize();
    }

};

#endif //LAB_6_PB_7_SERVICE_H
