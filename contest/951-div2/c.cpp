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
    vector<int> a(n), res(n);
    int x = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        x = lcm(x, a[i]);
    }
    int sm = 0;
    for (int i = 0; i < n; i++) {
        res[i] = x / a[i];
        sm += res[i];
    }
    if (sm >= x) {
        cout << -1 << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}