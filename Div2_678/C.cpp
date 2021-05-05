#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int main() {
    int tt = 1; 
    // cin >> tt;
    while (tt --) {
        int n, x, pos, lx = 0, rx = 0;
        cin >> n >> x >> pos;
        int left = 0, right  = n;
        while (left < right) {
            int mid = (left + right) / 2;
            if (mid <= pos) {
                left = mid + 1;
                if (mid < pos) lx ++;
            }
            else if (mid > pos) {
                right = mid;
                rx ++;
            }
        }
        if (lx > x-1 || rx > n-x) {
            cout << 0;
            return 0;
        }
        long long int p = 1;
        for (int i = x-lx; i <= x-1; i ++) {
            p = (p * i) % MOD;
        }
        for (int i = n-x-rx+1; i <= n-x; i ++) {
            p = (p * i) % MOD;
        }
        for (int i = 1; i <= n-1-lx-rx; i ++) {
            p = (p * i) % MOD;
        }
        cout << p;
    }
}
