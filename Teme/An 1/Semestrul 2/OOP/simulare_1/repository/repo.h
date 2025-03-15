//
// Created by Știube Denis on 18.05.2024.
//

#ifndef SIMULARE_1_REPO_H
#define SIMULARE_1_REPO_H
#include "../domain/procesor.h"
#include "../domain/placaDeBaza.h"
#include "../validare/eroare.h"
#include "../utils/utils.h"
#include <vector>
#include <fstream>

using std::vector;
using namespace std;
class repo {

private:
    vector<procesor> procesoare;
    vector<placaDeBaza> placiDeBaza;
    string filename1;
    string filename2;
    void saveToFileProcesor();
    void loadFromFileProcesor();
    void saveToFilePlacaDeBaza();
    void loadFromFilePlacaDeBaza();

public:
    repo() = delete;
    repo(const repo&) = delete;
    repo(const string& filename1, const string& filename2): filename1{filename1}, filename2{filename2} {
        loadFromFileProcesor();
        loadFromFilePlacaDeBaza();
    }
    void addProcesor(const procesor& p);
    void addPlacaDeBaza(const placaDeBaza& pb);
    vector<procesor> getProcesoareCopie() {
        return procesoare;
    }
    vector<procesor>& getProcesoare() {
        return procesoare;
    }
    vector<placaDeBaza> getPlaciDeBazaCopie() {
        return placiDeBaza;
    }
    vector<placaDeBaza>& getPlaciDeBaza() {
        return placiDeBaza;
    }
    int getProcesoareSize() {
        return procesoare.size();
    }
    int getPlaciSize() {
        return placiDeBaza.size();
    }
};


#endif //SIMULARE_1_REPO_H
