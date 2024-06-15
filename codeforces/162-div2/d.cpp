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
    vector<int> a(n + 1), pre(n + 1), post(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    for (int i = n; i > 0; i--) {
        post[i] = post[i + 1] + a[i];
    }
    for (int i = 1; i <= n; i++) {
        int l = i + 1, r = n + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (pre[m] - pre[i] <= a[i]) {
                l = m + 1;
            }
            else
                r = m;
        }
        int p = 0, q = i;
        while (p < q) {
            int m = (p + q + 1) / 2;
            if (post[m] - post[i] <= a[i]) {
                q = m - 1;
            }
            else
                p = m;
        }
        if (l == n + 1 && p == 0) cout << -1 << " ";
        else if (l == n + 1) cout << i - p << " ";
        else if (p == 0) cout << l - i << " ";
        else cout << min(l - i, i - p) << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}