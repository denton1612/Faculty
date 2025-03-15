#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <map>
using namespace std;

bool exista_drum(int** m, int parinti[], int n) {
    int vizitat[100] = {};
    queue<int> coada;
    coada.push(0);
    vizitat[0] = 1;
    parinti[0] = -1;
    int x;
    while (!coada.empty()) {
        x = coada.front();
        coada.pop();
        for (int i = 0; i < n; i++) {
            if (m[x][i] > 0 and vizitat[i] == 0){
                vizitat[i] = 1;
                parinti[i] = x;
                if (i == n-1)
                    return true;
                coada.push(i);
            }
        }
    }
    return false;
}

int main() {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int n, m;
    in >> n >> m;
    int parinti[n];
    int flux_maxim = 0;
    int** a = new int*[n];
    int** b = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        b[i] = new int[n];
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            a[i][j] = 0; b[i][j] = 0;
        }

    int n1, n2, w;
    for (int i = 0; i < m; i++) {
        in >> n1 >> n2 >> w;
        a[n1][n2] = w;
        b[n1][n2] = w;
    }
    int flux;
    while (exista_drum(b, parinti, n)) {
        flux = 10000;
        for (int i = n-1; i > 0; i = parinti[i]) {
            int p = parinti[i];
            if (b[p][i] < flux)
                flux = b[p][i];
        }
        for (int i = n-1; i > 0; i = parinti[i]) {
            int p = parinti[i];
            b[p][i] -= flux;
            b[i][p] += flux;
        }
        flux_maxim += flux;
    }

    out << flux_maxim;

    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;
    return 0;
}
