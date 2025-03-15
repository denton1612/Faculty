//
// Created by Știube Denis on 19.04.2024.
//

#ifndef LAB_6_PB_7_INFILEREPOSITORY_H
#define LAB_6_PB_7_INFILEREPOSITORY_H
#include <fstream>
#include "repository.h"
using std::ifstream;
using std::ofstream;

class InFileRepository : public Repository{
private:
    string filename;
    void loadFromFile();
    void saveToFile();

public:
    explicit InFileRepository(const string& filename);

    InFileRepository() = delete;

    void addMedicament(const Medicament& newMedicament) override{
        Repository::addMedicament(newMedicament);
        saveToFile();
    }

    void deleteMedicament(const Medicament& medicament) override{
        Repository::deleteMedicament(medicament);
        saveToFile();
    }

    void updateMedicament(const Medicament& oldMedicament, const Medicament& newMedicament) override{
        Repository::updateMedicament(oldMedicament, newMedicament);
        saveToFile();
    }
};

#endif //LAB_6_PB_7_INFILEREPOSITORY_H
