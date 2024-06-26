#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int h, n, sm = 0;
    cin >> h >> n;
    vector<int> a(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    h -= sm;
    if (h <= 0) {
        cout << 1 << endl;
        return;
    }
    int l = 2, r = 1e18;
    while (l < r) {
        int m = (l + r) / 2;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i] * ((m - 1) / (c[i]));
        }
        if (cur >= h) r = m;
        else l = m + 1;
    }
    cout << l << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}