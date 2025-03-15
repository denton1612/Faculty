//
// Created by Știube Denis on 20.05.2024.
//

#include "utils.h"

int to_int(string & s) {
    int n = 0;
    int p = 10;
    for (auto c : s)
        n = n * p + (c - '0');
    return n;
}