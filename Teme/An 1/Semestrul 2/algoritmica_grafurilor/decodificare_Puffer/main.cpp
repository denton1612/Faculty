#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <queue>
using std::cin;
using std::cout;
using std::ifstream;
using std::ofstream;
using std::vector;
using std::priority_queue;
using std::count;
using std::find;

int main(int argc, char** argv) {
    ifstream in("in.txt");
    ofstream out("out.txt");
    int parinti[100] = {};
    vector<int> codificare;
    priority_queue<int, vector<int>, std::greater<>> frunze;
    int n;
    in >> n;
    out << n+1 << '\n';
    int nod;
    for (int i = 0; i < n; i++) {
        in >> nod;
        codificare.push_back(nod);
    }
    for (int i = 0; i < n+1; i++) {
        if (find(codificare.begin(), codificare.end(), i) == codificare.end()) {
            frunze.push(i);
        }
    }
    int p, fr;
    for (int i = 1; i < n; i++) {
        p = *codificare.begin();
        codificare.erase(codificare.begin());
        fr = frunze.top();
        frunze.pop();
        parinti[fr] = p;
        if (find(codificare.begin(), codificare.end(), p) == codificare.end())
            frunze.push(p);
    }
    parinti[codificare[0]] = -1;
    for (int i = 0; i < n+1; i++) {
        out << parinti[i] << " ";
    }
}
