#include <bits/stdc++.h>
using namespace std;
string read (int k) {
	char s[k+1];
	scanf ("%s", s);
	return string(s);
}
void test_case() {
	int k, ans = 0;
	scanf ("%d", &k);
	string s = read(k);
	int dp[k];
	for (int i = 0; i < k; i ++) dp[i] = 0;
	for (int i = 1; i < k; i ++) {
		if (s[i] == 'P' && s[i-1] == 'A') {
			s[i] = 'A';
			dp[i] = dp[i-1] + 1;
		}
		ans = max (ans, dp[i]);
	}
	printf ("%d\n", ans);
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}