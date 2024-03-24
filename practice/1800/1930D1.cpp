#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int p = i, q = j, cur = 0;
            while (p <= q) {
                while (p <= q && s[p] != '1') p++;
                if (p > q) break;
                cur++;
                p += 3;
            }
            res += cur;
        }
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