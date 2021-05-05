#include <bits/stdc++.h>
using namespace std;
string read (int n) {
	char s[n + 1];
	scanf ("%s", s);
	return string(s);
}
void test_case() {
	int n, m;
	scanf ("%d%d", &n, &m);
	string s = read(n);
	int x[n];
	for (int i = 0; i < n; i ++) {
		if (s[i] == '+') {
			x[i] = ((i > 0) ? x[i - 1] : 0) + 1;
		}
		else {
			x[i] = ((i > 0) ? x[i - 1] : 0) - 1;
		}
	}
	int fnax[n], fnin[n], bnax[n], bnin[n];
	for (int i = 0; i < n; i ++) {
		fnax[i] = (i > 0) ? max (fnax[i - 1], x[i]) : x[i];
		fnin[i] = (i > 0) ? min (fnin[i - 1], x[i]) : x[i];
	}
	for (int i = n - 1; i >= 0; i --) {
		bnax[i] = (i < n - 1) ? max (bnax[i + 1], x[i]) : x[i];
		bnin[i] = (i < n - 1) ? min (bnin[i + 1], x[i]) : x[i];
	}
	while (m --) {
		int l, r;
		scanf ("%d%d", &l, &r);
		l --;
		r --;
		if (l == 0 && r == n - 1) {
			printf ("1\n");
		}
		else if (l == 0) {
			int a = max (bnax[r + 1], x[r]), b = min (bnin[r + 1], x[r]);
			a -= x[r];
			b -= x[r];
			printf ("%d\n", a - b + 1);
		}
		else if (r == n - 1) {
			int a = max (fnax[l - 1], 0), b = min (fnin[l - 1], 0);
			printf ("%d\n", a - b + 1);
		}
		else {
			int a = max (fnax[l - 1], 0), b = min (fnin[l - 1], 0), c = max (x[r], bnax[r + 1]), d = min (x[r], bnin[r + 1]);
			c = c - x[r] + x[l - 1];
			d = d - x[r] + x[l - 1];
			printf ("%d\n", max (a, c) - min (b, d) + 1);
		}
	}
}
int main() {
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		test_case();
	}
}