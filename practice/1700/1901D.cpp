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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n == 1) {
        cout << a[0] << endl;
        return;
    }
    vector<int> mxl(n), mxr(n);
    int res = INT64_MAX;
    int mx1 = 0, mx2 = 0;
    for (int i = 0; i < n; i++) {
        mx1 = max(mx1, a[i] + n - i - 1);
        mx2 = max(mx2, a[n - i - 1] + n - i - 1);
        mxr[i] = mx1;
        mxl[n - i - 1] = mx2;
    }
    for (int i = 0; i < n; i++) {
        int cur = a[i];
        if (i == 0) cur = max(mxl[i + 1], cur);
        else if (i == n - 1) cur = max(mxr[i - 1], cur);
        else {
            cur = max(mxl[i + 1], cur);
            cur = max(mxr[i - 1], cur);
        }
        res = min(res, cur);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}