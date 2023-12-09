#include <vector>
#include <iostream>
#define int long long
using namespace std;

void solve(void);
int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}

int dfs(int v, vector<vector<int> >& adj, vector<int>& paths, vector<bool>& vis){
    if(vis[v]) return 0;
    vis[v] = true;
    if(v != 1 && adj[v].size() == 1) return paths[v] = 1;
    for(int i = 0; i < adj[v].size(); i++){
        paths[v] += dfs(adj[v][i], adj, paths, vis);
    }
    return paths[v];
}

void solve(){
    int n, q;
    cin >> n;
    vector<vector<int> > adj(n+1);
    for(int i = 0; i < n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cin >> q;
    vector<vector<int> > ass(q, vector<int> (2));
    for(int i = 0; i < q; i++) cin >> ass[i][0] >> ass[i][1];
    vector<int> paths(n+1, 0);
    vector<bool> vis(n+1, false);
    dfs(1, adj, paths, vis);
    for(int i = 0; i < q; i++) cout<<paths[ass[i][0]]*paths[ass[i][1]]<<endl;
}