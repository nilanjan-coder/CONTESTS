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
		vvc a(n+1, vc(n+1));
		vll min_x(10, n+1), max_x(10, 0), min_y(10, n+1), max_y(10, 0), b(10, 0);
		for (ll i = 1; i <= n; i ++) {
			for (ll j = 1; j <= n; j ++) {
				cin >> a[i][j];
				ll d = a[i][j] - '0';
				min_x[d] = min (min_x[d], i);
				max_x[d] = max (max_x[d], i);
				min_y[d] = min (min_y[d], j);
				max_y[d] = max (max_y[d], j);
			}
		}
		for (ll i = 1; i <= n; i ++) {
			for (ll j = 1; j <= n; j ++) {
				ll d = a[i][j] - '0';
				b[d] = max(b[d], max(max(i-1, n-i) * max(max_y[d]-j, j-min_y[d]),
								 max(j-1, n-j) * max(max_x[d]-i, i-min_x[d])));
			}
		}
		for (ll d = 0; d < 10; d ++) {
			cout << b[d] << " ";
		}
		cout << "\n";
	}
}
