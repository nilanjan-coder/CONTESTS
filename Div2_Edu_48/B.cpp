#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
const long double ERR = 1e-9;
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
		int n, m, q;
		cin >> n >> m >> q;
		string s, t;
		cin >> s >> t;
		int dp[n];
		for (int i = 0; i < n; i ++) {
			if (i <= m-2) dp[i] = 0;
			else dp[i] = ((i > 0) ? dp[i-1] : 0) + (s.substr(i-m+1, m) == t);
		}
		while (q --) {
			int l, r;
			cin >> l >> r;
			l --;
			r --;
			if (l+m-1 > r) cout << 0 << "\n";
			else cout << dp[r] - ((l+m-2 >= 0) ? dp[l+m-2] : 0) << "\n";
		}
	}
}






