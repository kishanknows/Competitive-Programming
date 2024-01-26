#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void dfs(vector<vector<int>>& adj, int cur, vector<bool>& vis) {
    vis[cur] = true;
    for (int nbr : adj[cur]) {
        if (vis[nbr]) continue;
        dfs(adj, nbr, vis);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<vector<int>> adj(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) adj[i].push_back(a[i]);
        else if (adj[i][0] != a[i]) adj[i].push_back(a[i]);
        if (adj[a[i]].empty()) adj[a[i]].push_back(i);
        else if (adj[a[i]][0] != i) adj[a[i]].push_back(i);
    }
    int mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) {
        if (adj[i].size() == 1) mn++;
        if (vis[i]) continue;
        dfs(adj, i, vis);
        mx++;
    }
    mn = mn == 0 ? mx : mx - mn / 2 + 1;
    cout << mn << " " << mx << endl;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}