#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, x, tmp;
    cin >> n >> x;
    set<int> st;
    if ((n - x) % 2 == 0) {
        tmp = (n - x) / 2;
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                if (i + 1 >= x) st.insert(i + 1);
                if (tmp / i + 1 >= x) st.insert(tmp / i + 1);
            }
        }
        if (2 >= x) st.insert(2);
        if (tmp + 1 >= x) st.insert(tmp + 1);
    }
    if ((n + x) % 2 == 0) {
        tmp = (n + x - 2) / 2;
        for (int i = 2; i * i <= tmp; i++) {
            if (tmp % i == 0) {
                if (i + 1 >= x) st.insert(i + 1);
                if (tmp / i + 1 >= x) st.insert(tmp / i + 1);
            }
        }
        if (2 >= x) st.insert(2);
        if (tmp + 1 >= x) st.insert(tmp + 1);
    }
    cout << st.size() << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}