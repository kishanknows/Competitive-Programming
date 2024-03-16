#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = ((c + 1) * (c + 2)) / 2;
    int even = 0, odd = 0;
    for (auto x : a) {
        res -= (c + 1 - x);
        if (x & 1) {
            odd++;
            res -= (x / 2 + 1 - odd);
        }
        else {
            even++;
            res -= (x / 2 + 1 - even);
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