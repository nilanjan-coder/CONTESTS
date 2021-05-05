#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n, even = 0, odd = 0, ans = 0;
	scanf ("%d", &n);
	int p[n];
	vector <int> on;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &p[i]);
		if (p[i]) {
			if (p[i] & 1) odd ++;
			else even ++;
			on.push_back(i);
		}
	}
	if (on.empty()) {
		if (n == 1) printf ("0");
		else printf ("1");
		return;
	}
	if (n & 1) {
		even = (n-1)/2 - even;
		odd = (n+1)/2 - odd;
	}
	else {
		even = n/2 - even;
		odd = n/2 - odd;
	}
	int m = on.size();
	vector <bool> mark(m, false);
	for (int i = 1; i < m; i ++) {
		if ((p[on[i]] % 2 == 0 && p[on[i-1]] % 2 == 0) || (p[on[i]] % 2 != 0 && p[on[i-1]] % 2 != 0)) {
			if (p[on[i]] % 2 == 0) {
				mark[i] = true;
				even -= (on[i] - on[i-1] - 1);
				if (even < 0) {
					ans += 2;
				}
			}
			else {
				mark[i] = true;
				odd -= (on[i] - on[i-1] - 1);
				if (odd < 0) {
					ans += 2;
				}
			}
		}
	}
	if (p[on[0]] & 1) {
		mark[0] = true;
		odd -= on[0];
		if (odd < 0) {
			ans += 1;
		}
	}
	else {
		mark[0] = true;
		even -= on[0];
		if (even < 0) {
			ans += 1;
		}
	}
	if (m > 1) {
		if (p[on[m-1]] & 1) {
			odd -= (n - 1 - on[m-1]);
			if (odd < 0) {
				ans += 1;
			}
		}
		else {
			even -= (n - 1 - on[m-1]);
			if (even < 0) {
				ans += 1;
			}
		}
	}
	for (int i = 0; i < m; i ++) {
		if (! mark[i]) {
			ans += 1;
		}
	}
	printf ("%d", ans);
}
int main() {
	int T = 1;
	//scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}