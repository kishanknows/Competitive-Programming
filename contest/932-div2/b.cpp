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
    vector<int> a(n);
    set<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.insert(a[i]);
    }
    int mex = 0;
    set<int> s;
    for (int i = 0; i <= n; i++) {
        if (st.find(i) == st.end()) {
            mex = i;
            break;
        }
        s.insert(i);
    }
    set<int> s2 = s;
    int k = n;
    for (int i = 0; i < n; i++) {
        s.erase(a[i]);
        if (s.empty()) {
            k = i;
            break;
        }
    }
    for (int i = k + 1; i < n; i++) {
        s2.erase(a[i]);
        if (s2.empty()) {
            cout << 2 << endl;
            cout << 1 << " " << k + 1 << endl;
            cout << k + 2 << " " << n << endl;
            return;
        }
    }
    cout << -1 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}