#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, ans = 0;
	long long a, b, k;
	scanf ("%d%lld%lld%lld", &n, &a, &b, &k);
	long long c = a + b;
	long long h[n];
	vector <long long> store;
	for (int i = 0; i < n; i ++) {
		scanf ("%lld", &h[i]);
		h[i] %= c;
		if (h[i] == 0) h[i] += c;
		store.push_back((long long)ceil(h[i] * 1.0 / a) - 1);
	}
	sort (store.begin(), store.end());
	for (long long x: store) {
		if (x <= k) {
			k -= x;
			ans ++;
		}
		else {
			break;
		}
	}
	printf ("%d", ans);
}