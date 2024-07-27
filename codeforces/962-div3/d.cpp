#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int res = 0;
    for (int a = 1; a <= x; ++a) {
        for (int b = 1; a * b <= n; ++b) {
            int mxc = min((n - a * b) / (a + b), x - (a + b));
            res += mxc > 0 ? mxc : 0;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}