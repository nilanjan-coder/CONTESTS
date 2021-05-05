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
		vll a(n);
		vll b, c;
		for (ll i = 0; i < n; i ++) {
			cin >> a[i];
		}
		ll s = 0;
		for (ll i = 1; i < n; i ++) {
			b.pb(abs(a[i]-a[i-1]));
			s += b.back();
		}
		for (ll i = 2; i < n; i ++) {
			c.pb(abs(a[i]-a[i-2]));
		}
		ll deduct = 0;
		for (ll i = 1; i < n-1; i ++) {
			deduct = max (deduct, b[i]+b[i-1]-c[i-1]);
		}
		deduct = max (deduct, max(b[0],b[n-2]));
		s -= deduct;
		cout << s << "\n";
	}
}



