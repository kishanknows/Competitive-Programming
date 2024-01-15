#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n;
    cin >> n;
    string s, f;
    cin >> s >> f;
    int diff = 0;
    int s1 = 0, f1 = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '1') s1++;
        if(f[i] == '1') f1++;
        if(s[i] != f[i]) diff++;
    }
    cout << abs(s1-f1) + (diff - abs(s1-f1))/2 <<  endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}