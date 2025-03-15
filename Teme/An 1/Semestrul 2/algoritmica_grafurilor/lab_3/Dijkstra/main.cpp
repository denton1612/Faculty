#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;
constexpr int inf=1000;

ifstream fin("input.txt");
ofstream fout("out.txt");

typedef struct{
    int n2;
    int w;
} neigh;

int main(){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int n, m, s;
    fin >> n >> m >> s;
    int d[n];
    for (int i = 0; i < n; i++)
        d[i] = inf;
    d[s] = 0;
    neigh l_i[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            l_i[i][j].n2 = -1;
        }
    int n1, n2, w;
    for (int i = 0; i < m; i++){
        fin >> n1 >> n2 >> w;
        int j = 0;
        while (l_i[n1][j].n2 != -1){
            j++;
        }
        neigh nou = neigh {n2, w};
        l_i[n1][j] = nou;
    }

    pq.push(pair(0, s));
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
    for (int i = 0; i < n; i++){
        if (d[i] == inf)
            fout << "inf ";
        else
            fout << d[i] << " ";
    }
}