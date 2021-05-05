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
		long long a, b;
		cin >> a >> b;
		if (b < a) swap (a, b);
		if (b % a == 0) {
			long double p = log2l(b * 1.0 / a);
			long long p0 = p;
			if (p == p0) {
				cout << ceil(p / 3) << "\n";
				continue;
			}
		}
		cout << -1 << "\n";
	}
}







