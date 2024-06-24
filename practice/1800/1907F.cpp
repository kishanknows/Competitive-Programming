#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    bool b1 = true, b2 = true;
    int x1 = -1, x2 = -1;
    for (int i = 0; i < n; i++) cin >> a[i];
    int i = 0;
    while (i + 1 < n && a[i] <= a[i + 1]) {
        i++;
    }
    x1 = i;
    i++;
    if (i == n) {
        cout << 0 << endl;
        return;
    }
    while (i + 1 < n && a[i] <= a[i + 1]) {
        i++;
    }
    if (i < n - 1) b1 = false;
    i = 0;
    while (i + 1 < n && a[i] >= a[i + 1]) {
        i++;
    }
    x2 = i;
    i++;
    if (i == n) {
        cout << 1 << endl;
        return;
    }
    while (i + 1 < n && a[i] >= a[i + 1]) {
        i++;
    }
    if (i < n - 1) b2 = false;
    int res = 1e15;
    if (b1 && x1 != -1) {
        if (a[n - 1] > a[0]) b1 = false;
        else {
            res = min(res, min(x1 + 3, n - x1 - 1));
        }
    }
    if (b2 && x2 != -1) {
        if (a[n - 1] < a[0]) b2 = false;
        else {
            res = min({ res, x2 + 2, n - x2 });
        }
    }
    if (!b1 && !b2) {
        cout << -1 << endl;
        return;
    }
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