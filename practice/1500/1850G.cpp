#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> memo(4, vector<int> (n));
    for(int i = 0; i < n ; i++){
        int x, y;
        cin >> x >> y;
        memo[0][i] = x;
        memo[1][i] = y;
        memo[2][i] = x - y;
        memo[3][i] = x + y;
    }
    int res = 0;
    for(int i = 0; i < 4; i++){
        sort(memo[i].begin(), memo[i].end());
        int cur = 1;
        for(int j = 1; j < n; j++){
            if(memo[i][j] == memo[i][j-1]){
                cur++;
                continue;
            }
            res += (cur * cur - cur)/2;
            cur = 1;
        }
        res += (cur * cur - cur)/2;
    }
    cout << res * 2 << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}