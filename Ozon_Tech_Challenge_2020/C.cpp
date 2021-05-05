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
		int a[n], b[n], cnt[m];
		for (int i = 0; i < m; i ++) {
			cnt[i] = 0;
		}
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &a[i]);
			b[i] = a[i] % m;
			cnt[b[i]] ++;
		}
		for (int i = 0; i < m; i ++) {
			if (cnt[i] > 1) {
				printf ("0");
				return 0;
			}
		}
		long long ans = 1;
		for (int i = 0; i < n; i ++) {
			for (int j = i+1; j < n; j ++) {
				ans = (ans * (abs(a[j] - a[i]) % m)) % m;
			}
		}
		printf ("%lld", ans);
	}
}



