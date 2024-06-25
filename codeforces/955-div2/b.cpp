#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int x, y, k;
    cin >> x >> y >> k;
    while (k > 0) {
        if (k < y - x % y) {
            cout << x + k << endl;
            return;
        }
        k -= (y - x % y);
        x += (y - x % y);
        while (x % y == 0) x /= y;
        if (x == 1) {
            cout << x + k % (y - 1) << endl;
            return;
        }
    }
    cout << x << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}