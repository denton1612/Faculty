#include <iostream>
#include <queue>
#include <fstream>
using namespace std;
ifstream fin("graf.txt");

int main() {
    int n, l_a[50][50] = {}, x, y;
    fin >> n;
    for (int i = 0; i < n; i++)
        l_a[i][0] = i+1;
    while (fin >> x && fin >> y){
        int j = 1;
        while (l_a[x-1][j] != 0)
            j++;
        l_a[x-1][j] = y;
    }

    queue<int> q;
    int d[100], p[100];
    int s;
    cout << "Introduceti un nod sursa: ";
    cin >> s;
    d[s-1] = 0;
    for (int i = 0; i < n; i++)
        p[i] = -1;
    for (int i = 0; i < n; i++)
        if (i != s-1)
            d[i] = 1000;
    q.push(s);
    while (!q.empty()){
        int u = q.front();
        int j = 1;
        while (l_a[u-1][j] != 0){
            int vecin = l_a[u-1][j];
            if (d[vecin-1] == 1000) {
                q.push(vecin);
                d[vecin-1] = d[u-1] + 1;
                p[vecin-1] = u;
            }
            j++;
        }
        q.pop();
    }
    cout << "Vector de distante: ";
    for (int i = 0; i < n; i++)
        cout << d[i] << " ";
    cout << endl;
    cout << "Vector de parinti: ";
    for (int i = 0; i < n; i++)
        cout << p[i] << " ";
}
