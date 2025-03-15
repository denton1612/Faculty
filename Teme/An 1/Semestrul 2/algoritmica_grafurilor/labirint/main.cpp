#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

ifstream fin("labirint1.txt");
ofstream fout("solutie.txt");

int main(){
    int a[1000][1000] = {}, b[1000][1000] = {}, i = 0, j = 0;
    pair<int, int> start, final;
    char c;
    while (fin >> c){
        if (c == '\n')
            i++;
        else if (c == 'S'){
            start.first = i;
            start.second = j;
            b[i][j++] = 1;
        }
        else if (c == 'F'){
            final.first = i;
            final.second = j;
            j++;
        }
        else if (c == ' '){
            a[i][j] = 0;
            cout << a[i][j];
            j++;
        }
        else{
            a[i][j] = c - '0';
            j++;
        }
    }
    for (int k = 0; k < i; k++){
        for (int l = 0; l <= j; l++)
            cout << a[k][l] << " ";
        cout << endl;
    }
}
