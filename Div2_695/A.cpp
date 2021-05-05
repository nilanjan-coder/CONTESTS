#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	scanf ("%d", &n);
	if (n == 1) printf ("9\n");
	else if (n == 2) printf ("98\n");
	else {
		int c = 0;
		printf ("98");
		for (int i = 3; i <= n; i ++) {
			printf ("%d", (9 + c) % 10);
			c ++;
		}
		printf ("\n");
	}
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}