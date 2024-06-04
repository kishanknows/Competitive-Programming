#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    if (k == n) {
        cout << "YES" << endl;
        return;
    }
    int x = a[f - 1];
    sort(a.rbegin(), a.rend());
    if (a[k] == x && a[k - 1] == x) {
        cout << "MAYBE" << endl;
    }
    else if (a[k - 1] > x) {
        cout << "NO" << endl;
    }
    else {
        cout << "YES" << endl;
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}