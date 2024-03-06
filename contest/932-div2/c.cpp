#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    vector<int> pre(n), len(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j >= 0; j--) {
            if (pre[j] + a[i].first + abs(a[j].second - a[i].second) <= l) {
                if (len[i] < len[j] + 1) {
                    len[i] = len[j] + 1;
                    pre[i] = pre[j] + a[i].first + abs(a[j].second - a[i].second);
                }
                else if (len[i] == len[j] + 1) {
                    pre[i] = min(pre[i], pre[j] + a[i].first + abs(a[j].second - a[i].second));
                }
            }
        }
        res = max(res, len[i]);
    }
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}