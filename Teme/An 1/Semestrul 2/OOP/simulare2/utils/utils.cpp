//
// Created by Știube Denis on 20.05.2024.
//

#include "utils.h"

void clearFile(string filename) {
    ofstream out(filename);
    out.close();
}