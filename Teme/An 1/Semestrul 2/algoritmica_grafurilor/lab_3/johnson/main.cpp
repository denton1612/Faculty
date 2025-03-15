#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;
constexpr int inf = 1000;
typedef struct{
    int n1;
    int n2;
    int w;
}edge;

void scriere_fisier(int** m, int dim, ofstream& fout){
    for (int i = 0; i < dim; i++){
        for (int j = 0; j < dim; j++) {
            if (m[i][j] == inf)
                fout << "inf" << " ";
            else
                fout << m[i][j] << " ";
        }
        fout << endl;
    }
}

bool BellmanFord(vector<edge>& edges, int* d, int& n, int& m) {
    for (int i = 0; i < n; i++) {
        edges.push_back(edge{n, i, 0});
    }
    for (int i = 0; i < n; i++)
        d[i] = inf;
    d[n] = 0;
    for (int i = 0; i <= n; i++) {
        for (edge& e: edges) {
            if (d[e.n2] > d[e.n1] + e.w)
                d[e.n2] = d[e.n1] + e.w;
        }
    }
    for (edge& e: edges) {
        if (d[e.n2] > d[e.n1] + e.w)
            return false;
    }
    return true;
}

void Dijkstra(vector<edge>& edges, int n, int s, int** dist){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));
    int d[n];
    for (int i = 0; i < n; i++)
        d[i] = inf;
    d[s] = 0;
    while (!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for (edge e : edges){
            if (e.n1 == u) // n2 este vecin de al lui u
                if (d[e.n2] > d[e.n1] + e.w){
                    d[e.n2] = d[e.n1] + e.w;
                    pq.push(make_pair(d[e.n2], e.n2));
                }
        }
    }
    for (int j = 0; j < n; j++){
        dist[s][j] = d[j];
    }
}

int main(int argc, char ** argv) {
    if (argc != 3){
        cout << "Eroare!";
        return 0;
    }
    ifstream fin(argv[1]);
    ofstream f;
    f.open(argv[2]);
    int n, m, n1, n2, w;
    fin >> n >> m;
    int*d = new int[n];
    vector<edge> edges;
    for (int i = 0; i < m; i++){
        fin >> n1 >> n2 >> w;
        edges.push_back(edge{n1, n2, w});
    }
    bool bellman = BellmanFord(edges, d, n, m);
    if (!bellman) {
        delete[] d;
        cout << "Exista cicluri negative!";
        return 0;
    }
    int h[n];
    for (int i = 0; i < n; i++)
        h[i] = d[i];
    for (edge& e : edges){
        int new_weight = e.w + h[e.n1] - h[e.n2];
        e = edge {e.n1, e.n2, new_weight};
    }
    for (int i = 0; i < m; i++)
        f << edges[i].n1 << " " << edges[i].n2 << " " << edges[i].w << endl;
    for (int i = 0; i < n; i++)
        edges.pop_back();
    assert(edges.size() == m);
    int** dist = new int*[n];
    for (int i = 0; i < n; i++)
        dist[i] = new int[n];
    for (int i = 0; i < n; i++)
        Dijkstra(edges, n, i, dist);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            if (dist[i][j] != inf){
                dist[i][j] = dist[i][j] - h[i] + h[j];
            }
        }
    scriere_fisier(dist, n, f);
    for (int i = 0; i < n; i++)
        delete[] dist[i];
    delete[] dist;
    delete[] d;
    return 0;
}
