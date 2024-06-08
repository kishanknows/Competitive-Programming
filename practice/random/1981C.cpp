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
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != -1) {
            pq.push({ a[i], i });
        }
    }
    if (pq.empty()) {
        a[0] = 1;
        pq.push({ a[0], 0 });
    }
    while (!pq.empty()) {
        auto [x, i] = pq.top(); pq.pop();
        if (x == 1) {
            if (i - 1 >= 0 && a[i - 1] == -1) {
                a[i - 1] = 2;
                pq.push({ a[i - 1], i - 1 });
            }
            if (i + 1 < n && a[i + 1] == -1) {
                a[i + 1] = 2;
                pq.push({ a[i + 1], i + 1 });
            }
            continue;
        }
        if (i - 1 >= 0 && a[i - 1] == -1) {
            a[i - 1] = x / 2;
            pq.push({ a[i - 1], i - 1 });
        }
        if (i + 1 < n && a[i + 1] == -1) {
            a[i + 1] = x / 2;
            pq.push({ a[i + 1], i + 1 });
        }
    }

    for (int i = 0; i < n - 1; i++) {
        if (a[i] != a[i + 1] / 2 && a[i + 1] != a[i] / 2) {
            cout << -1 << endl;
            return;
        }
    }
    for (auto x : a) cout << x << " ";
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