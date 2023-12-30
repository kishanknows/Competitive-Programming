#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    vector<vector<int>> dp(n+1, vector<int> (2, 0));
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        dp[i][0] = max(dp[i+1][0], dp[i+1][1]);
        dp[i][1] = max(dp[i+1][0] + max(0LL, a[i]), dp[i+1][1] + a[i]);
        res = max(res, dp[i][(i+1)&1]);
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