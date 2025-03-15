//
// Created by Știube Denis on 14.04.2024.
//

#ifndef LAB_6_PB_7_RETETA_H
#define LAB_6_PB_7_RETETA_H

#include "../domain/Medicament.h"
#include <vector>
#include <string>

using std::vector;
using std::string;

class Reteta{
private:
    vector<Medicament> lista;

public:
    // adauga un medicament in reteta
    void addMedicament(const Medicament& med);

    // goleste reteta
    void deleteAll();

    vector<Medicament>& getAll(){
        return lista;
    }

    [[nodiscard]] unsigned long getSize() const{
        return lista.size();
    }

};

#endif //LAB_6_PB_7_RETETA_H
