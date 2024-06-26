#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<set<int>> adj(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n-1; i++){
        int u, v;
        cin >> u >> v;
        adj[u].insert(v);
        adj[v].insert(u);
    }
    int id = min_element(a.begin()+1, a.end()) - a.begin();
    vector<int> deg(n+1, 0);
    queue<int> q;
    for(int i = 1; i <= n; i++){
        deg[i] = adj[i].size();
        if(deg[i] == 1) q.push(i);
    }
    cout << n-1 << endl;
    while(!q.empty()){
           int cur = q.front(); q.pop();
           if(adj[cur].size() != 1 || cur == id) continue;
           cout << cur << " ";
           int par = *adj[cur].begin();
           adj[par].erase(cur);
           if(adj[par].size() == 1) q.push(par);
            adj[cur].clear();
    }
    cout << endl;
    
    
}

int32_t main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
