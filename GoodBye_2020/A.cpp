#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	scanf ("%d", &n);
	int x[n];
	set <int> ans;
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &x[i]);
	}
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			ans.insert(x[j] - x[i]);
		}
	}
	printf ("%d\n", (int)ans.size());
}
int main () {
	int T = 1;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t ++) {
		// printf ("Case #%d: ", t);
		test_case();
	}
}






