#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n;
    cin >> n;
    vector <int> a(n + 1), idx(2 * n + 1, 0);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        idx[a[i]] = i;
    }
    int ans = 0;
    for (int i = 3; i <= 2 * n - 1; i ++) {
        for (int j = 1; j * j < i; j ++) {
            if (i % j == 0) {
                if (idx[j] && idx[i / j] && i == idx[j] + idx[i / j]) {
                    ans ++;
                }
            }
        }
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
