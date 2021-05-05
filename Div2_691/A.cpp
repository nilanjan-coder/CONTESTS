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
		string r, b;
		cin >> r >> b;
		int red = 0, blue = 0;
		for (int i = 0; i < n; i ++) {
			if (r[i] > b[i]) red ++;
			else if (r[i] < b[i]) blue ++;
		}
		if (red > blue) cout << "RED\n";
		else if (red < blue) cout << "BLUE\n";
		else cout << "EQUAL\n";
	}
}





 
