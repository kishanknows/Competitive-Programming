#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    vector<string> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        cout << b[i] << endl;
    }
    vector<vector<int>> rsm(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        int cur = 0;
        for (int j = 0; j < m; j++) {
            cur += (b[i][j] - '0');
            rsm[i][j] = cur;
            cout << cur << " ";
        }
        cout << endl;
    }
    vector<vector<int>> cnt(n, vector<int>(m - k));
    vector<vector<int>> cnt2(n, vector<int>(m - k));
    vector<vector<int>> cnt3(n - k, vector<int>(m - k));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j + k < m; j++) {
            cnt[i][j] = rsm[i][j + k] - (j > 0 ? rsm[i][j - 1] : 0);
            cout << cnt[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m - k; i++) {
        int cur = 0;
        for (int j = 0; j < n; j++) {
            cur += cnt[j][i];
            cnt2[j][i] = cur;
            cout << cur << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < m - k; i++) {
        for (int j = 0; j < n - k; j++) {
            cnt3[i][j] = cnt2[j + k][i] - (j > 0 ? cnt2[j - 1][i] : 0);
            cout << cnt3[i][j] << " ";
        }
        cout << endl;
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