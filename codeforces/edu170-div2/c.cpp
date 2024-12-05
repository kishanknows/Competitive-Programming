#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        mp[a[i]]++;
    }
    auto it = mp.begin();
    vector<vector<int>> b;
    while (it != mp.end()) {
        vector<int> c;
        int cur = it->first;
        while (mp[cur]) {
            c.push_back(mp[cur]);
            cur++;
            it++;
        }
        b.push_back(c);
    }
    int res = 0;
    for (auto c : b) {
        int x = c.size();
        int cur = 0;
        for (int i = 0; i < x && i < k; i++) {
            cur += c[i];
        }
        res = max(res, cur);
        for (int i = k; i < x; i++) {
            cur = cur - c[i - k] + c[i];
            res = max(res, cur);
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