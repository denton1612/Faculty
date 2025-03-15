#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;

ifstream fin("labirint_1.txt");
ofstream fout("solutie.txt");

int main() {
    char a[1000][1000];
    int nr;
    fin >> nr;
    for (int i = 0; i < nr; i++){
        fin.getline(a[i], 100);
    }
    int i = 0;
    for (int j = 0; j < nr; j++){
        while (a[i][j] != '\0'){
            cout << a[i][j];
        }
        i++;
    }
}
