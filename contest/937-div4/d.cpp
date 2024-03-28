#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

set<int> st;

void solve() {
    int n;
    cin >> n;
    if (st.find(n) != st.end()) {
        cout << "YES" << endl;
        return;
    }
    for (auto d : st) {
        while (n % d == 0) {
            n = n / d;
            if (st.find(n) != st.end()) {
                cout << "YES" << endl;
                return;
            }
        }
    }
    if (n == 1) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    st = { 10, 11, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000, 10001, 10010, 10011, 10100, 10101, 10110, 10111, 11000, 11001, 11010, 11011, 11100, 11101, 11110, 11111, 100000 };
    while (t--) solve();
    return 0;
}