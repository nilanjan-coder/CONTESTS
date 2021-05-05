#include <bits/stdc++.h>
using namespace std;
struct cmp {
	bool operator() (pair <int, int> p1, pair <int, int> p2) {
		return (p1.second - p1.first == p2.second - p2.first) ? (p1.first > p2.first) : 
				(p1.second - p1.first < p2.second - p2.first);
	}
};
void test_case() {
	int n;
	scanf ("%d", &n);
	int a[n + 1];
	priority_queue <pair <int, int>, vector <pair <int, int>>, cmp> b;
	b.push(make_pair(1, n));
	for (int i = 1; i <= n; i ++) {
		pair <int, int> seg = b.top();
		int idx;
		if ((seg.second - seg.first + 1) & 1) {
			idx = (seg.first + seg.second) / 2;
		}
		else {
			idx = (seg.first + seg.second - 1) / 2;
		}
		a[idx] = i;
		b.pop();
		if (seg.first != idx) {
			b.push(make_pair(seg.first, idx - 1));
		}
		if (seg.second != idx) {
			b.push(make_pair(idx + 1, seg.second));
		}
	}
	for (int i = 1; i <= n; i ++) {
		printf ("%d ", a[i]);
	}
	printf ("\n");
}
int main() {
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}