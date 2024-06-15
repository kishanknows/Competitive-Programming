#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> pre(n+1, 0);
    for(int i = 1; i <= n; i++){
        pre[i] = pre[i-1] + a[i];
    }
    int res = INT_MIN;
    for(int i = 0; i <= k; i++){
        int l = max(n-i-x, 0LL);
        res = max(res, pre[l] - (pre[n-i] - pre[l]));
    }
    cout << res << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}