#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    vector<int> r(m);
    vector<char> c(m);
    for (int i = 0; i < m; i++) {
        cin >> r[i] >> c[i];
    }
    set<int> st;
    st.insert(x);
    for (int i = 0; i < m; i++) {
        set<int> tmp;
        for (auto x : st) {
            int p = x - r[i] <= 0 ? x - r[i] + n : x - r[i];
            int q = x + r[i] > n ? x + r[i] - n : x + r[i];
            if (c[i] == '1') {
                tmp.insert(p);
            }
            else if (c[i] == '0') {
                tmp.insert(q);
            }
            else {
                tmp.insert(p);
                tmp.insert(q);
            }
        }
        st = tmp;
    }
    cout << st.size() << endl;
    for (auto x : st) cout << x << " ";
    cout << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}