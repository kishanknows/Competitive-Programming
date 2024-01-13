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
    vector<int> divs;
    divs.push_back(1);
    for(int i = 2; i <= sqrt(n); i++){
        if(n %i == 0 && i == n/i){
            divs.push_back(i);
            continue;
        }
        if(n % i == 0){
            divs.push_back(i);
            divs.push_back(n/i);
        }
    }
    if(n > 1) divs.push_back(n);
    int res = 0;
    for(auto d: divs){
        int gd = 0;
        for(int i = 0; i < d; i++){
            int cur = a[i];
            for(int j = i+d; j < n; j+=d){
                gd = gcd(gd, abs(cur - a[j]));
            }
        }
        if(gd != 1) res++;
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