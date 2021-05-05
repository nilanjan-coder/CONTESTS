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
void solve_without_lead_trail_one (vll &a, ll i, ll j) {
	if (j < i) return;
	ll l = lg(j - i + 1) + 1, c = 0;
	vll idx;
	for (ll k = i; k <= j; k ++) {
		if (a[k] > 1) {
			idx.pb(k);
		}
	}
	ll s = sz(idx);
	if (s > l) {
		cout << a[i];
		for (ll k = i + 1; k <= j; k ++) {
			cout << "*" << a[k];
		}
	}
	else {
		ll nax = 0, reqd_mask;
		// 0 -> +		1 -> *
		for (ll mask = 0; mask < (1 << (s - 1)); mask ++) {
			ll pdt = 1, sum = 0;
			for (ll k = 0; k < s - 1; k ++) {
				if (mask & (1 << k)) {
					// *
					pdt *= a[idx[k]];
				}
				else {
					// +
					sum += (pdt * a[idx[k]] + idx[k+1] - idx[k] - 1);
					pdt = 1;
				}
			}
			sum += (pdt * a[idx[s-1]]);
			if (nax < sum) {
				nax = sum;
				reqd_mask = mask;
			}
		}
		for (ll k = 0; k < s - 1; k ++) {
			cout << a[idx[k]];
			if (reqd_mask & (1 << k)) {
				for (ll p = idx[k] + 1; p < idx[k+1]; p ++) {
					cout << "*" << 1;
				}
				cout << "*";
			}
			else {
				for (ll p = idx[k] + 1; p < idx[k+1]; p ++) {
					cout << "+" << 1;
				}
				cout << "+";
			}
		}
		cout << a[idx[s-1]];
	}
}
void solve_without_zero (vll &a, ll i, ll j) {
	if (j < i) return;
	ll i0 = i, j0 = j;
	while (a[i] == 1) {
		i ++;
		if (i == j + 1) break;
	}
	while (a[j] == 1) {
		if (j == i - 1) break;
		j --;
	}
	for (ll i1 = i0; i1 < i; i1 ++) {
		cout << 1;
		if (i1 != j0) cout << "+";
	}
	solve_without_lead_trail_one(a,i,j);
	for (ll j1 = j + 1; j1 <= j0; j1 ++) {
		cout << "+" << 1;
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
	// cin >> tc;
	while (tc --) {
		ll n;
		cin >> n;
		vll a(n);
		for (ll i = 0; i < n; i ++) {
			cin >> a[i];
		}
		string s;
		cin >> s;
		if (s == "+") {
			cout << a[0];
			for (ll i = 1; i < n; i ++) {
				cout << "+" << a[i];
			}
		}
		else if (s == "-") {
			cout << a[0];
			for (ll i = 1; i < n; i ++) {
				cout << "-" << a[i];
			}
		}
		else if (s == "*") {
			cout << a[0];
			for (ll i = 1; i < n; i ++) {
				cout << "*" << a[i];
			}
		}
		else if (s == "+-" || s == "-+") {
			cout << a[0];
			for (ll i = 1; i < n; i ++) {
				cout << "+" << a[i];
			}
		}
		else if (s == "-*" || s == "*-") {
			cout << a[0];
			ll i;
			for (i = 1; i < n && a[i] != 0; i ++) {
				cout << "*" << a[i];
			}
			if (i < n) {
				cout << "-" << a[i];
			}
			for (ll j = i+1; j < n; j ++) {
				cout << "*" << a[j];
			}
		}
		else if (s == "+*" || s == "*+" || s == "+*-" || s == "+-*" || s == "-+*"
				|| s == "*+-" || s == "*-+" || s == "-*+") {
			ll j = 0;
			for (ll i = 0; i < n; i ++) {
				if (a[i] == 0) {
					if (j <= i-1) {
						solve_without_zero(a,j,i-1);
						cout << "+";
					}
					cout << 0;
					if (i != n - 1) cout << "+";
					j = i + 1;
				}
			}
			if (j <= n-1) solve_without_zero(a,j,n-1);
		}
	}
}

