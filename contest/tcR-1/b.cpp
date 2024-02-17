#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += 2) {
        a[i] = i;
    }
    if (n & 1) {
        int cur = 2;
        for (int i = n - 1; i >= 0; i -= 2) {
            a[i] = cur;
            cur += 2;
        }
    }
    else {
        int cur = 2;
        for (int i = n; i >= 0; i -= 2) {
            a[i] = cur;
            cur += 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
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