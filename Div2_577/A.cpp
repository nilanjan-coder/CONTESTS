#include <bits/stdc++.h>
using namespace std;
int main() {
	int n, m;
	scanf ("%d%d", &n, &m);
	char s[n][m];
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			scanf (" %c", &s[i][j]);
		}
	}
	int a[m];
	for (int i = 0; i < m; i ++) {
		scanf ("%d", &a[i]);
	}
	int ans = 0;
	for (int j = 0; j < m; j ++) {
		int A = 0, B = 0, C = 0, D = 0, E = 0;
		for (int i = 0; i < n; i ++) {
			if (s[i][j] == 'A') A ++;
			else if (s[i][j] == 'B') B ++;
			else if (s[i][j] == 'C') C ++;
			else if (s[i][j] == 'D') D ++;
			else if (s[i][j] == 'E') E ++;
		}
		ans += (max({A, B, C, D, E}) * a[j]);
	}
	printf ("%d", ans);
}