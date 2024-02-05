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
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b.rbegin(), b.rend());
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (a[i] >= b[j]) {
            cout << a[i] << " ";
            i++;
        }
        else {
            cout << b[j] << " ";
            j++;
        }
    }
    while (i < n) {
        cout << a[i] << " ";
        i++;
    }
    while (j < m) {
        cout << b[j] << " ";
        j++;
    }
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}