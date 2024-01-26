#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, q;
    cin >> n >> m;
    vector<pair<int, int>> seg(m);
    for (int i = 0; i < m; i++) cin >> seg[i].first >> seg[i].second;
    cin >> q;
    vector<int> query(q + 1);
    for (int i = 1; i <= q; i++) cin >> query[i];
    int i = 1, j = q + 1;
    while (i < j) {
        vector<int> pre(n + 1, 0);
        int mi = (i + j) / 2;
        bool left = false;
        for (int k = 1; k <= mi; k++) pre[query[k]] = 1;
        for (int k = 1; k <= n; k++) pre[k] += pre[k - 1];
        for (auto& [l, r] : seg) {
            if (pre[r] - pre[l - 1] > (r - l + 1) / 2) {
                left = true;
                break;
            }
        }
        if (left) j = mi;
        else i = mi + 1;
    }
    cout << (i == q + 1 ? -1 : i) << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}