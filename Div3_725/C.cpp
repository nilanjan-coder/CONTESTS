#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector <int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll ans = 0;
    for (int i = 0; i < n; i ++) {
        ll tmp = upper_bound(a.begin(), a.end(), r - a[i]) - lower_bound(a.begin(), a.end(), l - a[i]);
        if (l <= 2 * a[i] && 2 * a[i] <= r) tmp --;
        ans += tmp;
    }
    cout << ans / 2 << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}
