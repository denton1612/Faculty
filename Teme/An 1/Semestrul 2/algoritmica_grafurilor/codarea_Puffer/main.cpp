#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::priority_queue;
using std::count;

int main(int argc, char** argv) {
    if (argc != 3){
        cout << "Eroare!";
        return 1;
    }
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    int n;
    int x;
    in >> n;
    vector<int> parinti;
    priority_queue<int, vector<int>, std::greater<>> frunze;
    for (int i = 0; i < n; i++) {
        in >> x;
        parinti.push_back(x);
    }
    for (int i = 0; i < n; i++){
        if (count(parinti.begin(), parinti.end(), i) == 0)
            frunze.push(i);
    }
    vector<int> codificare;
    while (count(parinti.begin(), parinti.end(), -1) != parinti.size()){
        int frunza = frunze.top();
        frunze.pop();
        int parinte = parinti[frunza];
        codificare.push_back(parinte);
        parinti[frunza] = -1;
        if (count(parinti.begin(), parinti.end(), parinte) == 0)
            frunze.push(parinte);
    }
    out << codificare.size() << '\n';
    for (auto nod : codificare)
        out << nod << " ";
    return 0;
}
