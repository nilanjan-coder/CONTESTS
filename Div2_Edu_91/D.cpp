#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define B begin()
#define E end()
#define ins insert
#define del erase
#define pb push_back
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(v) v.B,v.E
#define len(s) (ll)s.length()
#define sz(v) (ll)v.size()
#define clr(v) v.clear()
#define LOG(x) log10(x)
#define lg(x) log2(x)
#define ln(x) log(x)
#define up(x) ceil(x)
#define dn(x) floor(x)
#define bp(x) __builtin_popcountll(x)
#define bl(x) __builtin_clz(x)
#define bt(x) __builtin_ctz(x);
using ll = long long;
using ld = long double;
using pll = pair <ll, ll>;
using pld = pair <ld, ld>;
using plc = pair <ll, char>;
using vll = vector <ll>;
using vld = vector <ld>;
using vvll = vector <vll>;
using vvld = vector <vld>;
using vpll = vector <pll>;
using vpld = vector <pld>;
using vplc = vector <plc>;
using vs = vector <string>;
using vb = vector <bool>;
using vvb = vector <vb>;
using vc = vector <char>;
using vvc = vector <vc>;
using mll = map <ll, ll>;
using sll = set <ll>;
const ll MOD = 1e9 + 7, LIM = 1e6 + 5, INF = 1e18 + 5;
const ld ERR = 1e-9;
int main () {
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ll tc = 1;
	// cin >> tc;
	while (tc --) {
		ll n, m, x, k, y;
		cin >> n >> m >> x >> k >> y;
		vll a(n), b(m), idx(n+1);
		for (ll i = 0; i < n; i ++) {
			cin >> a[i];
			idx[a[i]] = i;
		}
		for (ll i = 0; i < m; i ++) {
			cin >> b[i];
		}
		for (ll i = 1; i < m; i ++) {
			if (idx[b[i]] <= idx[b[i-1]]) {
				cout << -1;
				return 0;
			}
		}
		ll cost = 0, i1, i2;
		for (ll i = 0; i <= m; i ++) {
			if (i == 0) {
				i1 = -1;
				i2 = idx[b[i]];
			}
			else if (i == m) {
				i1 = idx[b[i-1]];
				i2 = n;
			}
			else {
				i1 = idx[b[i-1]];
				i2 = idx[b[i]];
			}
			ll rng = i2 - i1 - 1;
			ll val = max((i1 == -1) ? 0 : a[i1], (i2 == n) ? 0 : a[i2]);
			bool f = false;
			for (ll j = i1 + 1; j <= i2 - 1; j ++) {
				if (a[j] > val) {
					f = true;
					break;
				}
			}
			ll nin = INF;
			if (f) {
				// at least 1 x
				if (rng < k) {
					cout << -1;
					return 0;
				}
				nin = min((rng - k) * y + x, (rng / k) * x + (rng % k) * y);
			}
			else {
				nin = min((rng / k) * x + (rng % k) * y, rng * y);
			}
			cost += nin;
		}
		cout << cost;
	}
}
