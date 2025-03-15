#include <iostream>
#include <fstream>
using namespace std;

bool m_a [100][100] = {}, m_i[100][100] = {};
int l_i[100][100] = {};
int m_d[100][100] = {};
void matrice_adiacenta()
{
    ifstream fin("a.txt");
    int nr_noduri = 0, nr_muchii = 0;
    fin >> nr_noduri;
    fin >> nr_muchii;
    int nod_1, nod_2;
    for (int i = 0; i < nr_muchii; i++)
    {
        fin >> nod_1 >> nod_2;
        m_a[nod_1-1][nod_2-1] = 1;
        m_a[nod_2-1][nod_1-1] = 1;
    }
    fin.close();
}

int min(int a, int b)
{
    if (a < b)
        return a;
    return b;
}

void lista_incidenta()
{
    ifstream fin("a.txt");
    int nr_noduri = 0, nr_muchii = 0;
    fin >> nr_noduri;
    fin >> nr_muchii;
    int nod_1, nod_2;
    int poz[10];
    for (int i = 0; i < nr_noduri; i++)
        poz[i] = 1;
    for (int i = 0; i < nr_muchii; i++)
    {
        fin >> nod_1 >> nod_2;
        l_i[nod_1-1][0]++;
        l_i[nod_2-1][0]++;
        l_i[nod_1-1][poz[nod_1-1]] = nod_2;
        l_i[nod_2-1][poz[nod_2-1]] = nod_1;
        poz[nod_1-1]++;
        poz[nod_2-1]++;
    }
    fin.close();
}

void matrice_incidenta()
{
    ifstream fin("a.txt");
    int nr_noduri = 0, nr_muchii = 0;
    fin >> nr_noduri;
    fin >> nr_muchii;
    int nod_1, nod_2;
    for (int i = 0; i < nr_muchii; i++)
    {
        fin >> nod_1 >> nod_2;
        m_i[nod_1-1][i] = 1;
        m_i[nod_2-1][i] = 1;
    }
    fin.close();
}

int* grad()
{
    int g[100] = {};
    ifstream fin("a.txt");
    int nr_noduri = 0;
    fin >> nr_noduri;
    fin.close();
    for (int i = 0; i < nr_noduri; i++)
        for (int j = 0; j < nr_noduri; j++)
            g[i] += m_a[i][j];
    return g;
}

int* izolate()
{
    ifstream fin("a.txt");
    int nr_noduri, j = 0;
    fin >> nr_noduri;
    fin.close();
    int n[100] = {};
    int* p = grad();
    for (int i = 0; i < nr_noduri; i++)
        if (p[i] == 0)
        {
            n[j] = i+1;
            j++;
        }
    return n;
}

int main() {
    ifstream fin("a.txt");
    int nr_noduri, nr_muchii, *ptr;
    fin >> nr_noduri >> nr_muchii;
    fin.close();
    cout << "Matricea de adiacenta:" << endl;
    matrice_adiacenta();
    for (int i = 0; i < nr_noduri; i++)
    {
        for (int j = 0; j < nr_noduri; j++)
            cout << m_a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    cout << "Lista de adiacenta: " << endl;
    lista_incidenta();
    for (int i = 0; i < nr_noduri; i++)
    {
        for (int j = 0; j < nr_muchii; j++)
            if (l_i[i][j] != 0 || j == 0)
                cout << l_i[i][j] << " ";
        cout << endl;
    }
    cout << endl;


    cout << "Matrice de incidenta:" << endl;
    matrice_incidenta();
    for (int i = 0; i < nr_noduri; i++)
    {
        for (int j = 0; j < nr_muchii; j++)
            cout << m_i[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    ptr = izolate();
    if (ptr[0] == 0)
        cout << "Nu exista noduri izolate!" << endl;
    else
    cout << "Nodurile izolate: " << endl;
    {
        for (int i = 0; i < nr_noduri; i++)
            if (ptr[i] != 0)
                cout << ptr[i] << " ";
    }
    cout << endl;

    bool regulat = true;
    int* g;
    g = grad();
    for (int i = 0; i < nr_noduri-1; i++)
        if (g[i] != g[i+1])
            regulat = false;
    if (regulat)
        cout << "Graful este regulat!";
    else
        cout << "Graful nu este regulat!";
    cout << endl;
    cout << endl;

    for (int i = 0; i < nr_noduri; i++)
    {
        for (int j = 0; j < nr_noduri; j++)
            if (i == j)
                m_d[i][j] = 0;
            else if (m_a[i][j] == 0)
                m_d[i][j] = 1000;
            else
                m_d[i][j] = 1;
    }

    for (int k = 0; k < nr_noduri; k++)
        for (int i = 0; i < nr_noduri; i++)
            for (int j = 0; j < nr_noduri; j++)
                m_d[i][j] = min(m_d[i][k] + m_d[k][j], m_d[i][j]);

    cout << "Matricea drumurilor este: " << endl;
    for (int i = 0; i < nr_noduri; i++)
    {
        for (int j = 0; j < nr_noduri; j++)
            if (m_d[i][j] == 1000)
                cout << "inf" << " ";
            else
                cout << m_d[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    bool conex = true;
    for (int i = 0; i < nr_noduri; i++)
    {
        int s = 0;
        for (int j = 0; j < nr_noduri; j++)
            s += m_a[i][j];
        if (s == 0)
            conex = false;
    }

    if (conex)
        cout << "Graful este conex!";
    else
        cout << "Graful nu este conex!";
}
