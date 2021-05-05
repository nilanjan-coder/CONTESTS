#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	scanf ("%d", &n);
	int x[n], y[2 * n + 2];
	for (int i = 0; i <= 2 * n + 1; i ++) y[i] = 0;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &x[i]);
		y[x[i]] ++;
	}
	for (int i = 1; i <= 2 * n; i ++) {
		if (y[i] > 1) {
			y[i] --;
			y[i+1] ++;
		}
	}
	int ans = 0;
	for (int i = 1; i <= 2 * n + 1; i ++) {
		if (y[i] >= 1) ans ++;
	}
	printf ("%d\n", ans);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T = 1;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t ++) {
		// printf ("Case #%d: ", t);
		test_case();
	}
}






