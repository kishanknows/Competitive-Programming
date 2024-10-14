#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s == t) {
        cout << 0 << endl;
        return;
    }
    int i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
        if (s[i] != t[j]) {
            cout << i + 1 << endl;
            return;
        }
        i++; j++;
    }
    cout << i + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}