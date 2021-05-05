//g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
//Fast IO: Use scanf and printf
#include <bits/stdc++.h>
using namespace std;
template<typename T> long long SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> long long SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, long long x1=0, long long x2=1e18){ string ret = ""; for(long long i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, long long x1=0, long long x2=1e18){ string ret = ""; for(long long i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), long long x1=0, long long x2=1e18, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), long long x1, long long x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(long long i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<long long Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
long long INF = 1e9 + 7;
struct segtree {
	vector <long long> a;
	long long s = 1;
	void init (long long n) {
		while (s < n) s *= 2;
		a.assign (2 * s, INF);
	}
	void update (long long i, long long v, long long x, long long lx, long long rx) {
		if (rx - lx == 1) {
			a[x] = v;
			return;
		}
		long long mx = (lx + rx) / 2;
		if (i < mx) update (i, v, 2 * x + 1, lx, mx);
		else update (i, v, 2 * x + 2, mx, rx);
		a[x] = min (a[2 * x + 1], a[2 * x + 2]);
	}
	void update (long long i, long long v) {
		update (i, v, 0, 0, s);
	}
	long long query (long long l, long long r, long long x, long long lx, long long rx) {
		if (l >= rx || r <= lx) return INF;
		else if (lx >= l && rx <= r) return a[x];
		else {
			long long mx = (lx + rx) / 2;
			return min (query (l, r, 2 * x + 1, lx, mx), query (l, r, 2 * x + 2, mx, rx));
		}
	}
	long long query (long long l, long long r) {
		return query (l, r, 0, 0, s);
	}
};
void solve() {
	long long n, p;
	scanf ("%lld%lld", &n, &p);
	segtree st;
	st.init(n);
	vector <long long> a(n);
	for (long long i = 0; i < n; i ++) {
		scanf ("%lld", &a[i]);
		st.update (i, a[i]);
	}
	vector <vector <pair <long long, long long>>> b(n);
	for (long long i = n - 1; i >= 0; i --) {
		if (i == n - 1) {
			b[i].push_back(make_pair(a[i], 1));
		}
		else {
			b[i].push_back(make_pair(a[i], 1));
			for (pair <long long, long long> x: b[i + 1]) {
				pair <long long, long long> y = make_pair(__gcd(x.first, a[i]), x.second);
				pair <long long, long long> z = b[i].back();
				if (y.first == z.first) {
					b[i].pop_back();
					b[i].push_back(make_pair(z.first, z.second + y.second));
				}
				else {
					b[i].push_back(y);
				}
			}
		}
	}
	dbg(b);
	vector <long long> dp(n);
	for (int i = 0; i < n; i ++) {
		dp[i] = (n - 1 - i) * p;
	}
	dbg(dp[n - 1]);
	for (long long i = n - 2; i >= 0; i --) {
		long long idx = i;
		for (pair <long long, long long> x: b[i]) {
			idx += x.second;
			if (idx == i + 1) continue;
			if (x.first == st.query(i, idx)) {
				dp[i] = min (dp[i], x.first + dp[idx - 1]);
			}
		}
		dbg(dp[i]);
	}
	printf ("%lld\n", dp[0]);
}
int main() {
	int t;
	scanf ("%d", &t);
	while (t --) {
		solve();
	}
}