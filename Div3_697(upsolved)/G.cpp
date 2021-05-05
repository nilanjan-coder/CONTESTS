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
vector <int> cnt (200001), dp(200001);
int keep (int i) {
	if (dp[i] != -1) return dp[i];
	int nax = 0;
	for (int j = 2; j * i <= 200000; j ++) {
		if (cnt[j * i] == 0) continue;
		nax = max (nax, keep(j * i));
	}
	dp[i] = nax + cnt[i];
	return dp[i];
}
int main() {
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		for (int i = 1; i <= 200000; i ++) {
			cnt[i] = 0;
			dp[i] = -1;
		}
		int n;
		scanf ("%d", &n);
		vector <int> a(n);
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &a[i]);
			cnt[a[i]] ++;
		}
		int nax = 0;
		for (int i = 1; i <= 200000; i ++) {
			if (cnt[i] == 0) continue;
			nax = max (nax, keep(i));
		}
		printf ("%d\n", n - nax);
	}
}