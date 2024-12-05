#include <bits/stdc++.h>

#define int long long
using namespace std;

int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            cout << 1 << endl;
        }
        else if (a[i] < b[i]) {
            cout << 0 << endl;
        }
        else {
            int result = 1;
            int x = 2;
            while (b[i]) {
                if (b[i] & 1)
                    result = ((result % mod) * (x % mod)) % mod;
                x = ((x % mod) * (x % mod)) % mod;
                b[i] >>= 1;
            }
            cout << result << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}