#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(a);
    int d = 0, res = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front(); q.pop();
            if (cur == b) {
                if (d & 1) {
                    cout << 2 * (n - 1) << endl;
                    return;
                }
                res += d;
            }
            vis[cur] = true;
            for (auto nbr : adj[cur]) {
                if (vis[nbr]) continue;
                q.push(nbr);
            }
        }
        d++;
    }
    res += 2 * (n - 1) - d;
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