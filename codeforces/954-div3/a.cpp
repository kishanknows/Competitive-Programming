#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int x, y, z;
    cin >> x >> y >> z;
    cout << max({ x, y, z }) - min({ x, y, z }) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}