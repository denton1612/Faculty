//
// Created by Știube Denis on 13.04.2024.
//

#ifndef LAB_6_PB_7_ERRORS_H
#define LAB_6_PB_7_ERRORS_H
#include <string>
using std::string;

class Error{
private:
    string mesaj;

public:
    Error(string m) : mesaj{m}{};
    const string& getMesaj() const;
};
#endif //LAB_6_PB_7_ERRORS_H
