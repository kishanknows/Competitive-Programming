#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;
    for (auto x : a) mp[x]++;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (mp.find(i) == mp.end()) {
            cout << i << endl;
            return;
        }
        if (mp[i] == 1) {
            if (flag) {
                cout << i << endl;
                return;
            }
            flag = true;
        }
    }
    cout << n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}