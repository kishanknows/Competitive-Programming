#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n + 1, -1);
    for (int i = y; i <= x; i++) a[i] = 1;
    int i = x + 2, j = y - 2;
    while (i <= n) {
        a[i] = 1;
        i += 2;
    }
    while (j > 0) {
        a[j] = 1;
        j -= 2;
    }
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}