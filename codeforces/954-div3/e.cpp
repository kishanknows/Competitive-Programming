#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> mods(n);
    map<int, set<int>> mp;
    for (int i = 0; i < n; i++) {
        if (mp[a[i] % k].find(a[i]) != mp[a[i] % k].end()) {
            mp[a[i] % k].erase(a[i]);
        }
        else {
            mp[a[i] % k].insert(a[i]);
        }
    }
    int cnt = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second.size() % 2 == 1) {
            cnt++;
        }
        // cout << it->first << ": ";
        // for (auto x : it->second) {
        //     cout << x << " ";
        // }
        // cout << endl;
    }
    // cout << endl;
    if (cnt > 1) {
        cout << -1 << endl;
        return;
    }
    if (cnt == 1 && (n % 2 == 0)) {
        cout << -1 << endl;
        return;
    }
    int res = 0;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second.size() % 2 == 1) continue;
        auto x = it->second.begin();
        while (x != it->second.end()) {
            int a = *x; x++;
            int b = *x;
            res += (b - a) / k;
            x++;
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