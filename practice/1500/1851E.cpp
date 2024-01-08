#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

int dfs(int cur, vector< vector<int> >& adj, vector<int>& dp, vector<int>& c){
    if(dp[cur] != -1)
        return dp[cur];
    int res = 0;
    for(auto nbr: adj[cur]){
        res += dfs(nbr, adj, dp, c);
    }
    dp[cur] = adj[cur].size() == 0 ? c[cur]: min(res, c[cur]);
    return dp[cur];
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> c(n+1), dp(n+1, -1);
    for(int i = 1; i <= n; i++){
        cin >> c[i];
    }
    vector< vector<int> > adj(n+1);
    for(int i = 0; i < k; i++){
        int p;
        cin >> p;
        c[p] = 0;
    }
    for(int i = 1; i <= n; i++){
        int m;
        cin >> m;
        for(int j = 0; j < m; j++){
            int nbr;
            cin >> nbr;
            adj[i].push_back(nbr);
        }
    }
    for(int i = 1; i <= n; i++){
        dfs(i, adj, dp, c);
    }
    for(int i = 1; i <= n; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}