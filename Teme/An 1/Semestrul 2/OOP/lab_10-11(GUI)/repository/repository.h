//
// Created by Știube Denis on 31.03.2024.
//

#ifndef LAB_6_PB_7_REPOSITORY_H
#define LAB_6_PB_7_REPOSITORY_H
#include <vector>
#include <algorithm>
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_6_pb_7/domain/Medicament.h"
#include "../repository/repoAbstract.h"
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_6_pb_7/validare/errors.h"
using std::vector;

class Repository : public repoAbstract{
    friend class Reteta;

private:
    vector<Medicament> lista;

public:

//    Repository(const Repository& repo) = delete;

    Repository() = default;

    // adauga un nou medicament in vectorul de medicamente
    // param newMedicament(Medicament): medicamentul ce va fi adaugat
    void addMedicament(const Medicament& newMedicament) override;

    // sterge un medicament din farmacie
    // param medicament(Medicament): medicamentul ce va fi sters
    void deleteMedicament(const Medicament& medicament) override;

    // cauta un medicament in farmacie
    // param denumire(string): denumriea medicamentului cautat
    // param prod(string): producatorul medicamentului cautat
    // returneaza adevarat daca medicamentul exista in farmacie sau fals in caz contrar
    bool findMedicament(const string& denumire, const string& prod) override;

    // modifica un medicament din farmacie
    // param oldMedicament(Medicament): medicamentul inainte de a fi modificat
    // param newMedicament(Medicament): medicamentul dupa modificare
    void updateMedicament(const Medicament& oldMedicament, const Medicament& newMedicament) override;

    // returneaza medicamentele stocate
    vector<Medicament>& getAll() override;

    vector<Medicament> getAllCopy() override;

    // returneaza numarul medicamentelor stocate
    unsigned int getSize() const override{
        return lista.size();
    }
};

#endif //LAB_6_PB_7_REPOSITORY_H
