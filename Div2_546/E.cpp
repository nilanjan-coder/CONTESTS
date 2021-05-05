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
		long long a[n+1], dpa[n+1];
		dpa[0] = 0;
		for (int i = 1; i <= n; i ++) {
			cin >> a[i];
			dpa[i] = dpa[i-1] + a[i];
		}
		long long k[n], dpk[n];
		dpk[0] = 0;
		for (int i = 1; i <= n-1; i ++) {
			cin >> k[i];
			dpk[i] = dpk[i-1] + k[i];
		}
		int q;
		cin >> q;
		while (q --) {
			char x;
			int a, b;
			cin >> x >> a >> b;
			
		}
	}
}




