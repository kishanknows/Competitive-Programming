#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    string s, t;
    cin >> s >> t;
    if (s == "AtCoder" && t == "Land") {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
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