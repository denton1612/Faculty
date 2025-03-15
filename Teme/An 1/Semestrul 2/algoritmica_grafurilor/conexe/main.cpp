#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");
ofstream fout("out.txt");

void DFS(int nod, bool* v, int** m, int n){
    v[nod-1] = true;
    for (int j = 0; j < n; j++){
        if (m[nod-1][j] == 1 && v[j] == 0) {
            DFS(j+1, v, m, n);
        }
    }
}

int main(){
    int n, m;
    int grupuri = 0;
    fin >> n >> m;
    int** a = new int*[n];
    for (int i = 0; i < n; i++){
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
            a[i][j] = 0;
    }
    bool* v = new bool[n];
    for (int i = 0; i < n; i++)
        v[i] = false;
    int n1, n2;
    for (int i = 0; i < m; i++){
        fin >> n1 >> n2;
        a[n1-1][n2-1] = 1; a[n2-1][n1-1] = 1;
    }
    int gata = 0;
    int nod = 1;
    while (gata == 0){
        grupuri++;
        DFS(nod, v, a, n);
        gata = 1;
        for (int i = 0; i < n; i++)
            if (!v[i]){
                gata = 0;
                nod = i+1;
                break;
            }
    }
    delete[] v;
    for (int i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
    fout << grupuri;
}