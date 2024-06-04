#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int, int>> pts;
    bool flag = false;
    map<pair<int, int>, int> mp;
    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        pts[i] = { x, y };
        mp[{x, y}] = i;
        if (y == 1) flag = true;
    }
    int res = 0;
    if (flag) cout << res << endl;
    sort(pts.begin(), pts.end());
    vector<vector<int>> mx(m + 1);
    vector<int> idx(k + 1);
    for (auto& [x, y] : pts) {
        mx[y].push_back(x);
    }
    for (int i = 1; i <= m; i++) {
        if (mx[i].empty()) {
            res += n;
            continue;
        }
        res += n - mx[i].back();
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