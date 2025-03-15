//
// Created by Știube Denis on 31.03.2024.
//

#ifndef LAB_6_PB_7_UI_H
#define LAB_6_PB_7_UI_H
#include "/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/lab_6_pb_7/service/service.h"
#include <utility>
#include <map>
using std::pair;
using std::map;

class UI{

private:
    Service& s;

public:
    UI() = delete;

    UI(Service& service): s{service}{

    }

    void addMedicament();

    void addMedicamentReteta();

    void addMedicamentRandomReteta();

    void deleteMedicament();

    void deleteAllReteta();

    void exportToFile();

    void updatePret();

    void updateSubst();

    void findMedicament();

    void filtruPret();

    void filtruSubst();

    void sortareDenumire();

    void sortareProducator();

    void sortareSubstPret();

    void undo();

    void addDefault();

    static void printMedicament(const Medicament& med);

    static void printAll(vector<Medicament>&);

    static void printAllDict(map<pair<string, string>, Medicament>&);

    static void Meniu();

    void Run();

};
#endif //LAB_6_PB_7_UI_H
