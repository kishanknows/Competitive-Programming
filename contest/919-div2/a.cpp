#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    int mn = INT_MIN, mx = INT_MAX;
    vector<int> tmp;
    for(int i = 0; i < n; i++){
        int a, x;
        cin >> a >> x;
        if(a == 3){
            tmp.push_back(x);
            continue;
        }
        if(a == 1){
            mn = max(mn, x);
        }
        else{
            mx = min(mx, x);
        }
    }
    int res = mx - mn + 1;
    for(int i = 0; i < tmp.size(); i++){
        if(tmp[i] <= mx && tmp[i] >= mn){
            res--;
        }
    }
    res = (res < 0 ? 0: res);
    cout <<  res << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}