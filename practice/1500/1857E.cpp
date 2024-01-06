#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n), pre(n), b(n);
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    for(int i = 0; i < n; i++){
        sum += b[i];
        pre[i] = sum;
    }
    for(int i = 0; i < n; i++){
        int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        int res = 0;
        if(id == 0){
            res = pre[n-1] - b[id] - b[id]*(n - 1);
        }
        else if(id == n-1){
            res = b[id] * (n - 1) - pre[n-2];
        }
        else{
            res = pre[n-1] - pre[id] - pre[id-1] + (2 * id - n + 1) * b[id];
        }
        cout << res + n << " ";
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