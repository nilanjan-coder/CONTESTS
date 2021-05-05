#include <bits/stdc++.h>
using namespace std;
long long INF = 1e18;
void test_case () {
	int n, m;
	scanf ("%d%d", &n, &m);
	long long a[n][m];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			scanf ("%lld", &a[i][j]);
			a[i][j] -= (long long)(i + j);
		}
	}
	long long dp[n][m], ans = INF;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			long long val = a[i][j];
			for (int i0 = 0; i0 < n; i0 ++) {
				for (int j0 = 0; j0 < m; j0 ++) {
					if (a[i0][j0] < val) {
						dp[i0][j0] = INF;
					}
					else if (i0 == 0 && j0 == 0) {
						dp[i0][j0] = a[i0][j0] - val;
					}
					else if (i0 == 0) {
						if (dp[i0][j0 - 1] == INF) {
							dp[i0][j0] = INF;
						}
						else {
							dp[i0][j0] = dp[i0][j0 - 1] + a[i0][j0] - val;
						}
					}
					else if (j0 == 0) {
						if (dp[i0 - 1][j0] == INF) {
							dp[i0][j0] = INF;
						}
						else {
							dp[i0][j0] = dp[i0 - 1][j0] + a[i0][j0] - val;
						}
					}
					else {
						if (dp[i0 - 1][j0] == INF && dp[i0][j0 - 1] == INF) {
							dp[i0][j0] = INF;
						}
						else if (dp[i0][j0 - 1] == INF) {
							dp[i0][j0] = dp[i0 - 1][j0] + a[i0][j0] - val;
						}
						else if (dp[i0 - 1][j0] == INF) {
							dp[i0][j0] = dp[i0][j0 - 1] + a[i0][j0] - val;
						}
						else {
							dp[i0][j0] = min (dp[i0 - 1][j0], dp[i0][j0 - 1]) + a[i0][j0] - val;
						}
					}
				}
			}
			ans = min (ans, dp[n - 1][m - 1]);
		}
	}
	printf ("%lld\n", ans);
}
int main () {
	int t;
	scanf ("%d", &t);
	while (t --) {
		test_case ();
	}
}