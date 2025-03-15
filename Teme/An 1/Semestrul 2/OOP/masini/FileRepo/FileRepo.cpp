//
// Created by Știube Denis on 26.06.2024.
//

#include "FileRepo.h"

void FileRepo::loadFromFile() {
    ifstream in(filename);
    string line;
    string nri, den, tip;
    int an;
    while (getline(in, line)) {
        int pos = line.find(", ");
        nri = line.substr(0, pos);
        line.erase(0, pos+2);
        pos = line.find(", ");
        den = line.substr(0, pos);
        line.erase(0, pos+2);
        pos = line.find(", ");
        an = stoi(line.substr(0, pos));
        line.erase(0, pos+2);
        tip = line;
        cars.push_back(Car{nri, den, an, tip});
    }
    in.close();
}

void FileRepo::saveInFile() {
    ofstream out(filename);
    for (auto & c : cars)
        out << c << '\n';
    out.close();
}

void FileRepo::deleteCar(const std::string &nri) {
    auto it = std::find_if(cars.begin(), cars.end(), [nri](const Car & c) {
        return c.getNri() == nri;
    });
    if (it == cars.end())
        throw exceptions("Masina nu exista!");
    cars.erase(it);
    saveInFile();
}