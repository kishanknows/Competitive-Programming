#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m;
    cin >> n;
    vector<int> a(n), b(n);
    set<int> bx;
    multiset<int> diff;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        bx.insert(b[i]);
    }
    cin >> m;
    vector<int> d(m);
    for (int i = 0; i < m; i++) cin >> d[i];
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) diff.insert(b[i]);
    }
    bool flag = true;
    for (int i = 0; i < m; i++) {
        if (diff.find(d[i]) != diff.end()) {
            diff.erase(diff.lower_bound(d[i]));
            continue;
        }
        if (bx.find(d[i]) != bx.end() && diff.empty()) flag = true;
        else if (bx.find(d[i]) == bx.end() && diff.empty()) {
            flag = false;
        }
    }
    if (!diff.empty() || !flag) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}