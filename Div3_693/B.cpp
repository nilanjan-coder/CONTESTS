#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n, c1 = 0, c2 = 0;
	scanf ("%d", &n);
	int a[n];
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a[i]);
		if (a[i] == 1) c1 ++;
		else c2 ++;
	}
	for (int i = 0; i <= c1; i ++) {
		for (int j = 0; j <= c2; j ++) {
			if (2 * i + 4 * j == c1 + 2 * c2) {
				printf ("YES\n");
				return;
			}
		}
	}
	printf ("NO\n");
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
