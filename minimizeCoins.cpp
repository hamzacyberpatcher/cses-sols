#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> c(n);

    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());

    vector<ll> dp(x + 1, -1);
    dp[0] = 0;

    for(int i = 1; i <= x; i++) {
        ll minim = INT_MAX;
        for(int j = 0; j < n; j++) {
            if (i - c[j] < 0 || dp[i - c[j]] == -1) continue;
            minim = min(minim , dp[i - c[j]]);
        }
        if (minim == INT_MAX) continue;
        dp[i] = minim + 1;
    }

    cout << dp[x] << endl;

    

    return 0;
}