#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define int long long
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void solve(){
    int n, s1, s2;
    cin >> n >> s1 >> s2;
    vector<pair<int,int>> r(n);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        r[i-1] = {x, i};
    }
    sort(r.rbegin(), r.rend());
    vector<int> v1, v2;
    int i = 1, j = 1, k = 0;
    while(i <= n && j <= n && k < n){
        if(i * s1 < j * s2){
            v1.push_back(r[k].second);
            i++;
        }
        else{
            v2.push_back(r[k].second);
            j++;
        }
        k++;
    }
    while(i <= n && k < n){
        v1.push_back(r[k].second);
        i++;
        k++;
    }
    while(j <= n && k < n){
        v2.push_back(r[k].second);
        j++;
        k++;
    }
    cout << v1.size() << " ";
    for(auto x: v1) cout << x << " ";
    cout << endl;
    cout << v2.size() << " ";
    for(auto x: v2) cout << x << " ";
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