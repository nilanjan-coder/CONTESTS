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
	scanf ("%d", &tc);
	while (tc --) {
		int n;
		scanf ("%d", &n);
		int a[n], b[n];
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &a[i]);
		}
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &b[i]);
		}
		sort (a, a+n);
		sort (b, b+n);
		for (int i = 0; i < n; i ++) {
			printf ("%d ", a[i]);
		}
		printf ("\n");
		for (int i = 0; i < n; i ++) {
			printf ("%d ", b[i]);
		}
		printf ("\n");
	}
}


