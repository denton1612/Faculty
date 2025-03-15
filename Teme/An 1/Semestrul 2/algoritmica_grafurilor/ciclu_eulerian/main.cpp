#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <utility>

using namespace std;

bool existaMuchie(vector<vector<int>> & graf) {
    for (auto v : graf) {
        for (auto m : v) {
            if (m == 1)
                return true;
        }
    }
    return false;
}

vector<int> Hierholzer(vector<vector<int>> & graf) {
    vector<int> cicluEulerian;
    cicluEulerian.push_back(0);
    while (existaMuchie(graf)) {
        vector<int> ciclu;
        int start, curent;
        for (auto n : cicluEulerian) {
            auto it = std::find(graf[n].begin(), graf[n].end(), 1);
            if (it != graf[n].end()) {
                start = n;
                curent = it-graf[n].begin();
                *it = 0;
                graf[curent][n] = 0;
                cicluEulerian.insert(std::find(cicluEulerian.begin(), cicluEulerian.end(), n) + 1, curent);
                break;
            }
        }
        while (curent != start) {
            auto it = std::find(graf[curent].begin(), graf[curent].end(), 1);
            int nou = it - graf[curent].begin();
            graf[curent][nou] = 0;
            graf[nou][curent] = 0;
            cicluEulerian.insert(std::find(cicluEulerian.begin(), cicluEulerian.end(), curent) + 1, nou);
            curent = nou;
        }
    }
    return cicluEulerian;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n, m;
    in >> n >> m;
    vector<vector<int>> graf;
    vector<int> linie;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            linie.push_back(0);
        graf.push_back(linie);
        linie.clear();
    }
    int x, y;
    for (int i = 0; i < m; i++) {
        in >> x >> y;
        graf[x][y] = 1;
        graf[y][x] = 1;
    }
    vector<int> ciclu = Hierholzer(graf);
    ciclu.pop_back();
    for (auto nod : ciclu)
        out << nod << " ";
    return 0;
}
