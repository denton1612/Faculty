#include <iostream>
using namespace std;

int main(){
    int n, m, n1, n2;
    cin >> n >> m;
    int m_i[n][m];
    for (int i = 0; i < m; i++){
        cin >> n1 >> n2;
        m_i[n1][m] = 1; m_i[n2][m] = 1; // construirea matricii de incidenta pentru m muchii date
    }
    int l_a[n][n];
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n; j++)
            l_a[i][j] = 0;
    for (int i = 0; i < n; i++)
        l_a[i][0] = i;

    // lista de adiacenta este initializata


}