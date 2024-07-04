#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        mp[x]++;
    }
    a.push_back(0);
    for (auto [k, v] : mp) a.push_back(v);
    n = a.size() - 1;
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        vector<int> tmp = dp;
        for (int j = 1; j <= n; j++) {
            int x = dp[j - 1] + a[i];
            if (x <= i - j)
                tmp[j] = min(tmp[j], x);
        }
        dp = tmp;
    }
    int bob = 0;
    for (int i = 1; i <= n; i++) {
        if (dp[i] < 1e9) bob++;
    }
    cout << n - bob << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}