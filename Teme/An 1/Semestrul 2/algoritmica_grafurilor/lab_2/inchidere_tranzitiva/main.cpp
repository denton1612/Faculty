#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("input.txt");
int main() {
    int m[100][100] = {}, tr[100][100] = {};
    int n, x, y;
    fin >> n;
    while (fin >> x >> y){
        m[x][y] = 1;
        tr[x][y] = 1;
    }
    for (int i = 0; i < n; i++){
        m[i][i] = 1;
        tr[i][i] = 1;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (m[i][j] == 0)
                    tr[i][j] = tr[i][k]*tr[k][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << tr[i][j] << " ";
        cout << endl;
    }
}
