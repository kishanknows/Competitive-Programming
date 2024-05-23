#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int x = c;
    if (a != c - 1) {
        cout << -1 << endl;
        return;
    }
    int level = ceil(log2(c));
    b -= min(b, (1 << level) - c);
    int res = level + (b + c - 1) / c;
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