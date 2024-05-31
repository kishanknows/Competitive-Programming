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
    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' <= 9 && s[i] - '0' >= 0) {
            if (s[i] - '0' < cur) {
                cout << "NO" << endl;
                return;
            }
            cur = s[i] - '0';
        }
        else {
            for (int j = i; j < n - 1; j++) {
                if (s[j] > s[j + 1] || (s[j] - '0' <= 9 && s[j] - '0' >= 0)) {
                    cout << "NO" << endl;
                    return;
                }
            }
            break;
        }
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}