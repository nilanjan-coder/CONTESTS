#include <bits/stdc++.h>
using namespace std;
string read (int n) {
	char s[n+1];
	scanf ("%s", s);
	return string(s);
}
int main() {
	int n, nax = -1;
	scanf ("%d", &n);
	string s = read(n);
	int color[n];
	multiset <char> sorted;
	int last_idx[26], last[26];
	for (int i = 0; i < 26; i ++) {
		last_idx[i] = last[i] = -2;
	}
	for (int i = 0; i < n; i ++) {
		int j = -1;
		for (j = s[i] - 'a' - 1; j >= 0; j --) {
			if (last[j] != -2) {
				break;
			}
		}
		j = (j == -1) ? 0 : (last[j] + 1);
		if (last[s[i] - 'a'] == -2) last[s[i] - 'a'] = j - 1;
		for (j = s[i] - 'a'; j < 26; j ++) {
			if (last[j] != -2) {
				last[j] ++;
			}
		}
		j = last[s[i] - 'a'];
		if (j == (int)sorted.size()) {
			color[i] = 0;
		}
		else {
			for (int k = 25; k >= 0; k --) {
				if (last_idx[k] >= j) {
					color[i] = k + 1;
					for (int l = k; l >= 0; l --) {
						last_idx[l] ++;
					}
					break;
				}
			}
		}
		last_idx[color[i]] = j;
		sorted.insert(s[i]);
		nax = max (nax, color[i]);
	}
	printf ("%d\n", nax + 1);
	for (int i = 0; i < n; i ++) {
		printf ("%d ", color[i] + 1);
	}
}