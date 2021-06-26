#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, min_idx = 0, max_idx = 0;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        if (i) {
            if (a[i] > a[max_idx]) max_idx = i;
            if (a[i] < a[min_idx]) min_idx = i;
        }
    }
    int idx1 = min(min_idx, max_idx), idx2 = max(min_idx, max_idx);
    cout << min({idx1 + 1 + n - idx2, idx2 + 1, n - idx1}) << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}
