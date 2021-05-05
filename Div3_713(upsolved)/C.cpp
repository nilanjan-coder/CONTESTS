//g++ -Wall -Wextra -pedantic -std=c++17 -O2 -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_FORTIFY_SOURCE=2 -fsanitize=address -fsanitize=undefined -fno-sanitize-recover -fstack-protector
//Fast IO: Use scanf and printf
#include <bits/stdc++.h>
using namespace std;
template<typename T> long long SIZE(T (&t)){ return t.size(); } template<typename T, size_t N> long long SIZE(T (&t)[N]){ return N; } string to_string(char t){ return "'" + string({t}) + "'"; } string to_string(bool t){ return t ? "true" : "false"; } string to_string(const string &t, long long x1=0, long long x2=1e18){ string ret = ""; for(long long i = min(x1,SIZE(t)), _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += t[i]; } return '"' + ret + '"'; } string to_string(const char* t){ string ret(t); return to_string(ret); } template<size_t N> string to_string(const bitset<N> &t, long long x1=0, long long x2=1e18){ string ret = ""; for(long long i = min(x1,SIZE(t)); i <= min(x2,SIZE(t)-1); ++i){ ret += t[i] + '0'; } return to_string(ret); } template<typename T, typename... Coords> string to_string(const T (&t), long long x1=0, long long x2=1e18, Coords... C); template<typename T, typename S> string to_string(const pair<T, S> &t){ return "(" + to_string(t.first) + ", " + to_string(t.second) + ")"; } template<typename T, typename... Coords> string to_string(const T (&t), long long x1, long long x2, Coords... C){ string ret = "["; x1 = min(x1, SIZE(t)); auto e = begin(t); advance(e,x1); for(long long i = x1, _i = min(x2,SIZE(t)-1); i <= _i; ++i){ ret += to_string(*e, C...) + (i != _i ? ", " : ""); e = next(e); } return ret + "]"; } template<long long Index, typename... Ts> struct print_tuple{ string operator() (const tuple<Ts...>& t) { string ret = print_tuple<Index - 1, Ts...>{}(t); ret += (Index ? ", " : ""); return ret + to_string(get<Index>(t)); } }; template<typename... Ts> struct print_tuple<0, Ts...> { string operator() (const tuple<Ts...>& t) { return to_string(get<0>(t)); } }; template<typename... Ts> string to_string(const tuple<Ts...>& t) { const auto Size = tuple_size<tuple<Ts...>>::value; return print_tuple<Size - 1, Ts...>{}(t); } void dbgr(){;} template<typename Heads, typename... Tails> void dbgr(Heads H, Tails... T){ cout << to_string(H) << " | "; dbgr(T...); } void dbgs(){;} template<typename Heads, typename... Tails> void dbgs(Heads H, Tails... T){ cout << H << " "; dbgs(T...); } 
#define dbgv(...) cout << to_string(__VA_ARGS__) << endl;
#define dbg(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgv(__VA_ARGS__);
#define dbgr(...) dbgr(__VA_ARGS__); cout << endl;
#define dbgm(...) cout << "[" << #__VA_ARGS__ << "]: "; dbgr(__VA_ARGS__);
void solve() {
	int a, b;
	cin >> a >> b;
	string s;
	cin >> s;
	int i = 0, j = a + b - 1;
	while (i < j) {
		if (s[i] == '?' && s[j] != '?') {
			s[i] = s[j];
		}
		else if (s[i] != '?' && s[j] == '?') {
			s[j] = s[i];
		}
		i ++;
		j --;
	}
	int c0 = 0, c1 = 0;
	for (int k = 0; k < a + b; k ++) {
		if (s[k] == '0') {
			c0 ++;
		}
		else if (s[k] == '1') {
			c1 ++;
		}
	}
	if (c0 > a || c1 > b) {
		cout << -1 << endl;
		return;
	}
	i = 0, j = a + b - 1;
	c0 = a - c0;
	c1 = b - c1;
	while (i < j) {
		if (s[i] == '?') {
			if (c0 >= 2) {
				s[i] = s[j] = '0';
				c0 -= 2;
			}
			else if (c1 >= 2) {
				s[i] = s[j] = '1';
				c1 -= 2;
			}
			else {
				cout << -1 << endl;
				return;
			}
		}
		i ++;
		j --;
	}
	if (i == j) {
		if (s[i] == '?') {
			if (c0 >= 1) {
				s[i] = '0';
				c0 --;
			}
			else if (c1 >= 1) {
				s[i] = '1';
				c1 --;
			}
			else {
				cout << -1 << endl;
				return;
			}
		}
	}
	if (c0 + c1) {
		cout << -1 << endl;
		return;
	}
	i = 0, j = a + b - 1;
	while (i < j) {
		if (s[i] != s[j]) {
			cout << -1 << endl;
			return;
		}
		i ++;
		j --;
	}
	cout << s << endl;
}
int main() {
	int t;
	cin >> t;
	while (t --) {
		solve();
	}
}