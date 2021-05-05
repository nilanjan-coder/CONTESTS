#include <bits/stdc++.h>
using namespace std;
struct Person {
	int ht, wt, idx;
};
bool comp (Person a, Person b) {
	if (a.ht == b.ht && a.wt == b.wt) return a.idx < b.idx;
	else if (a.ht == b.ht) return a.wt < b.wt;
	else return a.ht < b.ht;
}
void test_case() {
	int n;
	scanf ("%d", &n);
	int h[n], w[n];
	vector <Person> hwi;
	for (int i = 0; i < n; i ++) {
		scanf ("%d%d", &h[i], &w[i]);
		hwi.push_back({h[i], w[i], i});
		hwi.push_back({w[i], h[i], i});
	}
	sort (hwi.begin(), hwi.end(), comp);
	int index[n];
	for (int i = 0; i < n; i ++) {
		index[i] = -2;
	}
	int m = hwi.size();
	Person nin[m];
	for (int i = 0; i < m; i ++) {
		if (i == 0) nin[i] = hwi[i];
		else {
			if (nin[i-1].wt <= hwi[i].wt) nin[i] = nin[i-1];
			else nin[i] = hwi[i];
		}
	}
	for (int i = 0; i < m; i ++) {
		if (index[hwi[i].idx] == -2) {
			int start = 0, end = m - 1;
			while (start <= end) {
				int mid = (start + end) / 2;
				if (hwi[mid].ht >= hwi[i].ht) end = mid - 1;
				else start = mid + 1;
			}
			if (end != -1) {
				if (nin[end].wt < hwi[i].wt) {
					index[hwi[i].idx] = nin[end].idx;
				}
			}
		}
	}
	for (int i = 0; i < n; i ++) {
		printf ("%d ", index[i] + 1);
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
