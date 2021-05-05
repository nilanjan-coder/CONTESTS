#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	long long x, y;
	scanf ("%d%lld%lld", &n, &x, &y);
	long long a[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
	}
	if (y % x) {
		printf ("0");
	}
	else {
		long long p = y / x;
		vector <long long> p2, p4;
		for (int i = 0; i < n; i ++) {
			if (a[i] % x == 0) {
				p2.push_back(a[i] / x);
			}
			if (y % a[i] == 0) {
				p4.push_back(y / a[i]);
			}
		}
		// p = p1 * p3; (p1,p2) and (p3,p4) coprime
	}
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







