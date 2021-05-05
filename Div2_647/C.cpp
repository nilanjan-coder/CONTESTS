#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
int cnt (long long n) {
	int c = 0;
	for (int i = 60; i >= 0; i --) {
		if (n & (1LL << i)) c ++;
	}
	return c;
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
		long long n, s = 0LL;
		cin >> n;
		cout << 2 * n - cnt(n) << "\n";
	}
}









