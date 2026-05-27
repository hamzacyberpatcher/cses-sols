#include  <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ll n; cin >> n;
    vector<ll> a(n + 1, 0);
    a[0] = 1;

    for(ll i  = 1; i <= n; i++) {
        for(ll j = 1; j <= 6; j++) {
            if (i - j < 0) continue;
            a[i] = (a[i] + a[i - j]) % (ll) (1e9 + 7);
        }
    }

    cout << a[n] << endl;

    return 0;
}