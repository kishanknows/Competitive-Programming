#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> dp(n+1);
    for(int i = n-1; i >= 0; i--){
        if(i + a[i] + 1 > n){
            dp[i] = dp[i+1] + 1;
        }
        else dp[i] = min(dp[i+1] + 1, dp[i + a[i] + 1]);
    }
    cout << dp[0] << endl;

}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}