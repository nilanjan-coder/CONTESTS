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
		int n;
		cin >> n;
		long long a[n], b[n];
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		for (int i = 0; i < n; i ++) {
			cin >> b[i];
		}
		long long s[n], dp1[n], dp2[n];
		for (int i = n-1; i >= 0; i --) {
			s[i] = (a[i] + b[i]) + ((i < n-1) ? s[i+1] : 0);
			// cout << s[i] << " ";
		}
		// cout << "\n";
		for (int i = 0; i < n; i ++) {
			if (i & 1) {
				dp1[i] = ((i > 0) ? dp1[i-1] : 0) + 2 * i * b[i] + (2 * i + 1) * a[i];
			}
			else {
				dp1[i] = ((i > 0) ? dp1[i-1] : 0) + 2 * i * a[i] + (2 * i + 1) * b[i];
			}
			// cout << dp1[i] << " ";
		}
		// cout << "\n";
		for (int i = n-1; i >= 0; i --) {
			if (i & 1) {
				dp2[i] = ((i + 2 < n) ? (dp2[i+2] - 2 * s[i+2]) : 0) + 2 * i * b[i] + ((i < n-1) ? (2 * i + 1) * b[i+1] : 0) + (2 * n - 1) * a[i] + ((i < n-1) ? (2 * n - 2) * a[i+1] : 0);
			}
			else {
				dp2[i] = ((i + 2 < n) ? (dp2[i+2] - 2 * s[i+2]) : 0) + 2 * i * a[i] + ((i < n-1) ? (2 * i + 1) * a[i+1] : 0) + (2 * n - 1) * b[i] + ((i < n-1) ? (2 * n - 2) * b[i+1] : 0);
			}
			// cout << dp2[i] << " ";
		}
		// cout << "\n";
		long long nax = 0;
		for (int i = 0; i < n; i ++) {
			nax = max (nax, ((i > 0) ? dp1[i-1] : 0) + dp2[i]);
		}
		cout << nax;
	}
}




