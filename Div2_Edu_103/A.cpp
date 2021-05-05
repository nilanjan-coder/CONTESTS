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
int main() {
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		int n;
		scanf ("%d", &n);
		long long c[n], a[n], b[n];
		for (int i = 0; i < n ; i ++) {
			scanf ("%lld", &c[i]);
		}
		for (int i = 0; i < n ; i ++) {
			scanf ("%lld", &a[i]);
		}
		for (int i = 0; i < n ; i ++) {
			scanf ("%lld", &b[i]);
		}
		long long dp[n], nax = 0;
		dp[0] = 0;
		vector <int> idx;
		for (int i = 1; i < n; i ++) {
			dp[i] = c[i] + 1;
			if (i > 1 && a[i] != b[i]) {
				dp[i] += (dp[i - 1] - abs(a[i] - b[i]));
			}
			else {
				dp[i] += abs(a[i] - b[i]);
				idx.push_back(i - 1);
			}
		}
		idx.push_back(n - 1);
		debug(idx);
		for (int i = 1; i < (int)idx.size(); i ++) {
			vector <long long> nin(idx[i] - idx[i - 1] + 1);
			nin[0] = 100000000;
			for (int j = 1; j <= idx[i] - idx[i - 1]; j ++) {
				nin[j] = min (nin[j - 1], dp[idx[i - 1] + j]);
			}
			for (int j = idx[i]; j >= idx[i - 1] + 1; j --) {
				nax = max (nax, dp[j] - nin[j - idx[i - 1]]);
			}
		}
		printf ("%lld\n", nax);
	}	
}