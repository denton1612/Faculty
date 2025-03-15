#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
constexpr int inf = 1000;
ifstream fin("input.txt");

typedef struct{
    int n2;
    double w;
} neigh;

double get_pondere(int x1, int y1, int x2, int y2){
    double pondere = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    return pondere;
}

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<pair<int, int>> coord;
    int n, m, s, dest;
    cout << "Introduceti sursa si destinatia: " << endl;
    cin >> s >> dest;
    fin >> n >> m;
    double d[n];
    for (int i = 0; i < n; i++)
        d[i] = inf;
    d[s-1] = 0;
    int cord1, cord2;
    for (int i = 0; i < n; i++){
        fin >> cord1 >> cord2;
        coord.push_back(make_pair(cord1, cord2));
    }
    neigh l_i[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            l_i[i][j].n2 = -1;
        }
    int n1, n2;
    for (int i = 0; i < m; i++){
        fin >> n1 >> n2;
        double w = get_pondere(coord[n1-1].first, coord[n1-1].second, coord[n2-1].first, coord[n2-1].second);
        int j = 0;
        while (l_i[n1-1][j].n2 != -1){
            j++;
        }
        neigh nou = neigh {n2-1, w};
        l_i[n1-1][j] = nou;
    }
    pq.push(pair(0, s-1));
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        int j = 0;
        while(l_i[u][j].n2 != -1)
        {
            neigh neigh1 = l_i[u][j];
            if (d[neigh1.n2] > d[u] + neigh1.w) {
                d[neigh1.n2] = d[u] + neigh1.w;
                pq.push(pair(d[neigh1.n2], neigh1.n2));
            }
            j++;
        }
    }
    cout << d[dest-1];
}