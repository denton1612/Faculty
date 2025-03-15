#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
using namespace std;

// implementare pentru a mentine toate nodurile in submultimi disjuncte ale multimii nodurilor
// am folosit un dictionar unde cheia este nodul si valoarea este un nr asociat submultimii
// din care face parte nodul

class DisjointSet{
    int v;
    map<int, int> set;
public:
    DisjointSet(int n): v{n}{
        make_set(v);
    }
    void make_set(int n){
        for (int i = 0; i < n; i++)
            set[i] = i;
    }
    int find_set(int nod){
        return set[nod];
    }
    void union_set(int nod1, int nod2){
        if (find_set(nod1) != find_set(nod2)){
            int part = set[nod1];
            int vechi_part = set[nod2];
            for (auto el : set){
                if (el.second == vechi_part)
                    set[el.first] = part;
            }
        }
    }
};

int main(int argc, char** argv) {
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n, m, x, y, w;
    vector<pair<pair<int, int>, int>> edges;
    set<pair<pair<int, int>, int>> arbore;
    in >> n >> m;
    DisjointSet S(n);
    for (int i = 0; i < m; i++){
        in >> x >> y >> w;
        edges.push_back(make_pair(make_pair(x, y), w));
    }
    sort(edges.begin(), edges.end(), [](auto edge1, auto edge2){
        return edge1.second < edge2.second;
    });
    for (auto edge : edges){
        int nod1 = edge.first.first;
        int nod2 = edge.first.second;
        if (S.find_set(nod1) != S.find_set(nod2)){
            S.union_set(nod1, nod2);
            arbore.insert(edge);
        }
    }
    int sum = 0;
    for (auto edge : arbore){
        sum += edge.second;
    }
    out << sum << endl;
    out << arbore.size() << endl;
    for (auto edge : arbore){
        out << edge.first.first << " " << edge.first.second << endl;
    }
    return 0;
}
