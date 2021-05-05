#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n, odd = 0, even = 0;
	scanf ("%d", &n);
	int a[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a[i]);
		if (a[i] & 1) odd ++;
		else even ++;
	}
	if ((even == n) || (odd == n && n % 2 == 0)) {
		printf ("NO\n");
	}
	else {
		printf ("YES\n");
	}
}
int main() {
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}