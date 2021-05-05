#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
const long double ERR = 1e-9;
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int tc = 1;
	// scanf ("%d", &tc);
	while (tc --) {
		long double sy, a, b;
		scanf ("%Lf%Lf%Lf", &sy, &a, &b);
		int n;
		scanf ("%d", &n);
		long double l[n], r[n], dp[n];
		for (int i = 0; i < n; i ++) {
			scanf ("%Lf%Lf", &l[i], &r[i]);
			dp[i] = ((i > 0) ? dp[i-1] : 0) + r[i] - l[i];
		}
		int q;
		cin >> q;
		while (q --) {
			long double xi, yi;
			scanf ("%Lf%Lf", &xi, &yi);
			long double xa = (xi * sy - a * yi) / (sy - yi), xb = (xi * sy - b * yi) / (sy - yi), len = 0;
			int i1 = upper_bound (r, r+n, xa) - r - 1, i2 = lower_bound (l, l+n, xb) - l;
			i1 ++;
			i2 --;
			if (i1 < n && l[i1] < xa && r[i1] <= xb) {
				len += (r[i1] - xa);
				i1 ++;
			}
			if (i2 >= 0 && r[i2] > xb && l[i2] >= xa) {
				len += (xb - l[i2]);
				i2 --;
			}
			if (l[i1] < xa && r[i1] > xb) {
				len += (xb - xa);
			}
			else if (i1 <= i2) {
				len += dp[i2] - ((i1 > 0) ? dp[i1 - 1] : 0);
			}
			len = (len * (yi - sy)) / yi;
			printf ("%.7Lf\n", len);
		}
	}
}


