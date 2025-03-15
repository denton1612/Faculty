//
// Created by Știube Denis on 20.05.2024.
//

#ifndef SIMULARE2_EROARE_H
#define SIMULARE2_EROARE_H
#include <string>
using std::string;

class eroare {
private:
    string mesaj;
public:
    eroare(const string & mesaj): mesaj{mesaj} {

    }
    string getMesaj() {
        return mesaj;
    }
};


#endif //SIMULARE2_EROARE_H
