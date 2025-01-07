#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    if (n % 2 == 0 && (y - x) % 2 == 1) {
        for (int i = 0; i < n; i++) {
            cout << (i & 1) << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (i + 1 != y) cout << (i & 1) << " ";
        else {
            cout << 2 << " ";
            if ((n - y) % 2 == 0) {
                int x = 0;
                for (int j = i + 1; j < n; j++) {
                    cout << x << " ";
                    x = x ^ 1;
                }
            }
            else {
                int x = 1;
                for (int j = i + 1; j < n; j++) {
                    cout << x << " ";
                    x = x ^ 1;
                }
            }
            cout << endl;
            return;
        }
    }
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