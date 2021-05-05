#include <bits/stdc++.h>
using namespace std;
int INF = 1e9;
string read (int n) {
	char s[n+1];
	scanf ("%s", s);
	return string(s);
}
void test_case() {
	int n;
	scanf ("%d", &n);
	string s = read(n);
	s = '#' + s;
	map <pair <int, int>, vector <int>> points;
	points[{0,0}].push_back(0);
	int x = 0, y = 0;
	for (int i = 1; i < (int)s.length(); i ++) {
		if (s[i] == 'L') x --;
		else if (s[i] == 'R') x ++;
		else if (s[i] == 'U') y ++;
		else if (s[i] == 'D') y --;
		points[{x,y}].push_back(i);
	}
	int nin = INF, left = -1, right = -1;
	for (auto p: points) {
		if ((int)p.second.size() == 1) continue;
		for (int i = 1; i < (int)p.second.size(); i ++) {
			if (nin > p.second[i] - p.second[i-1]) {
				nin = p.second[i] - p.second[i-1];
				left = p.second[i-1] + 1;
				right = p.second[i];
			}
		}
	}
	if (nin == INF) {
		printf ("-1\n");
	}
	else {
		printf ("%d %d\n", left, right);
	}
}
int main() {
	int T;
	scanf ("%d", &T);
	while (T --) {
		test_case();
	}
}