#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int n, sum = 0;
	scanf ("%d", &n);
	int a[n];
	string b = "";
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a[i]);
	}
	for (int i = 0; i < n; i ++) {
		if (i == 0 || i == n-1) {
			b += '#';
		}
		else {
			if (a[i] > a[i-1] && a[i] > a[i+1]) {
				b += 'h';
				sum ++;
			}
			else if (a[i] < a[i-1] && a[i] < a[i+1]) {
				b += 'v';
				sum ++;
			}
			else {
				b += '#';
			}
		}
	}
	for (int i = 0; i < n - 2; i ++) {
		string c = b.substr(i, 3);
		if (c == "hvh" || c == "vhv") {
			printf ("%d\n", sum - 3);
			return;
		}
	}
	for (int i = 0; i < n - 3; i ++) {
		string c = b.substr(i, 4);
		if (c == "#hv#" || c == "#vh#") {
			if (i == 0 || (i > 0 && a[i] == a[i-1]) || i + 3 == n - 1 || (i + 3 < n - 1 && a[i+3] == a[i+4])) {
				printf ("%d\n", sum - 2);
				return;
			}
			else if (c == "#hv#" && (a[i+2] >= a[i] || a[i+3] >= a[i+1])) {
				printf ("%d\n", sum - 2);
				return;
			}
			else if (c == "#vh#" && (a[i+2] <= a[i] || a[i+3] <= a[i+1])) {
				printf ("%d\n", sum - 2);
				return;
			}	
		}
	}
	printf ("%d\n", max (0, sum - 1));
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}