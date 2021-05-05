#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n, m;
	scanf ("%d%d", &n, &m);
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		sum += ((i - 1) / 2);
	}
	if (m > sum) {
		printf ("-1");
	}
	else {
		sum = 0;
		vector <int> ans;
		for (int i = 1; i <= n; i ++) {
			if (sum + (i - 1) / 2 <= m) {
				ans.push_back(i);
				sum += ((i - 1) / 2);
			}
			else {
				break;
			}
		}
		int d = m - sum, k = ans.back();
		if (d > 0) {
			ans.push_back(2 * k + 1 - 2 * d);
			if (k & 1) k ++;
			else k += 2;
		}
		else k ++;
		int s = ans.size();
		for (int i = s+1; i <= n; i ++) {
			ans.push_back(ans.back() + k);
		}
		for (int x: ans) {
			printf ("%d ", x);
		}
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





