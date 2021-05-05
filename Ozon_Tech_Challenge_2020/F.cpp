#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int RANDOM = (int)chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(RANDOM);
set <int> prime_divisors;
map <long long, bool> proc;
void calc (long long x) {
	if (proc[x]) return;
	long long y = x;
	for (int k = 2; k * k <= x; k ++) {
		if (x % k == 0) {
			prime_divisors.insert(k);
			while (x % k == 0) x /= k;
		}
	}
	if (x > 1) {
		prime_divisors.insert(x);
	}
	proc[y] = true;
}
void test_case() {
	int n;
	scanf ("%d", &n);
	uniform_int_distribution <int> uni(0, n - 1);
	long long a[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
	}
	int ans = n;
	for (int i = 0; i < 20; i ++) {
		int j = uni(rng);
		calc(a[j]);
		calc(a[j] - 1);
		calc(a[j] + 1);
	}
	for (int d: prime_divisors) {
		int op = 0;
		for (int i = 0; i < n; i ++) {
			int r = a[i] % d;
			if (a[i] < d) op += (d - a[i]);
			else op += min (r, d - r);
		}
		ans = min (ans, op);
	}
	printf ("%d", ans);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	test_case();
	/* int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	} */
}






