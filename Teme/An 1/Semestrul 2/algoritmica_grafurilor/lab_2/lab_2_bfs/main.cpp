#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

ifstream fin("cmake-build-debug/input.txt");
int a[101][101] = {}, v[100] = {}, nr_noduri, nr_muchii, x;

void BFS(int x){
    queue <int> q;
    bool g[100];
    int p[100];
    g[x] = true;
    p[x] = 0;
    q.push(x);
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        cout << nod << " ";
        for (int j = 0; j < nr_noduri; j++){
            if (a[nod][j] == 1 && g[j] == 0){
                g[j] = true;
                p[j] = nod;
                q.push(j);
            }
        }
    }
    cout << endl;
    cout << "Vectori de parinti: ";
    for (int i = 0; i < nr_noduri; i++)
        cout << p[i] << " ";
}

int main() {
    fin >> nr_noduri >> nr_muchii >> x;
    for (int i = 0; i < nr_muchii; i++){
        int m, n;
        fin >> m >> n;
        a[m][n] = 1;
        a[n][m] = 1;
    }
    BFS(x);
}
