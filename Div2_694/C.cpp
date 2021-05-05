#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long n, m, s = 0;
	scanf ("%lld%lld", &n, &m);
	long long k[n + 1], c[m + 1];
	for (long long i = 1; i <= n; i ++) {
		scanf ("%lld", &k[i]);
	}
	for (long long i = 1; i <= m; i ++) {
		scanf ("%lld", &c[i]);
	}
	sort (k+1, k+n+1);
	long long idx = 1;
	for (long long i = n; i >= 1; i --) {
		if (idx <= k[i]) {
			s += c[idx];
			idx ++;
		}
		else {
			s += c[k[i]];
		}
	}
	printf ("%lld\n", s);
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
