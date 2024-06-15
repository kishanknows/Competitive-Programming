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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> zeros;
    int len = 0;
    for (auto x : a) {
        int cur = 0;
        bool flag = true;
        while (x) {
            if (x % 10 == 0 && flag) cur++;
            else flag = false;
            x /= 10;
            len++;
        }
        zeros.push_back(cur);
    }
    sort(zeros.begin(), zeros.end());
    for (int i = zeros.size() - 1; i >= 0; i -= 2) {
        len -= zeros[i];
    }
    if (len >= m + 1) {
        cout << "Sasha" << endl;
    }
    else
        cout << "Anna" << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}