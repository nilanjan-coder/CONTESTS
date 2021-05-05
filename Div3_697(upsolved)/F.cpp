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
int main() {
	#ifndef ONLINE_JUDGE
        freopen ("in.txt", "r", stdin);
        freopen ("out.txt", "w", stdout);
    #endif
	int t = 1;
	scanf ("%d", &t);
	while (t --) {
		int n;
		scanf ("%d", &n);
		vector <vector <char>> a(n, vector <char> (n)), b(n, vector <char> (n));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				scanf (" %c", &a[i][j]);
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				scanf (" %c", &b[i][j]);
			}
		}
		debug(a, b);
		bool ans = true;
		for (int i = 0; i < n; i ++) {
			if (i == 0) {
				bool hxor = false;
				for (int j = 0; j < n; j ++) {
					if (a[i][j] != b[i][j]) {
						hxor = true;
						break;
					}
				}
				if (hxor) {
					for (int j = 0; j < n; j ++) {
						a[i][j] = (a[i][j] == '0') ? '1' : '0';
					}
					for (int j = 0; j < n; j ++) {
						if (a[i][j] != b[i][j]) {
							for (int k = 0; k < n; k ++) {
								a[k][j] = (a[k][j] == '0') ? '1' : '0';
							}
						}
					}
				}
			}
			else {
				int ceq = 0, cneq = 0;
				for (int j = 0; j < n; j ++) {
					if (a[i][j] != b[i][j]) {
						cneq ++;
					}
					else {
						ceq ++;
					}
				}
				if (ceq != 0 && cneq != 0) {
					ans = false;
					break;
				}
			}
		}
		if (ans) printf ("YES\n");
		else printf ("NO\n");
	}
}