#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5, MOD1 = 1e9 + 9, MOD2 = 1e9 + 21;
long long power (long long x, long long y, long long p) {
	if (y == 0) return 1;
	long long r = power (x, y / 2, p);
	r = (r * r) % p;
	if (y & 1) r = (r * x) % p;
	return r;
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc = 1;
	cin >> tc;
	while (tc --) {
		int n;
		long long p;
		cin >> n >> p;
		long long k[n];
		for (int i = 0; i < n; i ++) cin >> k[i];
		sort (k, k+n);
		long long diff = 0, diff1 = 0, diff2 = 0;
		for (int i = n-1; i >= 0; i --) {
			if (diff == 0 && diff1 == 0 && diff2 == 0) {
				diff = (diff + power(p, k[i], MOD)) % MOD;
				diff1 = (diff1 + power(p, k[i], MOD1)) % MOD1;
				diff2 = (diff2 + power(p, k[i], MOD2)) % MOD2;
			}
			else {
				diff = (diff - power(p, k[i], MOD) + MOD) % MOD;
				diff1 = (diff1 - power(p, k[i], MOD1) + MOD1) % MOD1;
				diff2 = (diff2 - power(p, k[i], MOD2) + MOD2) % MOD2;
			}
		}
		cout << diff << "\n";
	}
}






