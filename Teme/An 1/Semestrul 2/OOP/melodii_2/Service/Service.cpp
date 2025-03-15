//
// Created by Știube Denis on 10.07.2024.
//

#include "Service.h"

void Service::completeRanks() {
    for (int i = 0; i < 11; i++)
        ranks[i] = 0;
    for (auto & s : getAll()) {
        ranks[s.getRank()]++;
    }
}

void Service::addSongService(const int id, const std::string title, const std::string artist, const int rank) {
    val.ValidateSong(Song{id, title, artist, rank});
    repo.addSong(Song{id, title, artist, rank});
    completeRanks();
}

void Service::updateTitleService(const int id, const std::string newTitle) {
    int pos = repo.findSong(id);
    auto it = repo.getAll().begin() + pos;
    it->setTitle(newTitle);
    repo.saveToFile();
}

void Service::updateRankService(const int id, const int newRank) {
    int pos = repo.findSong(id);
    auto it = repo.getAll().begin() + pos;
    it->setRank(newRank);
    completeRanks();
    repo.saveToFile();
}

void Service::removeSongService(const int id) {
    if (!ArtistSongs(id))
        throw Error{"Melodia nu poate fi stearsa, este singura de la artist!"};
    repo.removeSong(id);
    completeRanks();
}

vector<Song> Service::sortSongs() {
    vector<Song> copy = repo.getAllCopy();
    std::sort(copy.begin(), copy.end(), [](Song & s1, Song & s2) {
        return s1.getRank() < s2.getRank();
    });
    return copy;
}

bool Service::ArtistSongs(const int id) {
    int nr = 0;
    int poz = repo.findSong(id);
    string artist = repo.getAll()[poz].getArtist();
    for (auto & s : repo.getAll()) {
        if (s.getArtist() == artist)
            nr++;
    }
    return nr > 1;
}