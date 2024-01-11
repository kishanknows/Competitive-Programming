#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    map<int, int> curmax;
    vector<int> dp(n+1);
    for(int i = n-1; i >= 0; i--){
        if(!curmax[a[i]]){
            curmax[a[i]] = i + dp[i+1];
            dp[i] = dp[i+1];
            continue;
        }
        dp[i] = max(curmax[a[i]] - i + 1, dp[i+1]);
        curmax[a[i]] = max(curmax[a[i]], i + dp[i+1]);
    }
    cout << dp[0] << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}