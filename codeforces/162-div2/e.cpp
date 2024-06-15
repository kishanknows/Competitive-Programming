#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

int res = 0;
multiset<int> cur;

void dfs(int v, vector<int>& a, vector<vector<int>>& adj, vector<bool>& vis) {
    vis[v] = true;
    if (cur.find(a[v]) != cur.end()) {
        res++;
    }
    cur.insert(a[v]);
    for (auto x : adj[v]) {
        if (vis[x]) continue;
        dfs(x, a, adj, vis);
    }
    cur.erase(cur.lower_bound(a[v]));
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n + 1);
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) {
            dfs(i, a, adj, vis);
            break;
        }
    }
    cout << res << endl;
    res = 0;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}