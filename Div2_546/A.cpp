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
		int l[n], r[n];
		for (int i = 0; i < n; i ++) {
			cin >> l[i] >> r[i];
		}
		int k;
		cin >> k;
		int i = lower_bound(r, r+n, k) - r;
		cout << n - i;
	}
}


