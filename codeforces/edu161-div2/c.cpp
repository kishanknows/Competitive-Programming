#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 2), dp(n + 1), rdp(n + 1);
    a[0] = INT_MIN; a[n + 1] = INT_MAX;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 2; i <= n; i++) {
        if (a[i] - a[i - 1] < a[i - 1] - a[i - 2]) {
            dp[i] = dp[i - 1] + 1;
        }
        else {
            dp[i] = dp[i - 1] + a[i] - a[i - 1];
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        if (a[i + 1] - a[i] < a[i + 2] - a[i + 1]) {
            rdp[i] = rdp[i + 1] + 1;
        }
        else {
            rdp[i] = rdp[i + 1] + a[i + 1] - a[i];
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (a < b) {
            cout << dp[b] - dp[a] << endl;
        }
        else {
            cout << rdp[b] - rdp[a] << endl;
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}