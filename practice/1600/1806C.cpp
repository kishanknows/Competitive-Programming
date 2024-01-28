#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    int mx = INT64_MIN, mxid = -1;
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
        mx = max(mx, a[i]);
        if (mx == a[i]) mxid = i;
    }
    int res = INT64_MAX;
    if (n == 1) {
        cout << abs(a[0] - a[1]) << endl;
        return;
    }
    if (n == 2) {
        int cur = 0;
        for (int i = 0; i < 2 * n; i++) cur += abs(a[i] - 2);
        res = min(res, cur);
    }
    int zsum = 0;
    for (int i = 0; i < 2 * n; i++) zsum += abs(a[i]);
    res = min(res, zsum);
    if (n & 1) {
        cout << zsum << endl;
        return;
    }
    int cur = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i == mxid) cur += abs(mx - n);
        else cur += abs(a[i] + 1);
    }
    res = min(res, cur);
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}