#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 2e5 + 1;
const int MOD = 998244353;
int dp[N][3][3][3];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i] %= 2;
    }
    dp[0][2][2][2] = 1;
    for (int i = 0; i < n; i++) {
        memcpy(dp[i + 1], dp[i], sizeof(dp[i]));
        for (int x = 0; x < 3; x++)
            for (int y = 0; y < 3; y++)
                for (int z = 0; z < 3; z++) {
                    if (y == 2 || z == 2 || (y + z + a[i]) % 2 == 0) {
                        dp[i + 1][y][z][a[i]] += dp[i][x][y][z];
                        dp[i + 1][y][z][a[i]] %= MOD;
                    }
                }
    }
    int res = 0;
    for (int x = 0; x < 2; x++) {
        for (int y = 0; y < 2; y++) {
            for (int z = 0; z < 2; z++) {
                res += dp[n][x][y][z];
                res %= MOD;
            }
        }
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}