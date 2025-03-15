//
// Created by Știube Denis on 31.03.2024.
//

#ifndef LAB_6_PB_7_REPOSITORY_H
#define LAB_6_PB_7_REPOSITORY_H
#include <vector>
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/Domain/medicament.h"
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/List/list.h"
#include "../List/iterator.h"
#include "../Validare/Validare.h"
using std::vector;

class Repository{

private:
    VectorDinamic<Medicament> lista;

public:

    Repository(const Repository& repo) = delete;

    Repository() = default;

    // adauga un nou medicament in vectorul de medicamente
    // param newMedicament(Medicament): medicamentul ce va fi adaugat
    void addMedicament(const Medicament& newMedicament);

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

    Medicament& operator[](const int& poz);

    // returneaza medicamentele stocate

    VectorDinamic<Medicament> getAll() const;

    // returneaza numarul medicamentelor stocate
    int getSize(){
        return lista.getSize();
    }
};

#endif //LAB_6_PB_7_REPOSITORY_H
