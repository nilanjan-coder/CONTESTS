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
const ll MOD = 1e9 + 7, LIM = 2e5 + 5, INF = 1e18 + 5;
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
	cin >> tc;
	while (tc --) {
		ll n;
		cin >> n;
		vll l(n), r(n), lt(n), rt(n);
		for (ll i = 0; i < n; i ++) {
			cin >> l[i] >> r[i];
			lt[i] = l[i];
			rt[i] = r[i];
		}
		sort(all(lt));
		sort(all(rt));
		ll nin = INF;
		for (ll i = 0; i < n; i ++) {
			ll idx = ub(all(lt), r[i]) - lt.B;
			ll c1 = n - idx;
			idx = lb(all(rt), l[i]) - rt.B;
			ll c2 = idx;
			nin = min(nin, c1+c2);
		}
		cout << nin << "\n";
	}
}


