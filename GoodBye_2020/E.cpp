#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
long long f (long long x) { return x % MOD; }
void test_case() {
	long long n;
	scanf ("%lld", &n);
	long long x[n], p[n][60], cnt[60];
	for (long long j = 0; j < 60; j ++) cnt[j] = 0; 
	for (long long i = 0; i < n; i ++) {
		scanf ("%lld", &x[i]);
		for (long long j = 0; j < 60; j ++) {
			p[i][j] = x[i] % 2;
			x[i] /= 2;
			cnt[j] += p[i][j];
		}
	}
	long long ans = 0;
	for (long long i = 0; i < n; i ++) {
		long long y = 0, z = 0;
		for (long long j = 0; j < 60; j ++) {
			if (p[i][j] == 1) {
				y = f(y + f(cnt[j] * f(1LL << j)));
				z = f(z + f(n * f(1LL << j)));
			}
			else {
				z = f(z + f(cnt[j] * f(1LL << j)));
			}
		}
		ans = f(ans + f(y * z));
	}
	printf ("%lld\n", ans);
}
int main () {
	int T = 1;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t ++) {
		test_case();
	}
}






