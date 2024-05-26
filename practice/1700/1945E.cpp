#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, x, id;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == x) id = i;
    }
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (r + l) / 2;
        if (a[m] <= x) l = m;
        else r = m;
    }
    if (id == l) {
        cout << 0 << endl;
        return;
    }
    cout << 1 << endl;
    cout << id + 1 << " " << l + 1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}