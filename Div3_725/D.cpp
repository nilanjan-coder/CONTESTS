#include <bits/stdc++.h>
using namespace std;
int cnt (int x) {
    int ans = 0;
    for (int i = 2; i * i <= x; i ++) {
        while (x % i == 0) {
            x /= i;
            ans ++;
        }
    }
    if (x > 1) {
        x = 1;
        ans ++;
    }
    return ans;
}
void solve() {
    int a, b, k;
    //cin >> a >> b >> k;
    scanf ("%d%d%d", &a, &b, &k);
    if (a > b) swap(a, b);
    int c = cnt(a) + cnt(b);
    if (k == 1) {
        if (b % a == 0) {
            if (b > a) {
                printf ("YES\n");
                //cout << "YES" << endl;
            }
            else {
                printf ("NO\n");
                //cout << "NO" << endl;
            }
        }
        else {
            printf ("NO\n");
            //cout << "NO" << endl;
        }
    }
    else {
        if (c >= k) {
            printf ("YES\n");
            //cout << "YES" << endl;
        }
        else {
            printf ("NO\n");
            //cout << "NO" << endl;
        }
    }
}
int main() {
    int t;
    //cin >> t;
    scanf ("%d", &t);
    while (t --) {
        solve();
    }
}
