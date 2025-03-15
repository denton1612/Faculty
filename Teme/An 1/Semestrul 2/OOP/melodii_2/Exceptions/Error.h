//
// Created by Știube Denis on 09.07.2024.
//

#ifndef MELODII_2_ERROR_H
#define MELODII_2_ERROR_H
#include <string>
using std::string;

class Error {
private:
    string message;
public:
    Error(const string & m): message{m} {

    }
    string getMessage() {
        return message;
    }
};


#endif //MELODII_2_ERROR_H
