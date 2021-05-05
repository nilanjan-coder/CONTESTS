#include <bits/stdc++.h>
using namespace std;
void test_case() {
	long long n;
	scanf ("%lld", &n);
	long long a[n];
	vector <long long> even, odd;
	for (long long i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
		if (a[i] & 1) odd.push_back(a[i]);
		else even.push_back(a[i]);
	}
	sort(even.begin(), even.end());
	sort(odd.begin(), odd.end());
	long long alice = 0, bob = 0, turn = 0;
	while ((long long)even.size() > 0 && (long long)odd.size() > 0) {
		if (turn & 1) {
			if (odd.back() > even.back()) {
				bob += odd.back();
				odd.pop_back();
			}
			else {
				even.pop_back();
			}
		}
		else {
			if (even.back() > odd.back()) {
				alice += even.back();
				even.pop_back();
			}
			else {
				odd.pop_back();
			}
		}
		turn ++;
	}
	while ((long long)even.size() > 0) {
		if (turn & 1) {
			even.pop_back();
		}
		else {
			alice += even.back();
			even.pop_back();
		}
		turn ++;
	}
	while ((long long)odd.size() > 0) {
		if (turn & 1) {
			bob += odd.back();
			odd.pop_back();
		}
		else {
			odd.pop_back();
		}
		turn ++;
	}
	if (alice > bob) printf ("Alice\n");
	else if (alice < bob) printf ("Bob\n");
	else printf ("Tie\n");
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}
