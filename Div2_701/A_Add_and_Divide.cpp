#include <bits/stdc++.h>
using namespace std;
void test_case() {
    int a, b;
    scanf ("%d%d", &a, &b);
    int ans = 100;
    for (int i = b; i <= b + 35; i ++) {
        if (i == 1) {
            continue;
        }
        int j = a, op = 0;
        while (j) {
            j /= i;
            op ++;
        }
        ans = min (ans, i - b + op);
    }
    printf ("%d\n", ans);
}
int main () {
    int t;
    scanf ("%d", &t);
    while (t --) {
        test_case();
    }
}