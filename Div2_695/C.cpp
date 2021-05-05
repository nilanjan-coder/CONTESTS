#include <bits/stdc++.h>
using namespace std;
long long INF = 1e9 + 1;
void test_case() {
	int n1, n2, n3;
	scanf ("%d%d%d", &n1, &n2, &n3);
	long long a[n1], b[n2], c[n3];
	long long nin1 = INF, nin2 = INF, nin3 = INF, sum1 = 0, sum2 = 0, sum3 = 0;
	for (int i = 0; i < n1; i ++) {
		scanf ("%lld", &a[i]);
		nin1 = min (nin1, a[i]);
		sum1 += a[i];
	}
	for (int i = 0; i < n2; i ++) {
		scanf ("%lld", &b[i]);
		nin2 = min (nin2, b[i]);
		sum2 += b[i];
	}
	for (int i = 0; i < n3; i ++) {
		scanf ("%lld", &c[i]);
		nin3 = min (nin3, c[i]);
		sum3 += c[i];
	}
	printf ("%lld", max ({sum1 + sum2 + sum3 - 2 * nin1 - 2 * nin2, sum1 + sum2 + sum3 - 2 * nin3 - 2 * nin2, sum1 + sum2 + sum3 - 2 * nin1 - 2 * nin3, sum2 + sum3 - sum1, sum1 + sum3 - sum2, sum1 + sum2 - sum3}));
}
int main() {
	int T = 1;
	//scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
