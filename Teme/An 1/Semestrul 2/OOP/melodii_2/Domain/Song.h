//
// Created by Știube Denis on 09.07.2024.
//

#ifndef MELODII_2_SONG_H
#define MELODII_2_SONG_H
#include <string>
using std::string;

class Song {
private:
    int id;
    string title;
    string artist;
    int rank;

public:
    Song(const int id, const string t, const string a, const int rank): id{id}, title{t}, artist{a}, rank{rank} {

    }
    int getId() const{
        return id;
    }
    string getTitle() const{
        return title;
    }
    string getArtist() const{
        return artist;
    }
    int getRank() const{
        return rank;
    }
    void setRank(const int newRank) {
        rank = newRank;
    }
    void setTitle(const string newTitle) {
        title = newTitle;
    }
};


#endif //MELODII_2_SONG_H
