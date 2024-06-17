#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    if (b - a > n) {
        cout << (b * (b + 1)) / 2 - ((b - n) * ((b - n) + 1)) / 2 << endl;
        return;
    }
    if (b > a) {
        int res = (b * (b + 1)) / 2 - (a * (a + 1)) / 2 + (n - (b - a)) * a;
        cout << res << endl;
    }
    else {
        cout << n * a << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}