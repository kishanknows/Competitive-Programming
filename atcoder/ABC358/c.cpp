#include <bits/stdc++.h>

#define int long long
using namespace std;

int res;

void dfs(int start, vector<string>& s, int m, int n, vector<bool>& done, int ops) {
    // if (start >= n) return;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        if (!done[i]) ok = false;
    }
    if (ok) { res = min(res, ops); }
    for (int i = start; i < n; i++) {
        vector<bool> tmp = done;
        for (int j = 0; j < m; j++) {
            tmp[j] = tmp[j] || (s[i][j] == 'o');
        }
        dfs(i + 1, s, m, n, tmp, ops + 1);
        dfs(i + 1, s, m, n, done, ops);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    res = 1e10;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<bool> done(m);
    dfs(0, s, m, n, done, 0);
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