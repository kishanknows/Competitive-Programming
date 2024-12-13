#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    if (n < 2 || m < 2) {
        cout << -1 << endl;
        return;
    }
    int mn = INT64_MAX;
    int lx = -1, rx = -1;
    for (int i = 0; i < 26; i++) {
        int l = -1, r = -1;
        for (int j = 1; j < n; j++) {
            if (s[j] - 'a' == i) {
                l = j;
                break;
            }
        }
        for (int j = 0; j < m - 1; j++) {
            if (t[j] - 'a' == i) {
                r = j;
            }
        }
        if (l == -1 || r == -1) continue;
        int cur = l + m - r;
        if (cur <= mn) {
            lx = l, rx = r;
            mn = cur;
        }
    }
    if (lx == -1 || rx == -1) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < lx; i++) cout << s[i];
    for (int i = rx; i < m; i++) cout << t[i];
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}