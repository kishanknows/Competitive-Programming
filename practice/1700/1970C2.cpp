#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

bool dfs(vector<vector<int>>& adj, vector<bool>& vis, int cur, bool flag) {
    vis[cur] = true;
    bool res = flag;
    for (auto d : adj[cur]) {
        if (vis[d]) continue;
        if (flag) res = res && dfs(adj, vis, d, !flag);
        else res = res || dfs(adj, vis, d, !flag);
    }
    return res;
}

void solve() {
    int n, t, s;
    cin >> n >> t;
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> s;
    bool res = dfs(adj, vis, s, false);
    cout << (res ? "Ron" : "Hermione") << endl;


}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // int t; cin >> t;
    while (t--) solve();
    return 0;
}