#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int x, y, z, k;
    cin >> x >> y >> z >> k;
    vector<int> di;
    for (int i = 2; i <= sqrt(k); i++) {
        if (k % i == 0 && (k / i == i)) {
            di.push_back(i);
        }
        else if (k % i == 0) {
            di.push_back(i);
            di.push_back(k / i);
        }
    }
    vector<int> a = { x, y, z };
    sort(a.begin(), a.end());
    di.push_back(1);
    if (k > 1) di.push_back(k);
    int mx = 0;
    for (auto p : di) {
        for (auto q : di) {
            if (k % (p * q) == 0) {
                int r = k / (p * q);
                vector<int> b = { p, q, r };
                sort(b.begin(), b.end());
                if (a[0] < b[0] || a[1] < b[1] || a[2] < b[2]) continue;
                mx = max(mx, (a[0] - b[0] + 1) * (a[1] - b[1] + 1) * (a[2] - b[2] + 1));
            }
        }
        // cout << p << " ";
    }
    // cout << endl;
    cout << mx << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}