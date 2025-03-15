//
// Created by Știube Denis on 09.07.2024.
//

#include "RepoFIle.h"

void RepoFIle::loadFromFile() {
    ifstream in(filename);
    string line;
    int id, rank;
    string title, artist;
    while (getline(in, line)) {
        int pos = line.find(", ");
        id = stoi(line.substr(0, pos));
        line.erase(0, pos+2);
        pos = line.find(", ");
        title = line.substr(0, pos);
        line.erase(0, pos+2);
        pos = line.find(", ");
        artist = line.substr(0, pos);
        line.erase(0, pos+2);
        rank = stoi(line);
        songs.push_back(Song{id, title, artist, rank});
    }
    in.close();
}

void RepoFIle::saveToFile() {
    ofstream out(filename);
    for (auto & s : songs) {
        out << std::to_string(s.getId()) + ", " + s.getTitle() + ", " + s.getArtist() + ", " + std::to_string(s.getRank()) + "\n";
    }
    out.close();
}

void RepoFIle::addSong(Song s) {
    auto it = std::find_if(songs.begin(), songs.end(), [&s](Song & s1) {
        return s.getId() == s1.getId();
    });
    if (it != songs.end())
        throw Error{"Exista deja o melodie cu acest id!"};
    songs.push_back(s);
    saveToFile();
}

int RepoFIle::findSong(int id) {
    auto it = std::find_if(songs.begin(), songs.end(), [&id](Song & s1) {
        return s1.getId() == id;
    });
    if (it == songs.end())
        throw Error("Melodia cu id-ul dat nu exista!");
    return it-songs.begin();
}

void RepoFIle::removeSong(const int id) {
    int poz = findSong(id);
    songs.erase(songs.begin()+poz);
    saveToFile();
}