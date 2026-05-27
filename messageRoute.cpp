#include <bits/stdc++.h>
using namespace std;

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

    set<int> visited;
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(1);

    visited.insert(1);

    bool found = false;

    while(!q.empty()) {
        int curr = q.front(); q.pop();

        if (curr == n)
        {
            found = true;
            break;
        }

        for(auto v : adjList[curr]) {
            if (visited.find(v) == visited.end()) {
                visited.insert(v);
                q.push(v);
                parent[v] = curr;
            }
        }
    }

    if (!found) {
        cout << "IMPOSSIBLE\n";
        return 0;
    }

    vector<int> path;

    int curr = n;

    while(curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());

    cout << path.size() << endl;

    for(auto i : path) {
        cout << i << " ";
    }

    cout << endl;
}