#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k, q;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    for (int i = 0; i < k; i++) cin >> l[i];
    for (int i = 0; i < k; i++) cin >> r[i];
    cin >> q;
    vector<int> x(q), idx(q);
    for (int i = 0; i < q; i++) {
        int y;
        cin >> y;
        int id = lower_bound(r.begin(), r.end(), y) - r.begin();
        x[i] = min(y, l[id] + r[id] - y);
    }
    sort(x.begin(), x.end());
    int xid = 0;
    for (int i = 0; i < k; i++) {
        bool parity = false;
        for (int j = l[i]; j <= (l[i] + r[i]) / 2; j++) {
            while (xid < q && j == x[xid]) {
                parity = !parity;
                xid++;
            }
            if (parity) {
                swap(s[j - 1], s[l[i] + r[i] - j - 1]);
            }
        }
    }
    cout << s << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}