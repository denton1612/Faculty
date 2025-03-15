//
// Created by Știube Denis on 24.06.2024.
//

#include "utils.h"

int to_int(string& text) {
    int n = 0;
    for (auto c : text) {
        n = n * 10 + (c-'0');
    }
    return n;
}