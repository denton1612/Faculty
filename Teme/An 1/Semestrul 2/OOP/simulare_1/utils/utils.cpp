//
// Created by Știube Denis on 19.05.2024.
//

#include "utils.h"

void readLineProcesor(string& line, string& nume, unsigned int & nrThread, string& soclu, unsigned int & pret) {
    vector<string> tokens;
    int pos;
    while ((pos = line.find(',')) != string::npos) {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos+1);
    }
    tokens.push_back(line);
    nume = tokens[0];
    nrThread = stoi(tokens[1]);
    soclu = tokens[2];
    pret = stoi(tokens[3]);
}

void readLinePlacaDeBaza(string& line, string & nume, string & soclu, unsigned int & pret) {
    vector<string> tokens;
    int pos;
    while ((pos = line.find(',')) != string::npos) {
        tokens.push_back(line.substr(0, pos));
        line.erase(0, pos+1);
    }
    nume = tokens[0];
    soclu = tokens[1];
    pret = stoi(tokens[2]);
}

void clearFile(const string & filename) {
    ofstream out(filename);
    out.close();
}
