#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int m, x;
    cin >> m >> x;
    vector<int> c(m + 1), h(m + 1);
    int maxh = 0;
    for (int i = 1; i <= m; i++) {
        cin >> c[i] >> h[i];
        maxh += h[i];
    }
    vector<int> dp(maxh + 1, 1e10);
    dp[0] = 0;
    for (int j = 1; j <= m; j++) {
        for (int i = maxh; i >= h[j]; i--) {
            if (dp[i - h[j]] + c[j] <= (j - 1) * x) {
                dp[i] = min(dp[i], dp[i - h[j]] + c[j]);
            }
        }
    }

    for (int i = maxh; i >= 0; i--) {
        if (dp[i] <= (m - 1) * x) {
            cout << i << endl;
            return;
        }
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