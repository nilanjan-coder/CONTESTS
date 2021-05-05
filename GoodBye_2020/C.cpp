#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
string read() {
	static char s[100001];
	scanf ("%s", s);
	return string(s);
}
char get (set <int> change) {
	for (int i = 0; i < 26; i ++) {
		if (change.find(i) == change.end()) {
			return (char)('a' + i);
		}
	}
}
void test_case() {
	string s = read();
	int n = s.length();
	if (n == 1) {
		printf ("0\n");
		return;
	}
	int ans = 0;
	for (int i = 1; i < n; i ++) {
		if (i == 1 && s[i] == s[i-1]) {
			ans ++;
			set <int> change;
			change.insert(s[i]);
			change.insert(s[i-1] - 'a');
			if (i+1 < n) change.insert(s[i+1] - 'a');
			if (i+2 < n) change.insert(s[i+2] - 'a');
			s[i] = get(change);
		}
		if (i >= 2 && (s[i] == s[i-1] || s[i] == s[i-2])) {
			ans ++;
			set <int> change;
			change.insert(s[i]);
			change.insert(s[i-1] - 'a');
			change.insert(s[i-2] - 'a');
			if (i+1 < n) change.insert(s[i+1] - 'a');
			if (i+2 < n) change.insert(s[i+2] - 'a');
			s[i] = get(change);
		}
	}
	printf ("%d\n", ans);
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T = 1;
	scanf ("%d", &T);
	for (int t = 1; t <= T; t ++) {
		// printf ("Case #%d: ", t);
		test_case();
	}
}






