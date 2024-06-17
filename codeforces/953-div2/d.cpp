#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[1] += c;
    int mx = -1;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        mx = max(mx, a[i]);
        pre[i] = pre[i - 1] + a[i];
    }
    vector<int> dp(n + 1);
    int curmax = -1;
    for (int i = 1; i <= n; i++) {
        if (curmax != mx && a[i] == mx) {
            dp[i] = 0;
        }
        else if (pre[i] >= mx) {
            dp[i] = i - 1;
        }
        else {
            dp[i] = i;
        }
        curmax = max(curmax, a[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << " ";
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