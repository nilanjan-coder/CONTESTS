#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long n, x;
	scanf ("%lld%lld", &n, &x);
	long long a[n];
	long long sum1 = 0, sum2 = 0;
	for (long long i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
		sum1 += a[i];
		sum2 += (long long)ceil(a[i] * 1.0 / x);
	}
	printf ("%lld %lld\n", (long long)ceil(sum1 * 1.0 / x), sum2);
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
