#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        if (!(x <= 1 && y >= 1)) {
            mp1[x]++;
            mp1[y + 1]--;
        }
        if (!(x <= m && y >= m)) {
            mp2[x]++;
            mp2[y + 1]--;
        }
    }
    int mx = 0, sm = 0;
    for (auto it = mp1.begin(); it != mp1.end(); it++) {
        sm += it->second;
        it->second = sm;
        mx = max(mx, it->second);
    }
    sm = 0;
    for (auto it = mp2.begin(); it != mp2.end(); it++) {
        sm += it->second;
        it->second = sm;
        mx = max(mx, it->second);
    }
    cout << mx << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}