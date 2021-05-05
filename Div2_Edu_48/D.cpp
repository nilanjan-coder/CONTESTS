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
		int n, m;
		scanf ("%d%d", &n, &m);
		long long a[n], b[m], xora = 0, xorb = 0;
		for (int i = 0; i < n; i ++) {
			scanf ("%lld", &a[i]);
			xora ^= a[i];
		}
		for (int i = 0; i < m; i ++) {
			scanf ("%lld", &b[i]);
			xorb ^= b[i];
		}
		if (xora - xorb) {
			printf ("NO\n");
		}
		else {
			printf ("YES\n");
			long long val = xora ^ a[0] ^ b[0];
			for (int i = 0; i < n; i ++) {
				for (int j = 0; j < m; j ++) {
					if (i == 0) {
						if (j == 0) {
							printf ("%lld ", val);
						}
						else {
							printf ("%lld ", b[j]);
						}
					}
					else {
						if (j == 0) {
							printf ("%lld ", a[i]);
						}
						else {
							printf ("0 ");
						}
					}
				}
				printf ("\n");
			}
		}
	}
}


