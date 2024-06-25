#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (x1 < y1 && x2 > y2 || x1 > y1 && x2 < y2) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}