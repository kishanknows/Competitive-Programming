#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, f, a, b;
    cin >> n >> f >> a >> b;
    vector<int> m(n+1);
    int res = 0;
    for(int i = 1; i <= n; i++){
        cin >> m[i];
        res += min((m[i] - m[i-1]) * a, b);
    }
    cout << (res < f ? "YES": "NO") << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}