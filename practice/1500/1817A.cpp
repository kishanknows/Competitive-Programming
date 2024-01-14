#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, q;
    cin >> n >> q;
    vector<int> a(n+2), pre(n+1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    a[n+1] = INT64_MAX;

    for(int i = 1; i <= n; i++){
        if(a[i-1] >= a[i] && a[i] >= a[i+1]){
            while(i <= n && a[i] >= a[i+1]){
                pre[i] = pre[i-1];
                i++;
            }
        }
        pre[i] = pre[i-1] + 1;
    }

    for(int i = 0; i < q; i++){
        int l, r, res = 0;
        cin >> l >> r;
        res = pre[r] - pre[l] + 1;
        if(pre[r] == pre[r-1]) res++;
        cout << min(res, r - l + 1) << endl;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}