#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve() {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    int sm = 0;
    multiset<int> st;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
        st.insert(a[i]);
    }
    if (a[0] * (sm - a[0]) <= c) {
        cout << 1 << endl;
        return;
    }
    while (c > 0) {
        int tmp = 1e10;
        int mn = -1;
        for (auto x : st) {
            cout << (x * (sm - x)) << " ";
            if (x * (sm - x) < tmp) {
                tmp = x * (sm - x);
                mn = x;
            }
        }
        cout << endl;
        c -= tmp;
        if (c < 0) {
            break;
        }
        sm -= mn;
        st.erase(st.lower_bound(mn));
        n--;
    }
    cout << n << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}