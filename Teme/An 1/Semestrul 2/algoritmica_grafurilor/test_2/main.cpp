#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int cond1(vector<vector<int>> & graf, map<int, pair<int, int>> & noduri, int u) {
    int i = 0;
    for (auto w : graf[u]) {
        if (noduri[u].second and w > 0 and noduri[u].first == noduri[i].first + 1)
            return i;
        i++;
    }
    return -1;
}

int cond2(vector<vector<int>> & graf, map<int, pair<int, int>> & noduri, int u) {
    int i = 0;
    vector<int> inaltimi;
    for (auto p : noduri) {
        if (graf[u][i] > 0)
            inaltimi.push_back(p.first);
        i++;
    }
    if (inaltimi.empty())
        return -1;
    int minim = *min_element(inaltimi.begin(), inaltimi.end());
    if (noduri[u].first > minim || noduri[u].second == 0)
        return -1;
    return minim;
}

map<int, pair<int, int>> initializare(vector<vector<int>> & graf) {
    map<int, pair<int, int>> noduri;
    noduri[0] = make_pair(graf.size(), 0); // (inaltime, exces)
    for (int i = 1; i < graf.size(); i++)
        noduri[i] = make_pair(0, 0);
    int i = 0;
    for (auto w : graf[0]) {
        if (w > 0) {
            int exces = noduri[0].second;
            exces -= w;
            noduri[0] = make_pair(graf.size(), exces);
            noduri[i] = make_pair(0, w);
            graf[0][i] = 0;
            graf[i][0] = w;
        }
        i++;
    }
    return noduri;
}

bool pompare(vector<vector<int>> & graf, map<int, pair<int, int>> & noduri, int u, int v) { // u -> v
    int min = noduri[u].second;
    if (graf[u][v] < min)
        min = graf[u][v];
    int exces_u = noduri[u].second;
    exces_u -= min;
    noduri[u] = make_pair(noduri[u].first, exces_u);
    int exces_v = noduri[v].second;
    exces_v += min;
    noduri[v] = make_pair(noduri[v].first, exces_v);
    graf[u][v] -= min;
    graf[v][u] += min;
}

void inaltare(vector<vector<int>> & graf, map<int, pair<int, int>> & noduri, int u) {
    int h = noduri[u].first;
    h = cond2(graf, noduri, u) + 1;
    noduri[u] = make_pair(h, noduri[u].second);
}

int pompare_preflux(vector<vector<int>> & graf, map<int, pair<int, int>> & noduri) {
    while (true) {
        int i;
        for (i = 1; i < graf.size()-1; i++) {
            if (cond1(graf, noduri, i) != -1) {
                int v = cond1(graf, noduri, i);
                pompare(graf, noduri, i, v);
                break;
            }
        }
        if (i < graf.size()-1)
            continue;
        for (i = 1; i < graf.size()-1; i++) {
            if (cond2(graf, noduri, i) !=- 1) {
                inaltare(graf, noduri, i);
                break;
            }
        }
        if (i < graf.size()-1)
            continue;
        break;
    }
    return noduri[graf.size()-1].second;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n, m, e;
    in >> n >> m >> e;
    vector<vector<int>> graf;
    vector<int> linie;
    for (int i = 0; i < n+m+2; i++){
        for (int j = 0; j < n+m+2; j++)
            linie.push_back(0);
        graf.push_back(linie);
        linie.clear();
    }
    int x, y;
    for (int i = 0; i < e; i++){
        in >> x >> y;
        graf[x][y+n] = 1;
    }
    for (int i = 1; i < n+m+1; i++) {
        graf[0][i] = 1;
        graf[i][n+m+1] = 1;
    }
    map<int, pair<int, int>> noduri = initializare(graf);
    out << pompare_preflux(graf, noduri);
    return 0;
}

