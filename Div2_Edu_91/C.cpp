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
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
		}
		sort (a, a+n);
		int i = n-1, j = 1, teams = 0;
		while (i >= 0) {
			if (a[i] * j >= x) {
				teams ++;
				i --;
				j = 1;
			}
			else {
				i --;
				j ++;
			}
		}
		cout << teams << "\n";
	}
}


