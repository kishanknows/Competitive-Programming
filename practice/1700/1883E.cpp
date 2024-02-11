#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, res = 0, cur = 0;
    double y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        double x; cin >> x;
        if (i == 0 || log2(y / x) + cur < 0) {
            y = x; cur = 0;
            continue;
        }
        cur += ceil(log2(y / x));
        res += cur;
        y = x;
    }
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