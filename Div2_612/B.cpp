#include <bits/stdc++.h>
using namespace std;
string read (int k) {
	char s[k+1];
	scanf ("%s", s);
	return string(s);
}
void test_case() {
	int n, k;
	scanf ("%d%d", &n, &k);
	string s[n];
	for (int i = 0; i < n; i ++) {
		s[i] = read(k);
	}
	sort (s, s+n);
	long long cnt = 0;
	for (int i = 0; i < n; i ++) {
		for (int j = i + 1; j < n; j ++) {
			string t = "";
			for (int idx = 0; idx < k; idx ++) {
				if (s[i][idx] == s[j][idx]) t += s[i][idx];
				else {
					string r = "";
					r += s[i][idx];
					r += s[j][idx];
					sort (r.begin(), r.end());
					if (r == "ES") t += 'T';
					else if (r == "ST") t += 'E';
					else if (r == "ET") t += 'S';
				}
			}
			int idx = lower_bound (s+j+1, s+n, t) - s;
			if (idx == n) continue;
			else if (s[idx] != t) continue;
			else {
				int idx2 = upper_bound (s+j+1, s+n, t) - s;
				cnt += (long long)(idx2 - idx);
			}
		}
	}
	printf ("%lld", cnt);
}
int main() {
	int T = 1;
	//scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}