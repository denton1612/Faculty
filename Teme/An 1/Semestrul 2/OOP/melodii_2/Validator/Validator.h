//
// Created by Știube Denis on 11.07.2024.
//

#ifndef MELODII_2_VALIDATOR_H
#define MELODII_2_VALIDATOR_H
#include "../Exceptions/Error.h"
#include "../Domain/Song.h"

class Validator {
public:
    Validator() = default;
    void ValidateSong(const Song & s);
};


#endif //MELODII_2_VALIDATOR_H
