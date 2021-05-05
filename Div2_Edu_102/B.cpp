#include <bits/stdc++.h>
using namespace std;
string read() {
	char s[21];
	scanf ("%s", s);
	return string(s);
}
int is_repeat (string r, string s) {
	if ((int)s.length() % (int)r.length()) {
		return -1;
	}
	else {
		int cnt = 0;
		for (int i = 0; i < (int)s.length(); i += (int)r.length()) {
			if (s.substr (i, (int)r.length()) != r) {
				return -1;
			}
			else {
				cnt ++;
			}
		}
		return cnt;
	}
}
string repeat (string r, int n) {
	string p = "";
	while (n --) {
		p += r;
	}
	return p;
}
int lcm (int a, int b) {
	return (a * b) / __gcd (a, b);
}
void test_case() {
	string s = read(), t = read();
	if ((int)t.length() < (int)s.length()) {
		swap (s, t);
	}
	for (int i = 0; i < (int)s.length(); i ++) {
		string r = s.substr (0, i + 1);
		int ns = is_repeat (r, s), nt = is_repeat (r, t);
		if (ns != -1 && nt != -1) {
			printf ("%s\n", repeat(r, lcm (ns, nt)).c_str());
			return;
		}
	}
	printf ("-1\n");
}
int main() {
	int q = 1;
	scanf ("%d", &q);
	while (q --) {
		test_case();
	}
}