#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), f(k);
    set<int> d;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        d.insert(x);
    }
    for (int i = 0; i < k; i++) cin >> f[i];
    vector<int> diff(n);
    int mx = 0, id = -1, mnx = 0;
    for (int i = 1; i < n; i++) {
        diff[i] = a[i] - a[i - 1];
        mx = max(mx, diff[i]);
        if (mx == diff[i]) id = i;
    }
    int cnt = 0;
    for (auto x : diff) {
        if (x == mx) cnt++;
        if (cnt == 2) {
            cout << mx << endl;
            return;
        }
        if (x != mx) mnx = max(mnx, x);
    }
    sort(f.begin(), f.end());
    int mx2 = mx;
    for (auto x : d) {
        int u = upper_bound(f.begin(), f.end(), (a[id] + a[id - 1] - 2 * x) / 2) - f.begin();
        if (u < k) mx2 = min(mx2, max(f[u] + x - a[id - 1], a[id] - x - f[u]));
        if (u > 0) mx2 = min(mx2, max(f[u - 1] + x - a[id - 1], a[id] - x - f[u - 1]));
    }
    cout << max(mnx, mx2) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}