#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        mp[a[i] % y].push_back(a[i] % x);
    }
    int res = 0;
    for (auto m : mp) {
        map<int, int> tmp;
        for (auto i : m.second) {
            tmp[i]++;
        }
        for (auto p : tmp) {
            int k = tmp[x - p.first];
            if (p.first == (x - p.first) % x) {
                res += (p.second * (p.second - 1));
                continue;
            }
            res += (p.second * k);
        }
    }
    cout << res / 2 << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}