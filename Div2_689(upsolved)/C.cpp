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
using pld = pair <ll, ld>;
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
bool comp (pld p1, pld p2) {
	return p1.F < p2.F;
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
		ll n, m;
		cin >> n >> m;
		vll a(n+1);
		for (ll i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		vll nax(n+1);
		nax[0] = 0;
		for (ll i = 1; i <= n; i ++) {
			nax[i] = max (nax[i-1], a[i]);
		}
		ll j = 1;
		for (ll i = n; i >= 1; i --) {
			if (a[i] - i) {
				j = i+1;
				break;
			}
		}
		vpld b(m);
		for (ll i = 0; i < m; i ++) {
			cin >> b[i].F >> b[i].S;
		}
		if (j == 1) {
			cout << 1 << "\n";
			continue;
		}
		sort(all(b),comp);
		ld p = 1, s = 0;
		for (ll i = 0; i < m; i ++) {
			if (nax[b[i].F] - b[i].F) continue;
			else if (b[i].F < j-1) continue;
			else {
				s += (p * b[i].S);
				p *= (1 - b[i].S);
			}
		}
		cout << fixed << setprecision(7) << s << "\n";
	}
}


 
