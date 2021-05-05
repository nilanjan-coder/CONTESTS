#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
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
		vector <int> g[n+1];
		for (int i = 1; i <= m; i ++) {
			int a, b;
			cin >> a >> b;
			g[a].push_back(b);
			g[b].push_back(a);
		}
		int t[n+1];
		vector <int> h[n+1];
		for (int i = 1; i <= n; i ++) {
			cin >> t[i];
			h[t[i]].push_back(i);
		}
		vector <int> ans;
		set <int> proc;
		for (int i = 1; i <= n; i ++) {
			for (int x: h[i]) {
				vector <int> cnt(i+1, 0);
				for (int y: g[x]) {
					if (proc.find(y) != proc.end()) {
						cnt[t[y]] ++;
					}
				}
				if (cnt[i] > 0) {
					cout << -1;
					return 0;
				}
				for (int j = 1; j <= i-1; j ++) {
					if (cnt[j] == 0) {
						cout << -1;
						return 0;
					}
				}
				ans.push_back(x);
				proc.insert(x);
			}
		}
		for (int x: ans) cout << x << " ";
	}
}










