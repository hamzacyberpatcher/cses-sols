#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n, x; cin >> n >> x;
    vector<ll> c(n), p(n);
    for(ll i = 0; i < n; i++) cin >> c[i];
    for(ll i = 0; i < n; i++) cin >> p[i];

    vector<ll> dp(x+1);

    for(ll i = 0; i < n; i++) {
        ll pages = p[i];
        ll price = c[i];

        for(ll j = x; j >= price; j--) {
            dp[j] = max(dp[j], pages + dp[j-price]);
        }
    }

    cout << dp[x] << endl;

    return 0;
}