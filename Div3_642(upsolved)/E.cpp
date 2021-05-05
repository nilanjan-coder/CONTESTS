#include <bits/stdc++.h>
using namespace std;
string read (int n) {
	char s[n + 1];
	scanf ("%s", s);
	return string(s);
}
void print (int cnt[], int dp1[], int dp2[], int n) {
	printf ("CNT:\n");
	for (int i = 0; i <= n; i ++) {
		printf("%d ", cnt[i]);
	}
	printf ("\n");
	printf ("DP1:\n");
	for (int i = 0; i <= n; i ++) {
		printf("%d ", dp1[i]);
	}
	printf ("\n");
	printf ("DP2:\n");
	for (int i = 0; i <= n; i ++) {
		printf("%d ", dp2[i]);
	}
	printf ("\n");
	printf ("DP1 + DP2:\n");
	for (int i = 0; i <= n; i ++) {
		printf ("%d ", dp1[i] + dp2[i]);
	}
	printf ("\n");
}
void test_case () {
	int n, k;
	scanf ("%d%d", &n, &k);
	string s = read(n);
	s = '#' + s;
	int cnt[n + 1];
	cnt[0] = 0;
	for (int i = 1; i <= n; i ++) {
		cnt[i] = cnt[i - 1] + s[i] - '0';
	}
	int dp1[n + 1], dp2[n + 1];
	dp1[0] = 0;
	dp2[0] = cnt[n];
	for (int i = 1; i <= n; i ++) {
		if (i <= k) {
			dp1[i] = cnt[i - 1] + ((s[i] == '1') ? 0 : 1);
		}
		else {
			dp1[i] = min (cnt[i - 1], dp1[i - k] + cnt[i - 1] - cnt[i - k]) + ((s[i] == '1') ? 0 : 1);
		}
	}
	for (int i = n; i >= 1; i --) {
		if (i >= n - k + 1) {
			dp2[i] = cnt[n] - cnt[i] + ((s[i] == '1') ? 0 : 1);
		}
		else {
			dp2[i] = min (dp2[i + k] + cnt[i + k - 1] - cnt[i], cnt[n] - cnt[i]) + ((s[i] == '1') ? 0 : 1);
		}
	}
	//print (cnt, dp1, dp2, n);
	int ans = dp1[0] + dp2[0];
	for (int i = 1; i <= n; i ++) {
		ans = min (ans, ((s[i] == '1') ? 0 : -1) + dp1[i] + dp2[i]);
	}
	printf ("%d\n", ans);
}
int main () {
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case ();
		//printf ("\n");
	}
}