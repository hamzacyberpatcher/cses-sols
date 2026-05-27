#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> c(n);

    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.begin(), c.end());

    vector<ll> dp(x + 1, 0);
    dp[0] = 1;

    for(int i = 1; i <= x; i++) {
        
        for(int j = 0; j < n; j++) {
            if (i - c[j] < 0) continue;
            dp[i] = (dp[i] + dp[i - c[j]]) % (ll) (1e9 + 7);
        }
        
    }

    cout << dp[x] << endl;

    

    return 0;
}