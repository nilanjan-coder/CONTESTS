#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	scanf ("%d", &n);
	long long a[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
	}
	long long sum = 0, nax = 0;
	for (int i = 0; i < n; i ++) {
		sum += a[i];
		nax = max (nax, a[i]);
	}
	if (sum & 1) {
		printf ("NO");
	}
	else {
		if (sum - nax < nax) {
			printf ("NO");
		}
		else {
			printf ("YES");
		}
	}
}