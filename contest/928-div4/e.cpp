#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k;
    cin >> n >> k;
    int tmp = (n + 1) / 2;
    int cur = tmp, start = 1, d = 2;
    while (cur < k) {
        start *= 2;
        d *= 2;
        tmp = (n - start) / d + 1;
        cur += tmp;
    }
    cout << start + (tmp - cur + k - 1) * d << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}