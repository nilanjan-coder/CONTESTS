#include <bits/stdc++.h>
using namespace std;
void test_case() {
	int s, buries = 0;
	scanf ("%d", &s);
	while (s >= 10) {
		buries += (s - s % 10);
		s = s / 10 + s % 10;
	}
	printf ("%d\n", buries + s);
}
int main() {
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}