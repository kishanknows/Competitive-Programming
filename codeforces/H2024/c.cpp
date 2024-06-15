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
    vector<int> path;
    path.push_back(-a[0]);
    for(int i = 1; i < n; i++){
        if(-a[i] >= path.back()){
            path.push_back(-a[i]);
            continue;
        }
        int id = lower_bound(path.begin(), path.end(), -a[i]) - path.begin();
        path[id] = -a[i];
    }
    multiset<int> stack;
    for(int i = 0; i < path.size(); i++){
        stack.insert(-path[i]);
    }
    vector<int> b;
    for(int i = 0; i < n; i++){
        if(stack.find(a[i]) != stack.end()){
            stack.erase(stack.lower_bound(a[i]));
            continue;
        }
        b.push_back(a[i]);
    }
    int res = 0;
    for(int i = 1; i < b.size(); i++){
        if(b[i] > b[i-1]) res++;
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