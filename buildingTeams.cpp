#include <bits/stdc++.h>
using namespace std;

int MAXI = 1e5;
vector<int> assigned(MAXI, 0);
vector<vector<int>> adjList(MAXI);

bool possible = true;

void dfs(int u, int current_team) {
    assigned[u] = current_team;

    for(auto v : adjList[u]) {
        if (assigned[v] == 0) {
            dfs(v, 3 - current_team);
        } else if (assigned[u] == assigned[v]) {
            possible = false;
            return;
        }

        if (!possible) return;
    }
}

int main() {
    int n, m; cin >> n >> m;
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for(int i = 1; i <= n; i++) {
        if (assigned[i] == 0) {
            dfs(i, 1);
        }

        if (!possible) break;
    }

    if (!possible) {
        cout << "IMPOSSIBLE\n";

        return 0;
    }

    for(int i = 1; i <= n; i++) {
        cout << assigned[i] << " ";
    }

    cout << endl;




}