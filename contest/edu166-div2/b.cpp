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
    vector<int> a(n), b(n + 1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n + 1; i++) cin >> b[i];
    int x = b[n];
    int res = 0;
    for (int i = 0; i < n; i++) {
        res += abs(a[i] - b[i]);
    }
    for (int i = 0; i < n; i++) {
        if (x >= min(a[i], b[i]) && x <= max(a[i], b[i])) {
            res++;
            cout << res << endl;
            return;
        }
    }
    int mn = INT_MAX;
    for (int i = 0; i < n; i++) {
        mn = min(mn, abs(a[i] - x));
        mn = min(mn, abs(b[i] - x));
    }
    res += mn + 1;
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