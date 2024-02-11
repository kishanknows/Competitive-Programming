#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> adj(n + 1);
    vector<bool> marks(n + 1), vis(n + 1);
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        marks[x] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<int> q;
    q.push(1);
    int node = -1;
    while (!q.empty()) {
        int cur = q.front();
        vis[cur] = true;
        q.pop();
        if (marks[cur]) node = cur;
        for (auto nbr : adj[cur]) {
            if (vis[nbr]) continue;
            q.push(nbr);
        }
    }
    vis.clear(); vis.resize(n + 1);
    q.push(node);
    int res = 0, d = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front(); q.pop();
            vis[cur] = true;
            if (marks[cur]) res = d;
            for (auto nbr : adj[cur]) {
                if (vis[nbr]) continue;
                q.push(nbr);
            }
        }
        d++;
    }
    cout << (res + 1) / 2 << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}