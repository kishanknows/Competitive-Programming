#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        int sm, pr, res = 0;
        cin >> sm >> pr;
        if (sm * sm < 4 * pr) {
            cout << 0 << " ";
            continue;
        }
        int d = sqrt(sm * sm - 4 * pr);
        if (sm * sm - 4 * pr == d * d) {
            int x1 = (sm + d) / 2;
            int x2 = (sm - d) / 2;
            if (x1 == sm - x1) res += (mp[x1] * (mp[x1] - 1)) / 2;
            else res += mp[x1] * mp[sm - x1];
            if (x2 == sm - x2) res += (mp[x2] * (mp[x2] - 1)) / 2;
            else res += mp[x2] * mp[sm - x2];
        }
        cout << res / 2 << " ";
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}