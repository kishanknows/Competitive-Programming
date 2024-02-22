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
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int res = 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        if (a[0][i] == '1') {
            dp[0][i] = 1;
            res++;
        }
    }
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] += j - 1 >= 0 ? dp[i - 1][j - 1] : 0;
            dp[i][j] += j + 1 < n ? dp[i - 1][j + 1] : 0;
            dp[i][j] -= i - 2 >= 0 && j - 1 >= 0 && j + 1 < n ? dp[i - 2][j] : 0;
            if (a[i - 1][j] == '1') dp[i][j]++;
            if (dp[i][j] % 2 == 1) a[i][j] = a[i][j] == '1' ? '0' : '1';
            if (a[i][j] == '1') {
                dp[i][j]++;
                res++;
            }
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