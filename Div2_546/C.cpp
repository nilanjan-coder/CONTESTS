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
	// cin >> tc;
	while (tc --) {
		int n, m;
		cin >> n >> m;
		int a[n][m], b[n][m];
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cin >> b[i][j];
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				int i0 = i, j0 = j;
				bool f = false;
				while (i0 < n && j0 >= 0) {
					if (b[i][j] == a[i0][j0]) {
						swap (a[i][j], a[i0][j0]);
						f = true;
						break;
					}
					i0 ++;
					j0 --;
				}
				if (f) continue;
				i0 = i;
				j0 = j;
				while (i0 >= 0 && j0 < m) {
					if (b[i][j] == a[i0][j0]) {
						swap (a[i][j], a[i0][j0]);
						f = true;
						break;
					}
					i0 --;
					j0 ++;
				}
				if (f) continue;
				cout << "NO";
				return 0;
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (a[i][j] - b[i][j]) {
					cout << "NO";
					return 0;
				}
			}
		}
		cout << "YES";
	}
}



