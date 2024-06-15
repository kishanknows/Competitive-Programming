#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    set<int> a, b;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }
    int p = 0, q = 0, r = 0;
    for (int i = 1; i <= k; i++) {
        if (a.find(i) != a.end() && b.find(i) == b.end()) p++;
        else if (a.find(i) == a.end() && b.find(i) != b.end()) q++;
        else if (a.find(i) != a.end() && b.find(i) != b.end()) r++;
        else {
            cout << "NO" << endl;
            return;
        }
    }
    if (p > k / 2 || q > k / 2) {
        cout << "NO" << endl;
        return;
    }
    if (p + q + r == k) {
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}