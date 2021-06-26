#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    if (n & 1) {
        for (int i = 1; i <= n - 4; i += 2) {
            cout << (i + 1) << " " << i << " ";
        }
        cout << n << " " << (n - 2) << " " << (n - 1) << endl;
    }
    else {
        for (int i = 1; i <= n - 1; i += 2) {
            cout << (i + 1) << " " << i << " ";
        }
        cout << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while (t --) {
        solve();
    }
}
