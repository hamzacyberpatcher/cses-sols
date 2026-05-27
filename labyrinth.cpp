#include <bits/stdc++.h>
using namespace std;

void bfs(vector<string>& g, pair<int, int> st, pair<int, int> ed) {
    int n = g.size();
    int m = g[0].size();

    vector<vector<bool>> visited(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m));

    queue<pair<int, int>> q;
    q.push(st);

    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool found = false;

    visited[st.first][st.second] = true;
    parent[st.first][st.second] = {-1, -1};

    while(!q.empty()) {
        auto curr = q.front();
        q.pop();

        if (curr == ed) {
            found = true;
            break;
        }

        for(auto dir : directions) {
            int first = dir.first + curr.first;
            int second = dir.second + curr.second;

            if (first < 0 || first >= n || second < 0 || second >= m) continue;

            if (g[first][second] == '#') continue;

            if (!visited[first][second]) {
                visited[first][second] = true;
                parent[first][second] = curr;
                q.push({first, second});
            }
        }


    }

    if (!found) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";

    vector<pair<int, int>> path;

    pair<int, int> curr = ed;

    while(curr.first != -1 && curr.second != -1) {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }

    cout << path.size() - 1 << endl;

    reverse(path.begin(), path.end());

    for(int i = 1; i < path.size(); i++) {
        int first = path[i].first - path[i - 1].first;
        int second = path[i].second - path[i - 1].second;

        pair<int, int> dir = {first, second};

        if (dir == directions[0]) cout << "R";
        else if (dir == directions[1]) cout << "L";
        else if (dir == directions[2]) cout << "D";
        else cout << "U";
    }

    cout << endl;



}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);

    for(int i = 0; i < n; i++) cin >> g[i];

    pair<int, int> st, ed;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (g[i][j] == 'A') st = {i, j};
            else if (g[i][j] == 'B') ed = {i, j};
        }
    }

    bfs(g, st, ed);

    return 0;
}