#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define B begin()
#define E end()
#define in insert
#define er erase
#define rs resize
#define un unique
#define pb push_back
#define pf push_front
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define pob(v) v.pop_back()
#define pof(v) v.pop_front()
#define all(v) v.B,v.E
#define len(s) (ll)s.length()
#define sz(v) (ll)v.size()
#define clr(v) v.clear()
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
using vvvll = vector <vvll>;
using vvld = vector <vld>;
using vpll = vector <pll>;
using vpld = vector <pld>;
using vplc = vector <plc>;
using vvpll = vector <vpll>;
using vvvpll = vector <vvpll>;
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
	cin >> tc;
	while (tc --) {
		ll n;
		cin >> n;
		vll t(n), x(n);
		ll c = 0;
		for (ll i = 0; i < n; i ++) {
			cin >> t[i] >> x[i];
		}
		for (ll i = 0; i < n-1; i ++) {
			if (t[i+1] - t[i] >= abs(x[i] - 0)) c ++;
		}
		cout << c << "\n";
	}
}


