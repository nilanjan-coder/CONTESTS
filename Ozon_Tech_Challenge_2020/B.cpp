#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
const long double ERR = 1e-9;
string read () {
	char s[1000];
	scanf ("%s", s);
	return string(s);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int tc = 1;
	// scanf ("%d", &tc);
	while (tc --) {
		string s = read();
		int n = s.length();
		vector <int> open, close;
		for (int i = 0; i < n; i ++) {
			if (s[i] == '(') {
				open.push_back(i);
			}
		}
		for (int j = n-1; j >= 0; j --) {
			if (s[j] == ')') {
				close.push_back(j);
			}
		}
		/* for (int x: open) {
			printf ("%d ", x);
		}
		printf ("\n");
		for (int y: close) {
			printf ("%d ", y);
		}
		printf ("\n"); */
		int l = min ((int)open.size(), (int)close.size());
		int i;
		for (i = 0; i < l && open[i] < close[i]; i ++);
		if (i == 0) {
			printf ("0\n");
		}
		else {
			printf ("1\n");
			printf ("%d\n", 2*i);
			for (int j = 0; j < i; j ++) {
				printf ("%d ", open[j] + 1);
			}
			for (int j = i-1; j >= 0; j --) {
				printf ("%d ", close[j] + 1);
			}
		}
	}
}



