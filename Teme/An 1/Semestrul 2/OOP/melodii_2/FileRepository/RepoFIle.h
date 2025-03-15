//
// Created by Știube Denis on 09.07.2024.
//

#ifndef MELODII_2_REPOFILE_H
#define MELODII_2_REPOFILE_H
#include <vector>
#include <fstream>
#include <algorithm>
#include "../Domain/Song.h"
#include "../Exceptions/Error.h"
#include "../Service/Service.h"
using namespace std;
using std::vector;
using std::ifstream;
using std::ofstream;

class RepoFIle {
    friend class Service;
private:
    string filename;
    vector<Song> songs;
    void loadFromFile();
    void saveToFile();

public:
    RepoFIle(string f): filename{f} {
        loadFromFile();
    }
    void addSong(Song s);
    void removeSong(const int id);
    int findSong(int id);
    vector<Song> & getAll() {
        return songs;
    }
    vector<Song> getAllCopy() {
        return songs;
    }
    int getSize() {
        return songs.size();
    }
};


#endif //MELODII_2_REPOFILE_H
