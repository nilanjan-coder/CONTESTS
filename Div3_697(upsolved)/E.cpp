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
ll MOD = 1e9 + 7;
ll mul (ll x, ll y) {
	return ((x % MOD) * (y % MOD)) % MOD;
}
vector <ll> fact(1001);
ll power (ll x, ll y) {
	if (y == 0) return 1;
	ll r = power(x, y / 2);
	r = mul(r, r);
	if (y & 1) r = mul(r, x);
	return r;
}
ll invmod (ll n) {
	return power(n, MOD - 2);
}
ll ncr (ll n, ll r) {
	if (n < r) return 0;
	if (r == 0) return 1;
	return mul(fact[n], mul(invmod(fact[r]), invmod(fact[n - r])));
}
int main() {
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif
    fact[0] = 1;
    for (int i = 1; i <= 1000; i ++) {
    	fact[i] = mul(i, fact[i - 1]);
    }
    //debug(fact);
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		int n, k;
		scanf ("%d%d", &n, &k);
		vector <int> a(n);
		for (int i = 0; i < n; i ++) {
			scanf ("%d", &a[i]);
		}
		sort (a.begin(), a.end(), greater <int> ());
		debug(a);
		int val = a[k - 1], pos;
		for (int i = 0; i < n; i ++) {
			if (a[i] == val) {
				pos = i;
				break;
			}
		}
		int cnt = k - pos, c = 0;
		for (int i = 0; i < n; i ++) {
			if (a[i] == val) {
				c ++;
			}
		}
		debug(c, cnt);
		printf ("%lld\n", ncr((ll)c, (ll)cnt));
	}
}