#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    map<int, int> mp;
    int res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
        if (mp[a[i]] * a[i] <= m) {
            res = max(res, mp[a[i]] * a[i]);
        }
    }

    for (auto [x, y] : mp) {
        if (mp.find(x + 1) == mp.end()) continue;
        for (int i = 0; i <= y; i++) {
            if (i * x > m) break;
            int j = min(mp[x + 1], (m - i * x) / (x + 1));
            res = max(res, i * x + j * (x + 1));
        }
    }

    cout << res << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}