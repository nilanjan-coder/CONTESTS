#include <bits/stdc++.h>
using namespace std;
void test_case () {
	int n, d;
	scanf ("%d%d", &n, &d);
	int a[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a[i]);
	}
	sort (a, a + n);
	int idx = upper_bound (a, a + n, d) - a;
	if (idx == n) {
		printf ("YES\n");
	}
	else {
		if (idx >= 2) {
			if (a[0] + a[1] <= d) {
				printf ("YES\n");
			}
			else {
				printf ("NO\n");
			}
		}
		else {
			printf ("NO\n");
		}
	}
}
int main () {
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		test_case ();
	}
}