#include <bits/stdc++.h>
using namespace std;
int main() {
    int tt = 1; 
    cin >> tt;
    while (tt --) {
        int n;
        cin >> n;
        vector <vector <int>> a(n, vector <int> (n,0));
        for (int i = 0; i < n; i ++) {
            a[i][i] = 1;
            a[i][n-1-i] = 1;
            if (i == n-1-i) {
                a[i][i+1] = a[i][i-1] = a[i+1][i] = a[i-1][i] = 1;
            }
        }
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                cout << a[i][j] << " ";
            }
            cout << "\n";
        }
    }
}
