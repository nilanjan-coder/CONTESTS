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
#define len(s) s.length()
#define sz(v) v.size()
#define pi M_PI
#define e M_E
#define LOG(x) log10(x)
#define lg(x) log2(x)
#define ln(x) log(x)
#define up(x) ceil(x)
#define dn(x) floor(x)
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
void dfs (vvll &g, ll u, ll p, vll &h) {
	h[u] = 0;
	vll sto;
	for (ll v: g[u]) {
		if (v - p) {
			dfs(g,v,u,h);
			sto.pb(h[v] + ((sz(g[v]) > 2) ? 0 : 1));
			ll nax = 0, cnt = 0;
			for (ll val: sto) {
				if (nax < val) {
					nax = val;
					cnt = 1;
				}
				else if (nax == val) {
					cnt ++;
				}
			}
			h[u] = nax + ((cnt > 1) ? 1 : 0);
		}
	}
}
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
		vvll g(n+1);
		for (ll i = 1; i < n; i ++) {
			ll u, v;
			cin >> u >> v;
			g[u].pb(v);
			g[v].pb(u);
		}
		vll h(n+1);
		dfs(g,1,0,h);
		cout << h[1] << "\n";
	}
}

