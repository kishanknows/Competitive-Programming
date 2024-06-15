#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int a, b, c;
    string s;
    cin >> a >> b >> c >> s;
    cout << (a + b + c) << " " << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}