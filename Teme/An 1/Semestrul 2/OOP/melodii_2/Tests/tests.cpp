//
// Created by Știube Denis on 09.07.2024.
//

#include "tests.h"

void testDomain() {
    Song s1{1, "Hot", "Maluma", 7};
    assert(s1.getId() == 1);
    assert(s1.getArtist() == "Maluma");
    assert(s1.getRank() == 7);
    s1.setRank(5);
    assert(s1.getRank() == 5);
}

void testRepo() {
    RepoFIle repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/melodii_2/Tests/songs.txt"};
    assert(repo.getSize() == 10);
//    vector<Song> copy = repo.getAllCopy();
//    assert(copy.size() == 10);
    repo.addSong(Song{21, "Marie", "Grasu", 9});
    assert(repo.getSize() == 11);
    assert(repo.getAll()[10].getId() == 21);
    assert(repo.getAll()[10].getRank() == 9);
    try {
        repo.addSong(Song{3, "x", "y", 5});
        assert(false);
    }
    catch (Error & err) {
        assert(err.getMessage() == "Exista deja o melodie cu acest id!");
    }
    repo.removeSong(21);
    assert(repo.getSize() == 10);
    try {
        repo.removeSong(100);
        assert(false);
    }
    catch (Error & err) {
        assert(err.getMessage() == "Melodia cu id-ul dat nu exista!");
    }
}

void testService() {
    RepoFIle repo{"/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/melodii_2/Tests/songs.txt"};
    assert(repo.getSize() == 10);
    Validator v;
    Service s{repo, v};
    assert(s.getSize() == 10);
    s.addSongService(100, "x", "Ian", 9);
    assert(s.getSize() == 11);
    assert(s.getAll()[10].getRank() == 9);
    assert(s.getAll()[10].getId() == 100);
    s.removeSongService(100);
    assert(s.getSize() == 10);
    assert(s.getAll()[0].getRank() == 7);
    s.updateRankService(s.getAll()[0].getId(), 2);
    assert(s.getAll()[0].getRank() == 2);
    s.updateRankService(s.getAll()[0].getId(), 7);
    vector<Song> sorted = s.sortSongs();
    assert(sorted[0].getRank() == 5);
    assert(sorted[0].getId() == 6);
    assert(!s.ArtistSongs(6));
    assert(s.ArtistSongs(2));
    map<int, int> ranks = s.getRanks();
    assert(ranks[7] == 2 and ranks[10] == 3 and ranks[5] == 1);
}

void testAll() {
    testDomain();
    testRepo();
    testService();
}