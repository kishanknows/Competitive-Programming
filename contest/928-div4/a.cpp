#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    string s;
    cin >> s;
    int cnt = 0;
    for (int i = 0; i < 5; i++) {
        if (s[i] == 'A') cnt++;
        else cnt--;
    }
    if (cnt > 0) cout << 'A' << endl;
    else cout << 'B' << endl;
}
int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}