#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, mx = 0, res = 0;
    cin >> n;
    for (int i = 2; i <= n; i++) {
        int cur = 0;
        for (int j = 1; j * i <= n; j++) {
            cur += i * j;
        }
        if (mx < cur) {
            mx = cur;
            res = i;
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}