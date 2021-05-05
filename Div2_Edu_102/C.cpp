#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long n, k;
	scanf ("%lld%lld", &n, &k);
	for (long long i = 1; i <= k; i ++) {
		long long s;
		if (i + n - k > k) {
			long long z = 2 * k - n;
			s = z * (2 * k - 2 * i + z) + (k - i) * (k - i);
		}
		else {
			long long p = n - k;
			s = ((k - i) * (k - i + 1)) / 2 + p * (k - i) - (p * (p + 1)) / 2;
		}
		if (s <= (n - k) * (n - k)) {
			for (long long j = 1; j < i; j ++) {
				printf ("%lld ", j);
			}
			for (long long j = k; j >= i; j --) {
				printf ("%lld ", j);
			}
			printf ("\n");
			return;
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