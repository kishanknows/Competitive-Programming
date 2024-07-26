#include <bits/stdc++.h>

#define int long long
using namespace std;

vector<int> po(64);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    bool ok = true;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (a[i] < mx && a[i] == 1) ok = false;
    }
    if (!ok) {
        cout << -1 << endl;
        return;
    }
    vector<long double> b(n);
    for (int i = 0; i < n; i++) b[i] = a[i];
    int res = 0;
    int prev = 1;
    for (int i = 1; i < n; i++) {
        int x = ceil(log2l((prev * log2l(b[i - 1])) / log2l(b[i])));
        res += (1ll << x);
        prev = (1ll << x);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    for (int i = 0; i <= 63; i++) {
        po[i] = 1LL << i;
    }
    while (t--) solve();
    return 0;
}