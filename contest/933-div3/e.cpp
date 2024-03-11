#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; cin >> x;
            a[i][j] = x + 1;
        }
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        vector<int> dp(m, 0);
        multiset<int> st;
        for (int j = 0; j <= d && j < m; j++) {
            if (st.empty()) dp[j] = a[i][j];
            else dp[j] = a[i][j] + *st.begin();
            st.insert(dp[j]);
        }
        for (int j = d + 1; j < m; j++) {
            dp[j] = *st.begin() + a[i][j];
            st.erase(st.lower_bound(dp[j - d - 1]));
            st.insert(dp[j]);
        }
        b[i] = dp[m - 1];
    }
    int cur = 0, res = 0;
    for (int i = 0; i < k; i++) cur += b[i];
    res = cur;
    for (int i = k; i < n; i++) {
        cur = cur - b[i - k] + b[i];
        res = min(res, cur);
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