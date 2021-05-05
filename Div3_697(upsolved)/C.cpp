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
		int a, b, k;
		scanf ("%d%d%d", &a, &b, &k);
		vector <int> va(k), vb(k);
		map <int, int> na, nb;
		map <pair <int, int>, int> nc;
		for (int i = 0; i < k; i ++) {
			scanf ("%d", &va[i]);
		}
		for (int i = 0; i < k; i ++) {
			scanf ("%d", &vb[i]);
		}
		for (int i = 0; i < k; i ++) {
			na[va[i]] ++;
			nb[vb[i]] ++;
			nc[make_pair(va[i], vb[i])] ++;
		}
		long long ans = 0;
		for (int i = 0; i < k; i ++) {
			ans += (long long)(k - na[va[i]] - nb[vb[i]] + nc[make_pair(va[i], vb[i])]);
		}
		debug(na, nb, nc);
		printf ("%lld\n", ans / 2);
	}
}