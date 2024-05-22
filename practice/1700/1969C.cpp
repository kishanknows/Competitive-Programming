#include <bits/stdc++.h>

#define int long long
#define imax 1e18
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, imax));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            int mn = imax;
            for (int d = 0; j + d <= k && i + d < n; d++) {
                mn = min(mn, a[i + d]);
                dp[i + d + 1][j + d] = min(dp[i + d + 1][j + d], dp[i][j] + (d + 1) * mn);
            }
        }
    }
    int res = *min_element(dp[n].begin(), dp[n].end());
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