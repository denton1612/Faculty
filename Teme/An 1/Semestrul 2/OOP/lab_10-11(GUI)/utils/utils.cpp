//
// Created by Știube Denis on 20.04.2024.
//

#include "utils.h"
#include "../validare/errors.h"

void clearFile(const string& filename){
    ofstream out(filename);
    if (!out.is_open())
        throw Error("Nu s-a putut deschide fisierul!");
    out.close();
}