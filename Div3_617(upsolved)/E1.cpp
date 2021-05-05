#include <bits/stdc++.h>
using namespace std;
string read (int n) {
	char s[n+1];
	scanf ("%s", s);
	return string(s);
}
int main() {
	int n;
	scanf ("%d", &n);
	string s = read(n);
	int c[n], color[n];
	for (int i = 0; i < n; i ++) {
		if (i == 0) {
			c[i] = color[i] = 0;
		}
		else {
			if (s[i] >= s[i-1]) {
				c[i] = color[i] = 0;
			}
			else {
				c[i] = color[i] = 1;
				for (int j = i; j >= 1; j --) {
					if (s[j] < s[j-1]) {
						if (c[j] != c[j-1]) {
							swap (c[j], c[j-1]);
							swap (s[j], s[j-1]);
						}
						else {
							printf ("NO");
							return 0;
						}
					}
				}
			}
		}
	}
	printf ("YES\n");
	for (int i = 0; i < n; i ++) {
		printf ("%d", color[i]);
	}
}