#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 1;
int main () {
    int n, q;
    long long k;
    scanf ("%d%d%lld", &n, &q, &k);
    vector <long long> a(n + 2);
    a[0] = 0;
    a[n + 1] = INF;
    for (int i = 1; i <= n; i ++) {
        scanf ("%lld", &a[i]);
    }
    vector <long long> left(n + 2), right(n + 2), sum(n + 2);
    sum[0] = 0;
    for (int i = 1; i <= n; i ++) {
        left[i] = a[i] - a[i - 1];
    }
    for (int i = 1; i <= n; i ++) {
        right[i] = a[i + 1] - a[i];
    }
    for (int i = 1; i <= n; i ++) {
        sum[i] = sum[i - 1] + left[i] + right[i];
    }
    while (q --) {
        int l, r;
        scanf ("%d%d", &l, &r);
        printf ("%lld\n", sum[r] - sum[l - 1] - left[l] - right[r] + a[l] + k - a[r] + 1 - 2 * (r - l + 1));
    }
}