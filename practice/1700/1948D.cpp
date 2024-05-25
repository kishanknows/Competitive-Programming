#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    string s;
    cin >> s;
    int n = s.length(), res = 0;
    for (int d = 1; d <= n / 2; d++) {
        int cur = 0;
        for (int i = 0; i < n - d; i++) {
            if (s[i] == s[i + d] || s[i] == '?' || s[i + d] == '?') {
                cur++;
            }
            else cur = 0;
            if (cur == d) res = 2 * d;
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