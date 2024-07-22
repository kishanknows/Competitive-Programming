#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int mx = 0, res = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        res += a[i];
        mp[a[i]]++;
        if (mp[a[i]] == 2) {
            mx = max(mx, a[i]);
        }
        a[i] = mx;
    }
    mp.clear();
    mx = 0;
    for (int i = 0; i < n; i++) {
        mp[a[i]]++;
        res += a[i];
        if (mp[a[i]] == 2) {
            mx = max(mx, a[i]);
        }
        a[i] = mx;
    }
    int cur = 0;
    for (int i = 0; i < n; i++) {
        cur += a[i];
        res += cur;
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