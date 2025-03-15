#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using std::vector;
using std::string;
using std::ifstream;
using std::iostream;

void dfs(int i, int j, vector<vector<int>> & matrix, vector<vector<int>> & visited) {

}

void removeIslands(vector<vector<int>> & matrix, vector<vector<int>> & visited) {
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[0].size(); j++) {
            if (matrix[i][j] == 1 and visited[i][j] == 0)
                dfs(i, j, matrix, visited);
        }
}

int main() {
    ifstream in("/Users/stiubedenis/Desktop/Facultate/Teme/Semestrul 2/OOP/googleInterview/cmake-build-debug/matrix.txt");
    vector<vector<int>> matrix;
    vector<vector<int>> visited;
//    for (int i = 0; i < matrix.size(); i++) {
//        for (int j = 0; j < matrix[0].size(); j++)
//            matrix[i].push_back(0);
//    }
    string line;
    int i = 0;
    while (getline(in, line)) {
        for (auto & c : line) {
            if (c != ' ')
                matrix[i].push_back(c-'0');
        }
        i++;
    }
    for (auto & v : matrix) {
        for (auto nr : v)
            std::cout << nr << " ";
        std::cout << '\n';
    }
    return 0;
}
