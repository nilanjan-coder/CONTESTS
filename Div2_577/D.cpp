#include <bits/stdc++.h>
using namespace std;
bool comp (pair <long long, long long> p1, pair <long long, long long> p2) {
	return (p1.first == p2.first) ? (p1.second > p2.second) : (p1.first < p2.first);
}
int main () {
	int N;
	scanf ("%d", &N);
	long long C, ans = 0, lim = 0;
	scanf ("%lld", &C);
	long long a[N], b[N], c[N];
	pair <long long, long long> interval[N];
	for (int i = 0 ; i < N; i ++) {
		scanf ("%lld%lld%lld", &a[i], &b[i], &c[i]);
		interval[i] = make_pair (a[i], b[i]);
	}
	sort (interval, interval + N, comp);
	vector <vector <int>> disjoint;
	for (int i = 0; i < N; i ++) {
		if (disjoint.empty()) {
			disjoint.push_back({a[i], b[i], c[i]});
		}
		else {
			int start = 0, end = (int)disjoint.size() - 1;
			while (start <= end) {
				int mid = start + (end - start) / 2;
				if (disjoint[mid][1] > a[i]) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			int j = start;
			
	printf ("%lld", ans);
}