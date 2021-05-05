#include <bits/stdc++.h>
using namespace std;
int main() {
	long long n, k, nax = 0;
	scanf ("%lld%lld", &n, &k);
	long long a[n], sum = 0, p = (n-1) / 2;
	for (long long i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
	}
	sort (a, a+n);
	for (long long i = p; i < n - 1; i ++) {
		if (k >= (i - p + 1) * (a[i+1] - a[i])) {
			k -= ((i - p + 1) * (a[i+1] - a[i]));
		}
		else {
			long long buffer = k / (i - p + 1);
			nax = a[i] + buffer;
			break;
		}
	}
	if (nax == 0) {
		long long buffer = k / (n - p);
		nax = a[n-1] + buffer;
	}
	printf ("%lld", nax);
}