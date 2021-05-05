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
		int t[n+1];
		for (int i = 1; i <= n; i ++) {
			cin >> t[i];
		}
		for (int i = 1; i <= m-1; i ++) {
			int cnt = 0;
			for (int j = 1; j <= n-1; j ++) {
				if (t[j] - t[j+1]) cnt ++;
			}
			cout << cnt << "\n";
			int a, b;
			cin >> a >> b;
			for (int j = 1; j <= n; j ++) {
				if (t[j] == b) t[j] = a;
			}
		}
		cout << 0 << "\n";
	}
}

