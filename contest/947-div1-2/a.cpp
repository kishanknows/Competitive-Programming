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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        vector<int> b;
        for (int j = i; j < n; j++) {
            b.push_back(a[j]);
        }
        for (int j = 0; j < i; j++) {
            b.push_back(a[j]);
        }
        bool ok = true;
        for (int j = 0; j < n - 1; j++) {
            if (b[j] > b[j + 1]) {
                ok = false;
                break;
            }
        }
        // for (auto x : b) cout << x << " ";
        // cout << endl;
        if (ok) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}