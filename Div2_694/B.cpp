#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long n, x;
	scanf ("%lld%lld", &n, &x);
	long long a[n], nin = 1e18, pos = -1, s = 0;
	for (long long i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
		long long y = a[i], c = 0;
		while (y % x == 0) {
			y /= x;
			c ++;
		}
		if (c + 1 < nin) {
			nin = c + 1;
			pos = i;
		}
	}
	for (long long i = 0; i < n; i ++) {
		if (i < pos) s += (a[i] * (nin + 1));
		else s += (a[i] * nin);
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
