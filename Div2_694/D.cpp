#include <bits/stdc++.h>
using namespace std;
int mask[1000001];
void test_case() {
	int n;
	scanf ("%d", &n);
	int a[n];
	map <int, int> cnt;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a[i]);
		//printf ("%d: %d\n", a[i], mask[a[i]]);
		cnt[mask[a[i]]] ++;
	}
	int nax0 = 0, nax1 = 0;
	for (auto i: cnt) {
		nax0 = max (nax0, i.second);
	}
	//printf ("nax0 = %d\n", nax0);
	for (auto i: cnt) {
		if (i.second % 2 == 0 && i.first != 1) {
			cnt[1] += i.second;
			i.second = 0;
		}
	}
	for (auto i: cnt) {
		nax1 = max (nax1, i.second);
	}
	//printf ("nax1 = %d\n", nax1);
	int Q;
	scanf ("%d", &Q);
	while (Q --) {
		long long w;
		scanf ("%lld", &w);
		if (w == 0) {
			printf ("%d\n", nax0);
		}
		else {
			printf ("%d\n", nax1);
		}
	}
}
int main() {
	mask[0] = 0;
	for (int i = 1; i <= 1000000; i ++) {
		int val = 1, k = i;
		for (int j = 2; j * j <= k; j ++) {
			int c = 0;
			while (k % j == 0) {
				k /= j;
				c ++;
			}
			if (c & 1) {
				val *= j;
			}
		}
		if (k > 1) {
			val *= k;
		}
		mask[i] = val;
		//printf ("%d: %d\n", i, mask[i]);
	}
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
