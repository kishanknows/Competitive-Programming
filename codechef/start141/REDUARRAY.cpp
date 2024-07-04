#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    int ones = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        ones += a[i] == 1 ? 1: 0;
    }
    int res = n-ones;
    map<int,int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    }
    for(auto [x, y]: mp){
        res = min(res, x * (n - y));
    }
    cout << res << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while(t--) solve();
    return 0;
}