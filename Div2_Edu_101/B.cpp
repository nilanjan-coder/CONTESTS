#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	scanf ("%d", &n);
	int r[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &r[i]);
		if (i == 0) continue;
		r[i] += r[i - 1];
	}
	int m;
	scanf ("%d", &m);
	int b[m];
	for (int i = 0; i < m; i ++) {
		scanf ("%d", &b[i]);
		if (i == 0) continue;
		b[i] += b[i - 1];
	}
	int ans = 0;
	for (int i = 0; i < n+m; i ++) {
		for (int x = -1; x <= min (n - 1, i); x ++) {
			if (i - x <= m) {
				ans = max (ans, ((x >= 0) ? r[x] : 0) + ((i - x > 0) ? b[i - x - 1] : 0));
			}
		}
	}
	printf ("%d\n", ans);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	// test_case();
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}






