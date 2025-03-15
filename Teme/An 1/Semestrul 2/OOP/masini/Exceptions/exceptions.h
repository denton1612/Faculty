//
// Created by Știube Denis on 26.06.2024.
//

#ifndef MASINI_EXCEPTIONS_H
#define MASINI_EXCEPTIONS_H
#include <string>
using namespace std;

class exceptions {
private:
    string mesaj;
public:
    exceptions(const string & mesaj): mesaj{mesaj} {}
    string getMesaj() {
        return mesaj;
    }
    ~exceptions() = default;
};


#endif //MASINI_EXCEPTIONS_H
