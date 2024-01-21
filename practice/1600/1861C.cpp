#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve() {
    string s;
    cin >> s;
    int len = 0, maxsort = 0, minunsort = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '+') len++;
        else if (s[i] == '-') {
            len--;
            maxsort = min(maxsort, len);
            if (len < minunsort) minunsort = 0;
        }
        else if (s[i] == '0') {
            if (len <= 1) {
                cout << "NO" << endl;
                return;
            }
            if (minunsort == 0) minunsort = len;
        }
        else maxsort = max(len, maxsort);

        if (minunsort <= maxsort && minunsort != 0) {
            cout << "NO" << endl;
            return;
        }
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