#include <bits/stdc++.h>
using namespace std;
int INF = 1e6;
vector <int> gr[5001];
int par[5001][(int)log2(5000)+1];
int depth[5001];
int mat[5001][5001];
void dfs (int u, int p) {
	par[u][0] = p;
	for (int v: gr[u]) {
		if (v != p) {
			depth[v] = depth[u] + 1;
			dfs(v, u);
		}
	}
}
void spt (int n) {
	for (int i = 1; i <= (int)log2(n); i ++) {
		for (int j = 1; j <= n; j ++) {
			par[j][i] = par[par[j][i-1]][i-1];
		}
	}
}
int lift (int x, int dist) {
	int i = 0;
	while (dist) {
		if (dist & 1) {
			x = par[x][i];
		}
		dist /= 2;
		i ++;
	}
	return x;
}
int lca (int x, int y, int n) {
	if (depth[x] > depth[y]) {
		swap(x, y);
	}
	int dist = depth[y] - depth[x];
	y = lift(y, dist);
	if (x == y) {
		return x;
	}
	for (int i = log2(n); i >= 0; i --) {
		if (par[x][i] != par[y][i]) {
			x = par[x][i];
			y = par[y][i];
		}
	}
	return par[x][0];
}
void print (int n) {
	printf ("DEPTH:\n");
	for (int i = 1; i <= n; i ++) {
		printf ("%d: %d\n", i, depth[i]);
	}
	printf ("PAR:\n");
	for (int i = 1; i <= n; i ++) {
		printf ("%d:\n", i);
		for (int j = 0; j <= (int)log2(n); j ++) {
			printf ("%d: %d\n", j, par[i][j]);
		}
	}
}
int main() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i <= n-1; i ++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		gr[x].push_back(y);
		gr[y].push_back(x);
		mat[x][y] = mat[y][x] = i;
	}
	for (int i = 0; i <= (int)log2(n); i ++) {
		for (int j = 0; j <= n; j ++) {
			par[j][i] = 0;
		}
	}
	depth[1] = 0;
	dfs(1, 0);
	spt(n);
	int nin[n];
	//print(n);
	for (int i = 0; i < n; i ++) nin[i] = 0;
	int m;
	scanf ("%d", &m);
	int a[m], b[m], c[m], g[m];
	for (int i = 0; i < m; i ++) {
		scanf ("%d%d%d", &a[i], &b[i], &g[i]);
		c[i] = lca(a[i], b[i], n);
		int x = a[i], y = b[i], z = c[i], v = g[i];
		while (x != z) {
			int idx = mat[x][par[x][0]];
			nin[idx] = max(nin[idx], v);
			x = par[x][0];
		}
		while (y != z) {
			int idx = mat[y][par[y][0]];
			nin[idx] = max(nin[idx], v);
			y = par[y][0];
		}
	}
	for (int i = 1; i < n; i ++) {
		if (nin[i] == 0) {
			nin[i] = INF;
		}
	}
	for (int i = 0; i < m; i ++) {
		int x = a[i], y = b[i], z = c[i], val = INF + 1;
		while (x != z) {
			int idx = mat[x][par[x][0]];
			val = min(val, nin[idx]);
			x = par[x][0];
		}
		while (y != z) {
			int idx = mat[y][par[y][0]];
			val = min(val, nin[idx]);
			y = par[y][0];
		}
		if (val != g[i]) {
			printf ("-1");
			return 0;
		}
	}
	for (int i = 1; i < n; i ++) {
		printf ("%d ", nin[i]);
	}
}
