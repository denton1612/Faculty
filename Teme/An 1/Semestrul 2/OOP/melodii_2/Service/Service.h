//
// Created by Știube Denis on 10.07.2024.
//

#ifndef MELODII_2_SERVICE_H
#define MELODII_2_SERVICE_H
#include "../FileRepository/RepoFIle.h"
#include "../Validator/Validator.h"
#include <map>
using std::map;

class Service {
private:
    RepoFIle & repo;
    Validator & val;
    map<int, int> ranks;

public:
    Service(RepoFIle & repo, Validator & v): repo{repo}, val{v} {
        completeRanks();
    }
    Service(const Service & ot) = delete;
    Service() = delete;
    void completeRanks();
    void addSongService(const int id, const string title, const string artist, const int rank);
    void updateRankService(const int id, const int newRank);
    void updateTitleService(const int id, const string newTitle);
    void removeSongService(const int id);
    vector<Song> sortSongs();
    bool ArtistSongs(const int id);
    vector<Song> & getAll() {
        return repo.getAll();
    }
    map<int, int> getRanks() {
        return ranks;
    }
    int getSize() {
        return repo.getSize();
    }
};

#endif //MELODII_2_SERVICE_H
