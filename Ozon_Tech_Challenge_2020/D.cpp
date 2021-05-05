#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
set <int> g[1001], leaves;
void find_leaves (int u, int par) {
	if ((int)g[u].size() <= 1) leaves.insert(u);
	for (int v: g[u]) {
		if (v != par) {
			find_leaves (v, u);
		}
	}
}
void test_case() {
	int n;
	scanf ("%d", &n);
	for (int i = 1; i < n; i ++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		g[x].insert(y);
		g[y].insert(x);
	}
	find_leaves (1, 0);
	while ((int)leaves.size() > 1) {
		set <int> :: iterator it = leaves.begin();
		int u = *it;
		++ it;
		int v = *it;
		printf ("? %d %d\n", u, v);
		fflush(stdout);
		int lca;
		scanf ("%d", &lca);
		if (lca == u || lca == v) {
			printf ("! %d", lca);
			return;
		}
		else {
			set <int> :: iterator it1 = g[u].begin(), it2 = g[v].begin();
			int u0 = *it1, v0 = *it2;
			g[u0].erase(u);
			g[v0].erase(v);
			leaves.erase(u);
			leaves.erase(v);
			if ((int)g[u0].size() <= 1) leaves.insert(u0);
			if ((int)g[v0].size() <= 1) leaves.insert(v0);
		}
	}
	printf ("! %d", *leaves.begin());
	return;
}
int main () {
	/* #ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif */
	test_case();
	/* int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	} */
}




