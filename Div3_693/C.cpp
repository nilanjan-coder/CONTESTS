#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long n;
	scanf ("%lld", &n);
	long long a[n+1];
	for (long long i = 1; i <= n; i ++) {
		scanf ("%lld", &a[i]);
	}
	long long dp[n+1], ans = 0;
	for (long long i = n; i >= 1; i --) {
		dp[i] = a[i];
		if (i + a[i] <= n) dp[i] += dp[i + a[i]];
		ans = max(ans, dp[i]);
	}
	printf ("%lld\n", ans);
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
