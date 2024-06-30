#include <bits/stdc++.h>

#define int long long
using namespace std;

int mod = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 1;
    int res = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[i + 1]) {
            if (cur > 2) res = ((res % mod) * ((cur + 1) / 2) % mod) % mod;
            cur = 1;
        }
        else if (i + 1 < n) {
            cur++;
        }
    }
    if (cur > 2) res = ((res % mod) * ((cur + 1) / 2) % mod) % mod;
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