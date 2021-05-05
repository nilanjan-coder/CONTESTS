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
	cin >> tc;
	while (tc --) {
		long long n;
		cin >> n;
		for (long long x = n;; x ++) {
			long long p = x;
			bool f = true;
			while (p) {
				int d = p % 10;
				if (d == 0) {
					p /= 10;
					continue;
				}
				if (x % d) {
					f = false;
					break;
				}
				p /= 10;
			}
			if (f) {
				cout << x << "\n";
				break;
			}
		}
	}
}



