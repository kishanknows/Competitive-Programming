#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int minops(int pos, int tar, vector<int>& a) {
    if (a[pos] >= tar) return 0;
    if (pos == a.size() - 1 && a[pos] < tar) return INT_MAX;
    return tar - a[pos] + minops(pos + 1, tar - 1, a);
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), dp(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = *max_element(a.begin(), a.end());
    int r = l + k;
    while (l < r) {
        int cur = (l + r + 1) / 2;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (minops(i, cur, a) <= k) {
                flag = true;
                break;
            }
        }
        if (flag) l = cur;
        else r = cur - 1;

    }
    cout << l << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}