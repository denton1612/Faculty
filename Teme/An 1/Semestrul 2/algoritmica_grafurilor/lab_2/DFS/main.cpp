#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("input.txt");

int a[101][101] = {}, v[100] = {}, nr_noduri, nr_muchii, x;

void DFS(int x){
    cout << x << " ";
    v[x] = 1;
    for (int i = 0; i < nr_noduri; i++)
        if (v[i] == 0 && a[x][i] == 1)
            DFS(i);
}

int main() {
    fin >> nr_noduri >> nr_muchii >> x;
    for (int i = 0; i < nr_muchii; i++){
        int m, n;
        fin >> m >> n;
        a[m][n] = 1;
        a[n][m] = 1;
    }
    DFS(x);
}
