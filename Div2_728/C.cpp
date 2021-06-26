#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    ll n;
    cin >> n;
    vector <ll> d(n);
    for (ll i = 0; i < n; i ++) {
        cin >> d[i];
    }
    sort(d.begin(), d.end());
    ll ans = d.back();
    for (ll i = n - 1; i >= 1; i --) {
        d[i] -= d[i - 1];
    }
    for (ll i = 1; i < n; i ++) {
        d[i] *= i;
    }
    for (ll i = 1; i < n; i ++) {
        d[i] += d[i - 1];
    }
    for (ll i = 1; i < n; i ++) {
        ans -= d[i];
    }
    cout << ans << endl;
}
int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}
