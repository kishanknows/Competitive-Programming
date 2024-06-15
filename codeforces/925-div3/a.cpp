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
    for (int i = 1; i <= 26; i++) {
        for (int j = 1; j <= 26; j++) {
            for (int k = 1; k <= 26; k++) {
                if (i + j + k == n) {
                    cout << char('a' + i - 1) << char('a' + j - 1) << char('a' + k - 1) << endl;
                    return;
                }
            }
        }
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}