//
// Created by Știube Denis on 11.07.2024.
//

#include "Validator.h"

void Validator::ValidateSong(const Song &s) {
    if (s.getArtist().empty() or s.getTitle().empty() or s.getRank() < 0 or s.getRank() > 10)
        throw Error{"Campurile melodiei sunt invalide!"};
}