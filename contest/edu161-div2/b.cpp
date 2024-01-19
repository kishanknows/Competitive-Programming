#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int i = 0, j = 1;
    int res = 0;
    while (j < n - 1) {
        int sm = a[i] + a[j];
        int x = upper_bound(a.begin() + j, a.end(), sm - 1) - a.begin();
        cout << i << " " << j << " " << sm << " " << x << endl;
        res += x - j;
        if (j - i == 1) {
            j++;
        }
        else {
            if (a[i] + a[j + 1] < a[i + 1] + a[j]) {
                j++;
            }
            else {
                i++;
            }
        }
        // cout << i << " " << j << endl;
    }
    cout << res << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}