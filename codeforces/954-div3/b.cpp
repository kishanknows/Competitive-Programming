#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int mx = 0;
            if (i - 1 >= 0) mx = max(mx, a[i - 1][j]);
            if (j - 1 >= 0) mx = max(mx, a[i][j - 1]);
            if (i + 1 < n) mx = max(mx, a[i + 1][j]);
            if (j + 1 < m) mx = max(mx, a[i][j + 1]);
            if (mx < a[i][j] && mx != 0) {
                a[i][j] = mx;
            }
            // cout << a[i][j] << " ";
        }
        // cout << endl;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
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