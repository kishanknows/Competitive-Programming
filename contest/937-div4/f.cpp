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
    if (a != c - 1) {
        cout << -1 << endl;
        return;
    }
    int res = ceil((double)b / c) + ceil(log2(c));
    c = c - b % c;
    if (c != 0 && (c & (c - 1)) == 0) res--;
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