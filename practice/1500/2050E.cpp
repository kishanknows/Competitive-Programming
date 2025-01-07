#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N = 1001;
int dp[N][N];

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    a = " " + a, b = " " + b, c = " " + c;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            dp[i][j] = 1e9;
    }
    dp[0][0] = 0;
    for (int i = 0; i < a.length(); i++) {
        for (int j = 0; j < b.length(); j++) {
            if (i + j == 0) continue;
            if (c[i + j] == a[i]) dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            if (c[i + j] == b[j]) dp[i][j] = min(dp[i][j], dp[i][j - 1]);
            if (i) dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1);
            if (j) dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    cout << dp[a.length() - 1][b.length() - 1] << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}