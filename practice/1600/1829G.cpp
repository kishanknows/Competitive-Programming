#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

vector<int> level;
vector<int> dp(1000001);

void solve() {
    int n;
    cin >> n;
    cout << dp[n] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    int x = 0, sm = 0;
    while (sm < 1000001) {
        sm += x;
        level.push_back(sm);
        x++;
    }
    dp[1] = 1; dp[2] = 5; dp[3] = 10;
    int l = 3;
    for (int i = 4; i <= 1000000; i++) {
        if (i - l > level[l - 2] && i - l <= level[l - 1]) dp[i] += dp[i - l];
        if (i - l + 1 > level[l - 2] && i - l + 1 <= level[l - 1]) dp[i] += dp[i - l + 1];
        if (i - 2 * (l - 1) > level[l - 3] && i - 2 * (l - 1) <= level[l - 2]) dp[i] -= dp[i - 2 * (l - 1)];
        dp[i] += i * i;
        if (i == level[l]) l++;
    }
    while (t--) solve();
    return 0;
}