#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    string a, b;
    cin >> a;
    cin >> b;
    int res = 1e10;
    for(int i = 0; i < n-m+1; i++){
        int cur = 0;
        for(int j = 0; j < m; j++){
            if(a[i+j] != b[j]){
                cur++;
            }
        }
        res = min(res, cur);
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