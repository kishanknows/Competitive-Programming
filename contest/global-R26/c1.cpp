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
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> mn(n + 1), mx(n + 1);
    for (int i = 1; i <= n; i++) {
        mn[i] = min({ mn[i - 1] + a[i], mx[i - 1] + a[i], llabs(mn[i - 1] + a[i]), mx[i - 1] + a[i] });
        mx[i] = max({ mn[i - 1] + a[i], mx[i - 1] + a[i], llabs(mn[i - 1] + a[i]), mx[i - 1] + a[i] });
    }
    cout << mx[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}