#include <bits/stdc++.h>
using namespace std;
void test_case() {
    long long x, y;
    scanf ("%lld%lld", &x, &y);
    long long d = sqrt(x + 1);
    if (d > y) {
        printf ("%lld\n", (y * (y - 1)) / 2);
        return;
    }
    long long cnt = (d * (d - 1)) / 2;
    for (long long b = d + 1; b <= y; b ++) {
        cnt += (x / (b + 1));
    }
    printf ("%lld\n", cnt);
}
int main () {
    int t;
    scanf ("%d", &t);
    while (t --) {
        test_case();
    }
}