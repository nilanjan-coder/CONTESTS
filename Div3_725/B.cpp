#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
    int n, sum = 0;
    cin >> n;
    vector <int> a(n), ps(n);
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    ps[0] = a[0];
    for (int i = 1; i < n; i ++) {
        ps[i] = ps[i - 1] + a[i];
    }
    int k = n + 1;
    if (n * a[n - 1] == ps[n - 1]) {
        k = n;
    }
    if (k == n + 1) {
    for (int i = n - 1; i >= 1; i --) {
        int reqd = i * a[i - 1] - ps[i - 1], have = ps[n - 1] - ps[i - 1] - (n - i) * a[i - 1];
        if (have >= reqd && (have - reqd) % n == 0) {
            k = i;
            break;
        }
    }}
    if (k == n + 1) {
        if (ps[n - 1] % n == 0) {
            k = 0;
        }
    }
    cout << n - k << endl;
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}
