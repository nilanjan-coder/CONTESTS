#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc = 1;
	// cin >> tc;
	while (tc --) {
		int n, m;
		cin >> n >> m;
		int p[n+1];
		for (int i = 1; i <= n; i ++) {
			cin >> p[i];
		}
		vector <int> g[n+1];
		for (int i = 1; i <= m; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
		}
		set <int> bad;
		bad.insert(p[n]);
		for (int i = n-1; i >= 1; i --) {
			int cnt = 0;
			for (int x: g[p[i]]) {
				if (bad.find(x) != bad.end()) {
					cnt ++;
				}
			}
			if (cnt - bad.size()) bad.insert(p[i]);
		}
		cout << n - bad.size();
	}
}



