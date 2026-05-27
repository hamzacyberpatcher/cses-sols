#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    int n; cin >> n;
    vector<string> m(n);

    for(int i = 0; i < n; i++) cin >> m[i];

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    if (m[0][0] != '*')
        dp[0][0] = 1;

    ll mod = 1e9 + 7;

    for(ll i = 0; i < n; i++) {
        for(ll j = 0; j < n; j++) {

            if (i == 0 && j == 0) continue;

            ll a = 0, b = 0;

            if (i - 1 >= 0) a = dp[i - 1][j];
            if (j - 1 >= 0) b = dp[i][j - 1];

            if (m[i][j] == '*') continue;

            dp[i][j] = (a + b) % mod;
        }
    }

    cout << dp[n - 1][n - 1] << endl;

    

    return 0;
}