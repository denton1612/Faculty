//
// Created by Știube Denis on 19.05.2024.
//

#ifndef SIMULARE_1_UTILS_H
#define SIMULARE_1_UTILS_H
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void readLineProcesor(string& line, string& nume, unsigned int & nrThread, string& soclu, unsigned int & pret);
void readLinePlacaDeBaza(string& line, string & nume, string & soclu, unsigned int & pret);
void clearFile(const string & filename);
#endif //SIMULARE_1_UTILS_H
