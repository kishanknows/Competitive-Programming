#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[n - 1] == 'n' && s[n - 2] == 'a' && s[n - 3] == 's') {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}