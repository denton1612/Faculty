//
// Created by Știube Denis on 27.06.2024.
//

#include "utils.h"

bool valid(const string s) {
    int contX = 0, contL = 0;
    for (auto & c : s) {
        if (c == 'X')
            contX++;
        if (c == '-')
            contL++;
    }
    return (contX + contL == s.size());
}