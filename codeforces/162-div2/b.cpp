#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), x(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> x[i];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < n; i++) {
        pq.push({ abs(x[i]), a[i] });
    }
    int cur = 0, prev = 0;
    while (!pq.empty()) {
        auto [x, y] = pq.top(); pq.pop();
        cur += (x - prev) * k;
        if (cur < y) {
            cout << "NO" << endl;
            return;
        }
        cur -= y;
        prev = x;
    }
    cout << "YES" << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}