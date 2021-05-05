#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, LIM = 2e5, INF = 1e9 + 5;
const long double ERR = 1e-9;
vector <int> g[LIM+1];
int p[LIM+1];
long long dp[LIM+1], a[LIM+1], ans = 0;
void dfs_build_dp (int u) {
	dp[u] = a[u];
	long long val = 0;
	for (int v: g[u]) {
		dfs_build_dp(v);
		val = max (val, dp[v]);
	}
	dp[u] += val;
}
void dfs_go_bandit (int u) {
	if ((int)g[u].size() == 0) {
		ans = a[u];
		return;
	}
	long long nax = 0;
	int idx = 0;
	for (int v: g[u]) {
		if (nax < dp[v]) {
			nax = dp[v];
			idx = v;
		}
	}
	long long space = 0;
	for (int v: g[u]) {
		space += (dp[idx] - dp[v]);
	}
	a[u] -= space;
	if (a[u] < 0) a[u] = 0;
	long long distribute = ceil (a[u] * 1.0 / (int)g[u].size());
	a[idx] += distribute;
	dfs_go_bandit(idx);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int tc = 1;
	// scanf ("%d", &tc);
	while (tc --) {
		int n;
		scanf ("%d", &n);
		for (int i = 2; i <= n; i ++) {
			scanf ("%d", &p[i]);
			g[p[i]].push_back(i);
		}
		for (int i = 1; i <= n; i ++) {
			scanf ("%lld", &a[i]);
		}
		dfs_build_dp(1);
		dfs_go_bandit(1);
		printf ("%lld", ans);
	}
}








