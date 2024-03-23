#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, l;
    cin >> n >> l;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].second >> a[i].first;
    sort(a.begin(), a.end());
    int res = 0;
    for (int i = 0; i < n; i++) {
        priority_queue<int> pq;
        int cur = 0;
        for (int j = i; j < n; j++) {
            cur += a[j].second;
            pq.push(a[j].second);
            while (!pq.empty() && cur + a[j].first - a[i].first > l) {
                cur -= pq.top();
                pq.pop();
            }
            res = max(res, (int)pq.size());
        }
    }
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