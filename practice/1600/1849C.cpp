#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> ones, zeros;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '0') zeros.push_back(i);
        else ones.push_back(i);
    }
    if (ones.empty() || zeros.empty()) {
        int l, r;
        for (int i = 0; i < m; i++) cin >> l >> r;
        cout << 1 << endl;
        return;
    }
    set<pair<int, int>> st;
    int res = 0;
    for (int i = 0; i < m; i++) {
        int l, r, p, q;
        cin >> l >> r;
        int lo = lower_bound(ones.begin(), ones.end(), l) - ones.begin();
        int hi = upper_bound(zeros.begin(), zeros.end(), r) - zeros.begin();
        p = (lo == ones.size()) ? n + 1 : ones[lo];
        q = (hi == 0) ? 0 : zeros[hi - 1];
        if (p > q) res = 1;
        else st.insert({ p, q });
    }
    res += st.size();
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}