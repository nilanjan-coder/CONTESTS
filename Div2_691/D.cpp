#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const int MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e9 + 5;
const ld ERR = 1e-10;
bool comp (pair <ld, ld> p1, pair <ld, ld> p2) {
	if (p1.second == p2.second) return  p1.first < p2.first;
	return p1.second < p2.second;
}
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int tc = 1;
	// cin >> tc;
	while (tc --) {
		int n;
		cin >> n;
		pair <ld, ld> ab[n+1];
		for (int i = 1; i <= n; i ++) {
			cin >> ab[i].first >> ab[i].second;
		}
		sort (ab+1, ab+n+1, comp);
		ld k[n+1];
		for (int i = n; i >= 1; i --) {
			// n-i+1..n taken, 1..n-i left
			k[i] = 0;
			vector <ld> diff, fill;
			for (int j = n-i+1; j <= n; j ++) {
				k[i] += ab[j].second;
				if (ab[j].first > ab[j].second) diff.push_back(ab[j].first - ab[j].second);
			}
			for (int j = 1; j <= n-i; j ++) {
				fill.push_back(ab[j].second);
			}
			while (true) {
				if (fill.empty() || diff.empty()) break;
				sort (fill.begin(), fill.end());
				sort (diff.begin(), diff.end());
				ld add = min (fill.back() / 2, diff.back());
				fill.back() -= (2 * add);
				diff.back() -= add;
				k[i] += add;
				if (fill.back() == 0) fill.pop_back();
				if (diff.back() == 0) diff.pop_back();
			}
			
		}
		for (int i = 1; i <= n; i ++) {
			cout << fixed << setprecision(10) << k[i] << " ";
		}
	}
}







