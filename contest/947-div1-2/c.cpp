#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = { a[i], i };
    }
    sort(b.rbegin(), b.rend());
    int res = 0;
    for (auto& [x, y] : b) {
        if (y - 1 >= 0 && a[y - 1] >= x) res = max(res, x);
        if (y - 2 >= 0 && a[y - 2] >= x) res = max(res, x);
        if (y + 1 < n && a[y + 1] >= x) res = max(res, x);
        if (y + 2 < n && a[y + 2] >= x) res = max(res, x);
        if (res != 0) {
            cout << res << endl;
            return;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}