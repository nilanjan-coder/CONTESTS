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
		int n;
		cin >> n;
		if (n == 1) { cout << 4; return 0; }
		if (n == 2) { cout << 4; return 0; }
		int dp[n+1];
		dp[0] = 1;
		dp[1] = 4;
		dp[2] = 4;
		for (int i = 3; i <= n; i ++) {
			if (i & 1) dp[i] = dp[i-2] + 2 * (i + 1);
			else dp[i] = dp[i-4] + 2 * i;
		}
		cout << dp[n];
	}
}





 
