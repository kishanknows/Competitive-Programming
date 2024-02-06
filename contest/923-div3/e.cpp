#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int x = 1, p = 0, q = n - 1 - n % k;
    bool flag = true;
    while (x <= n) {
        if (flag) {
            for (int i = p; i < n; i += k) {
                a[i] = x;
                x++;
            }
            p += 2;
        }
        else {
            for (int i = q; i >= 0; i -= k) {
                a[i] = x;
                x++;
            }
            q += 2;
        }
        flag = !flag;
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
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