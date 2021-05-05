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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i;
		for (i = n-1; i >= 0; i --) {
			if (s[i] - ')') {
				break;
			}
		}
		if (i < (n-1) / 2) cout << "Yes\n";
		else cout << "No\n";
	}
}



