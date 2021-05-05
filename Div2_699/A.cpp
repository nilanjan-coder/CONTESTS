#include <bits/stdc++.h>
using namespace std;
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
string read() {
	char s[100001];
	scanf ("%s", s);
	return string(s);
}
void test_case() {
	int n, m;
	scanf ("%d%d", &n, &m);
	vector <int> a(n), b(n), c(m);
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &a[i]);
	}
	for (int i = 0; i < n; i ++) {
		scanf ("%d", &b[i]);
	}
	for (int i = 0; i < m; i ++) {
		scanf ("%d", &c[i]);
	}
	set <int> equal;
	vector <set <int>> idx(n + 1);
	for (int i = 0; i < n; i ++) {
		if (a[i] == b[i]) {
			equal.insert(i);
		}
		else {
			idx[b[i]].insert(i);
		}
	}
	set <int> store;
	for (int i = 0; i < m; i ++) {
		if (idx[c[i]].empty()) {
			store.push_back(c[i]);
		}
	}
}
int main() {
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif
	int T = 1;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}