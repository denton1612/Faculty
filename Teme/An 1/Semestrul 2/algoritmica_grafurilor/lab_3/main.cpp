#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

constexpr int INF = 1000;

typedef struct{
    int i;
    int j;
    int w;
} edge;

int main(int argc, char * argv[]) {
    if (argc != 3){
        cout << "Eroare!";
        return 0;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n, m, s;
    fin >> n >> m >> s;
    int d[n];
    for (int i = 0; i < n; i++)
        d[i] = INF;
    d[s] = 0;
    edge edges[m];
    int n1, n2, w;
    for (int i = 0; i < m; i++){
        fin >> n1 >> n2 >> w;
        edges[i].i = n1;
        edges[i].j = n2;
        edges[i].w = w;
    }
    for (int i = 1; i < n; i++){
        for (edge e : edges){
            if (d[e.j] > d[e.i] + e.w)
                d[e.j] = d[e.i] + e.w;
        }
    }
    for (edge e : edges){
        if (d[e.j] > d[e.i] + e.w) {
            cout << "Graful contine cicluri negative" << endl;
            return 0;
        }
    }
    for (int dist : d){
        if (dist == INF)
            fout << "INF" << " ";
        else
            fout << dist << " ";
    }
    fin.close();
    fout.close();
    return 0;
}
