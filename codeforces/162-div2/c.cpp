#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n + 1), cnt(n + 1), pre(n + 1);
    int sm = 0, x = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) x++;
        sm += a[i];
        pre[i] = sm;
        cnt[i] = x;
    }
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        if (l == r) {
            cout << "NO" << endl;
            continue;;
        }
        if (r - l + 1 + cnt[r] - cnt[l - 1] > pre[r] - pre[l - 1]) {
            cout << "NO" << endl;
        }
        else cout << "YES" << endl;
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