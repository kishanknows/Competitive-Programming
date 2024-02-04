#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    set<int> ones;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 1) ones.insert(i + 1);
    }
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int val;
            cin >> val;
            int sm = 2 * n - ones.size();
            if (val > sm) {
                cout << "NO" << endl;
                continue;
            }
            if ((sm - val) % 2 == 0) {
                cout << "YES" << endl;
                continue;
            }
            if (ones.empty()) {
                cout << "NO" << endl;
                continue;
            }
            int l = *ones.begin(), r = *ones.rbegin();
            sm = max(sm - 2 * l + 1, sm - 2 * (n - r) - 1);
            if (sm < val) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
        else {
            int pos, val;
            cin >> pos >> val;
            ones.erase(pos);
            if (val == 1) ones.insert(pos);
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}