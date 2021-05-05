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
		int p[n+1];
		for (int i = 1; i <= n; i ++) {
			cin >> p[i];
		}
		bool f = false;
		for (int i = 1; i <= n; i ++) {
			int c = 0, k1 = i, k2, k3;
			for (int j = 1; j < i; j ++) {
				if (p[j] < p[i]) {
					c ++;
					k2 = j;
					break;
				}
			}
			for (int j = i+1; j <= n; j ++) {
				if (p[j] < p[i]) {
					c ++;
					k3 = j;
					break;
				}
			}
			if (c == 2) {
				cout << "YES\n" << k2 << " " << k1 << " " << k3 << "\n";
				f = true;
				break;
			}
		}
		if (!f) cout << "NO\n";
	}
}
