#include <bits/stdc++.h>
using namespace std;

void bfs(vector<string>& g, const pair<int,int> start) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    q.push(start);

    int n = g.size();
    int m = g[0].size();

    g[start.first][start.second] = '*';

    while(!q.empty()) {
        pair<int, int> curr = q.front(); q.pop();


        for(pair<int, int> dir : directions) {
            int first = curr.first + dir.first;
            int second = curr.second + dir.second;

            if (first < 0 || first >= n) continue;
            if (second < 0 || second >= m) continue;

            if (g[first][second] != '.')  continue;

            g[first][second] = '*';

            q.push({first, second});
        }

    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);

    for(int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int cnt = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (g[i][j] == '.') {
                cnt++;
                bfs(g, {i, j});
            }
        }
    }

    cout << cnt << endl;



    
}