//
// Created by Știube Denis on 18.05.2024.
//

#ifndef SIMULARE_1_EROARE_H
#define SIMULARE_1_EROARE_H
#include <string>
using std::string;

class eroare {

private:
    string mesaj;

public:
    eroare(const string& mesaj): mesaj{mesaj} {

    }
    string& getMesaj() {
        return mesaj;
    }
};


#endif //SIMULARE_1_EROARE_H
