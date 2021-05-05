#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n;
	scanf ("%d", &n);
	vector <pair <int, int>> ans;
	for (int x = 3; x <= n - 1; x ++) {
		if (x == 8) continue;
		ans.push_back({x, n});
	}
	if (n <= 8) {
		int p = n;
		while (n > 1) {
			ans.push_back({p, 2});
			n = ceil (n / 2.0);
		}
	}
	else {
		int p = n;
		while (n > 1) {
			ans.push_back({p, 8});
			n = ceil (n / 8.0);
		}
		p = n = 8;
		while (n > 1) {
			ans.push_back({p, 2});
			n = ceil (n / 2.0);
		}
	}
	printf ("%d\n", (int)ans.size());
	for (pair <int, int> x: ans) {
		printf ("%d %d\n", x.first, x.second);
	}
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	// test_case();
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}






