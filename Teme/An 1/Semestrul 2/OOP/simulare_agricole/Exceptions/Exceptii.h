//
// Created by Știube Denis on 24.06.2024.
//

#ifndef SIMULARE_AGRICOLE_EXCEPTII_H
#define SIMULARE_AGRICOLE_EXCEPTII_H
#include <string>
using std::string;

class RepoException {
private:
    string mesaj;

public:
    RepoException(const string mesaj): mesaj{mesaj} {

    }
    string getMesaj() const {
        return mesaj;
    }
};

class ServiceException {
private:
    string mesaj;

public:
    ServiceException(const string mesaj): mesaj{mesaj} {

    }
    string getMesaj() const {
        return mesaj;
    }
};


#endif //SIMULARE_AGRICOLE_EXCEPTII_H
