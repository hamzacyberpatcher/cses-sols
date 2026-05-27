#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> c(n);

    ll Mod = 1e9 + 7;

    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for(ll c1 : c) {
        for(ll i = c1; i <= x; i++) {
            dp[i] = (dp[i] + dp[i - c1]) % Mod;
        }
    }

    

    cout << dp[x] << endl;
    

    return 0;
}