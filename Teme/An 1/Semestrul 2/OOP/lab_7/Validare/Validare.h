//
// Created by Știube Denis on 08.04.2024.
//

#ifndef LAB_7_VALIDARE_H
#define LAB_7_VALIDARE_H
#include <iostream>
using std::string;

class Error{
private:
    string mesaj;

public:
    Error(string m) : mesaj{m}{};
    const string& getMesaj() const;
};


#endif //LAB_7_VALIDARE_H
