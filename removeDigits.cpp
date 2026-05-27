#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;

    vector<ll> dp(n + 1, INT_MAX);

    dp[0] = 0;

    for(ll i = 1; i <= n; i++) {
        ll x = i;
        while (x > 0) {
            int d = x % 10; x/= 10;
            dp[i] = min(dp[i], dp[i - d] + 1);
        }
    }

    cout << dp[n] << endl;
    

    return 0;
}