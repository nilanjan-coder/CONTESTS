#include <bits/stdc++.h>
using namespace std;
int n;
int p[2001], c[2001];
vector <int> g[2001];
int cnt[2001];
vector <int> val;
int a[2001];
void dfs_get_cnt (int u) {
	cnt[u] = 1;
	for (int v: g[u]) {
		dfs_get_cnt (v);
		cnt[u] += cnt[v];
	}
}
void dfs_get_val (int u) {
	a[u] = val[c[u]];
	val.erase (val.begin() + c[u]);
	for (int v: g[u]) {
		dfs_get_val (v);
	}
}
int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf ("%d%d", &p[i], &c[i]);
	}
	int root;
	for (int i = 1; i <= n; i ++) {
		g[p[i]].push_back(i);
		if (p[i] == 0) {
			root = i;
		}
	}
	for (int i = 1; i <= n; i ++) {
		cnt[i] = 0;
	}
	dfs_get_cnt (root);
	for (int i = 1; i <= n; i ++) {
		if (c[i] > cnt[i] - 1) {
			printf ("NO");
			return 0;
		}
	}
	val.push_back (1);
	int gap = 2000;
	for (int i = 2; i <= n; i ++) {
		val.push_back (val.back() + gap);
	}
	dfs_get_val (root);
	printf ("YES\n");
	for (int i = 1; i <= n; i ++) {
		printf ("%d ", a[i]);
	}
}