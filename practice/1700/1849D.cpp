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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = 0, res = 0;
    while (l < n) {
        bool hasTwo = a[l] == 2;
        bool left = a[l] == 0;
        int r = l + 1;
        while (r < n && a[r] != 0) {
            hasTwo = a[r] == 2 || hasTwo;
            r++;
        }
        if (left && hasTwo || !left) l = r + 1;
        else l = r;
        res++;
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}