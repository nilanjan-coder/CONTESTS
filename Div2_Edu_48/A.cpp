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
		int n, m;
		cin >> n >> m;
		int a[n];
		int xs = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (xs == 0) {
				cout << a[i] / m << " ";
				xs = m - a[i] % m;
			}
			else {
				if (xs > a[i]) {
					cout << 0 << " ";
					xs -= a[i];
				}
				else {
					cout << 1 + (a[i] - xs) / m << " ";
					xs = m - (a[i] - xs) % m;
				}
			}
		}
	}
}





