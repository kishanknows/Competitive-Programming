#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mp[x]++;
    }
    auto it = mp.begin();
    int len = 0;
    while (it != mp.end() && it->first == len) {
        it++;
        len++;
    }
    vector<int> dp(len + 1, INT_MAX);
    dp[len] = 0;
    for (int i = len - 1; i >= 0; i--) {
        int cnt = mp[i];
        for (int j = i + 1; j <= len; j++) {
            dp[i] = min(dp[i], j * (cnt - 1) + dp[j] + i);
        }
    }
    cout << dp[0] << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}