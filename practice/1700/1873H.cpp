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
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if (a == b) {
        cout << "NO" << endl;
        return;
    }
    vector<int> deg(n + 1);
    set<int> leafs;
    for (int i = 1; i <= n; i++) {
        deg[i] = adj[i].size();
        if (deg[i] == 1) leafs.insert(i);
    }
    while (!leafs.empty()) {
        int cur = *leafs.begin(); leafs.erase(cur);
        for (auto nbr : adj[cur]) {
            deg[nbr]--;
            if (deg[nbr] == 1) leafs.insert(nbr);
        }
    }
    set<int> cycle;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 2) cycle.insert(i);
    }
    if (cycle.find(b) != cycle.end()) {
        cout << "YES" << endl;
        return;
    }
    vector<bool> vis(n + 1, false);
    queue<int> q;
    q.push(b);
    int bd = 0, c = -1, ad = 0;
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front(); q.pop();
            if (cycle.find(cur) != cycle.end()) {
                c = cur;
                while (!q.empty()) q.pop();
                bd--;
                break;
            }
            vis[cur] = true;
            for (auto nbr : adj[cur]) {
                if (vis[nbr]) continue;
                q.push(nbr);
            }
        }
        bd++;
    }
    vis.assign(n + 1, false);
    q.push(a);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; i++) {
            int cur = q.front(); q.pop();
            if (cur == c) {
                while (!q.empty()) q.pop();
                ad--;
                break;
            }
            vis[cur] = true;
            for (auto nbr : adj[cur]) {
                if (vis[nbr]) continue;
                q.push(nbr);
            }
        }
        ad++;
    }
    if (bd < ad) cout << "YES" << endl;
    else cout << "NO" << endl;

}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while (t--) solve();
    return 0;
}