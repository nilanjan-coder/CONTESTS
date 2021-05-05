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
		string s;
		cin >> s;
		int cr = 0, cp = 0, cs = 0;
		int n = s.length();
		for (int i = 0; i < n; i ++) {
			if (s[i] == 'R') cr ++;
			else if (s[i] == 'P') cp ++;
			else if (s[i] == 'S') cs ++;
		}
		int nax = max({cr,cp,cs});
		char x;
		if (cr == nax) x = 'P';
		else if (cp == nax) x = 'S';
		else if (cs == nax) x = 'R';
		for (int i = 0; i < n; i ++) cout << x;
		cout << "\n";
	}
}

