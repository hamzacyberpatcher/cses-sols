#include <bits/stdc++.h>
using namespace std;

set<int> visited;

void dfs(vector<vector<int>>& adjList, int vertex) {
    visited.insert(vertex);
    for(auto v : adjList[vertex]) {
        if (visited.find(v) == visited.end()) {
            dfs(adjList, v);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adjList(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> vertices;

    for(int i = 1; i <= n; i++) {
        if (visited.find(i) == visited.end()) {
            vertices.push_back(i);
            dfs(adjList, i);
        }
    }

    cout << vertices.size() - 1 << endl;

    for(int i = 0; i < vertices.size() - 1; i++) {
        cout << vertices[i] << " " << vertices[i + 1] << endl;
    }

    return 0;


}