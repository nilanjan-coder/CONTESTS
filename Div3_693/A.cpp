#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long w, h, n;
	scanf ("%lld%lld%lld", &w, &h, &n);
	long long c1 = 0, c2 = 0;
	while (w % 2 == 0) {
		c1 ++;
		w /= 2;
	}
	while (h % 2 == 0) {
		c2 ++;
		h /= 2;
	}
	if ((1LL << c1) * (1LL << c2) >= n) {
		printf ("YES\n");
	}
	else {
		printf ("NO\n");
	}
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
