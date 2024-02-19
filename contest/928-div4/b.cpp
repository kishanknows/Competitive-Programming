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
    set<int> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x = count(s.begin(), s.end(), '1');
        if (x > 0) cnt.insert(x);
    }
    if (cnt.size() == 1) {
        cout << "SQUARE" << endl;
        return;
    }
    cout << "TRIANGLE" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}