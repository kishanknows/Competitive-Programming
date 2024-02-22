#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
    tree_order_statistics_node_update> ordered_set;

vector<int> stk;
bool res = false;
map<int, int> mp;
int cur = 0;
void dfs(int v, map<int, vector<int>>& adj, vector<bool>& vis, map<pair<int, int>, int>& wt) {
    vis[v] = true;
    if (!stk.empty()) {
        cur += wt[{stk.back(), v}];
        mp[v] = cur;
    }
    stk.push_back(v);
    for (auto x : adj[v]) {
        if (vis[x] && mp.find(x) != mp.end() && stk.size() > 1 && stk[stk.size() - 2] != x) {
            if (cur - mp[x] + wt[{v, x}] != 0) {
                res = true;
                return;
            }
        }
        if (vis[x]) continue;
        dfs(x, adj, vis, wt);
    }
    stk.pop_back();
    if (!stk.empty()) {
        mp.erase(v);
        cur -= wt[{stk.back(), v}];
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    map<int, vector<int>> adj;
    map<pair<int, int>, int> wt;
    bool ok = true;
    for (int i = 0; i < m; i++) {
        int u, v, d;
        cin >> u >> v >> d;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (wt.find({ u, v }) != wt.end() && wt[{u, v}] != d) ok = false;
        if (wt.find({ v, u }) != wt.end() && wt[{v, u}] != -d) ok = false;
        wt[{u, v}] = d;
        wt[{v, u}] = -d;
    }
    if (!ok) {
        cout << "NO" << endl;
        return;
    }
    vector<bool> vis(n + 1);
    for (auto u : adj) {
        if (vis[u.first]) continue;
        mp[u.first] = 0;
        dfs(u.first, adj, vis, wt);
        if (res) {
            cout << "NO" << endl;
            res = false, cur = 0;
            stk.clear(), mp.clear();
            return;
        }
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