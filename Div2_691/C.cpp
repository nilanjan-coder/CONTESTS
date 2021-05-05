#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
long long gcd (long long a , long long b) {
   if (a == 0) return b;
   return gcd(b % a, a);
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
	// cin >> tc;
	while (tc --) {
		int n, m;
		cin >> n >> m;
		long long a[n], b[m];
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		if (n == 1) {
			for (int j = 0; j < m; j ++) {
				cin >> b[j];
				cout << a[0] + b[j] << " ";
			}
			return 0;
		}
		sort (a, a+n);
		for (int i = 1; i < n; i ++) {
			a[i] -= a[0];
		}
		long long g = a[1];
		for (int i = 2; i < n; i ++) g = gcd(g, a[i]);
		for (int j = 0; j < m; j ++) {
			cin >> b[j];
			cout << gcd(a[0] + b[j], g) << " ";
		}
	}
}





 
