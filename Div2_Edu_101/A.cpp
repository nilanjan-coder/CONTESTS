#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
string read () {
	char s[100];
	scanf ("%s", s);
	return string(s);
}
void test_case() {
	string s = read();
	int n = s.length(), open = -1, close = -1;
	for (int i = 0; i < n; i ++) {
		if (s[i] == '(') open = i;
		else if (s[i] == ')') close = i;
	}
	if (open == -1 && close == -1) {
		if (n & 1) printf ("NO\n");
		else printf ("YES\n");
	}
	else if (open == -1) {
		if (close == 0) printf ("NO\n");
		else {
			if ((n - 2) & 1) printf ("NO\n");
			else printf ("YES\n");
		}
	}
	else if (close == -1) {
		if (open == n - 1) printf ("NO\n");
		else {
			if ((n - 2) & 1) printf ("NO\n");
			else printf ("YES\n");
		}
	}
	else {
		if (open < close) {
			if ((n - 2) & 1) printf ("NO\n");
			else printf ("YES\n");
		}
		else {
			if (close == 0) printf ("NO\n");
			else {
				if (open == n - 1) printf ("NO\n");
				else {
					if ((n - 4) & 1) printf ("NO\n");
					else printf ("YES\n");
				}
			}
		}
	}
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	// test_case();
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}






