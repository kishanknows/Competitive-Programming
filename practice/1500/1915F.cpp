#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    vector<vector<int> > a(n, vector<int> (2));
    for(int i = 0; i < n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    ordered_set st;
    int res = 0;
    for(int i = 0; i < n; i++){
        res += st.size() - st.order_of_key(a[i][1]);
        st.insert(a[i][1]);
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