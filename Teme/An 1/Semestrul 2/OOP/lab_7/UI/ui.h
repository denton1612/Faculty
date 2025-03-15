//
// Created by Știube Denis on 31.03.2024.
//

#ifndef LAB_6_PB_7_UI_H
#define LAB_6_PB_7_UI_H
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_7/Service/service.h"
class UI{

private:
    Service& s;

public:
    UI() = delete;

    UI(Service& service): s{service}{

    }

    void addMedicament();

    void deleteMedicament();

    void updatePret();

    void updateSubst();

    void findMedicament();

    void filtruPret();

    void filtruSubst();

    void sortareDenumire();

    void sortareProducator();

    void sortareSubstPret();

    void addDefault();

    static void printMedicament(const Medicament& med);

    void printAll();

    void Meniu();

    void Run();

};
#endif //LAB_6_PB_7_UI_H
