#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n + 1), idx(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        idx[i] = i;
    }
    sort(idx.begin() + 1, idx.end(), [&](int u, int v) {
        return a[u] - u * c > a[v] - v * c;
        });
    int cur = a[1];
    for (int i = 1; i <= n; i++) {
        int j = idx[i];
        if (j == 1) continue;
        if (cur + a[j] < j * c) {
            cout << "NO" << endl;
            return;
        }
        cur += a[j];
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}