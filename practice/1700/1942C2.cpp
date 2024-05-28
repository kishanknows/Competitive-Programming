#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    vector<int> a(x);
    for (int i = 0; i < x; i++) cin >> a[i];
    vector<int> even, odd;
    sort(a.begin(), a.end());
    for (int i = 1; i < x; i++) {
        int d = a[i] - a[i - 1] - 1;
        if (d < 2) continue;
        if (d & 1) odd.push_back(d);
        else even.push_back(d);
    }
    int p = a[0] + n - a[x - 1] - 1;
    if (p > 1) {
        (p & 1) ? odd.push_back(p) : even.push_back(p);
    }
    sort(even.rbegin(), even.rend());
    sort(odd.rbegin(), odd.rend());
    while (!odd.empty() && y) {
        int tmp = min(y, odd.back() / 2);
        odd.back() -= tmp * 2;
        y -= tmp;
        if (odd.back() <= 1) odd.pop_back();
    }

    while (!even.empty() && y) {
        int tmp = min(y, even.back() / 2);
        even.back() -= tmp * 2;
        y -= tmp;
        if (even.back() <= 1) even.pop_back();
    }
    int res = n - 2;
    for (auto d : odd) res -= d;
    for (auto d : even) res -= d;
    cout << res << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}