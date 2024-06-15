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
    vector<int> a(n);
    int sm = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    sm /= n;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] < sm) {
            cout << "NO" << endl;
            return;
        }
        a[i + 1] += a[i] - sm;
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