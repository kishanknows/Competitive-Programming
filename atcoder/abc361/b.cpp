#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    vector<int> a(6), b(6);
    for (int i = 0; i < 6; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 6; i++) {
        cin >> b[i];
    }
    int res = 1;
    for (int i = 0; i < 3; i++) {
        res *= min(a[i + 3], b[i + 3]) - max(a[i], b[i]);
    }
    if (res > 0) {
        cout << "Yes" << endl;
    }
    else cout << "No" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}