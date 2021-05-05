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
	cin >> tc;
	while (tc --) {
		int n;
		cin >> n;
		int s[n];
		for (int i = 0 ; i < n ; i ++) {
			cin >> s[i];
		}
		sort (s, s+n);
		int s0[n];
		int k = -1;
		for (int mask = 1; mask < (1 << 10); mask ++) {
			for (int i = 0; i < n; i ++) {
				s0[i] = s[i] ^ mask;
			}
			sort (s0, s0+n);
			bool f = true;
			for (int i = 0 ; i < n; i ++) {
				if (s0[i] - s[i]) {
					f = false;
					break;
				}
			}
			if (f) {
				k = mask;
				break;
			}
		}
		cout << k << "\n";
	}
}








