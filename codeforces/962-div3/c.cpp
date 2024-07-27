#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, q;
    cin >> n >> q;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> cnt1(n + 1, vector<int>(26, 0));
    vector<vector<int>> cnt2(n + 1, vector<int>(26, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 26; j++) {
            cnt1[i][j] = cnt1[i - 1][j];
            cnt2[i][j] = cnt2[i - 1][j];
        }
        cnt1[i][a[i - 1] - 'a']++;
        cnt2[i][b[i - 1] - 'a']++;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int cur = 0;
        for (int j = 0; j < 26; j++) {
            cur += abs((cnt1[r][j] - cnt1[l - 1][j]) - (cnt2[r][j] - cnt2[l - 1][j]));
        }
        cout << cur / 2 << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}