#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve(){
    int n, k, h;
    cin >> n >> k >> h;
    int res = 0;
    for(int i = 1; i <= n; i++){
        if(i >= h) {
            res += n - h + 1;
            continue;
        }
        int x = n - (h + (i+1)*(k-1))/k + 1;
        res += max(0ll, x);
        // cout << x << endl;
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