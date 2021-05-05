#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
using ll = long long;
int main() {
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		int n;
		ll m;
		scanf ("%d%lld", &n, &m);
		vector <ll> a(n);
		vector <int> b(n);
		for (int i = 0; i < n; i ++) {
			scanf ("%lld", &a[i]);
		}
		vector <ll> a1, a2;
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &b[i]);
			if (b[i] == 1) {
				a1.push_back(a[i]);
			}
			else {
				a2.push_back(a[i]);
			}
		}
		sort (a1.begin(), a1.end(), greater <ll> ());
		sort (a2.begin(), a2.end(), greater <ll> ());
		int p = a1.size(), q = a2.size();
		for (int i = 1; i < p; i ++) {
			a1[i] += a1[i - 1];
		}
		for (int i = 1; i < q; i ++) {
			a2[i] += a2[i - 1];
		}
		int nin = 2 * n + 1;
		for (int i = -1; i < p; i ++) {
			ll res = m - ((i == -1) ? 0 : a1[i]);
			if (res <= 0) {
				nin = min (nin, i + 1);
				break;
			}
			else {
				int j = lower_bound (a2.begin(), a2.end(), res) - a2.begin();
				if (j == q) continue;
				nin = min (nin, i + 1 + 2 * (j + 1));
			}
		}
		printf ("%d\n", (nin == 2 * n + 1) ? -1 : nin);
	}
}