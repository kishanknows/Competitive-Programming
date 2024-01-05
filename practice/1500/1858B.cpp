#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <numeric>
#include <climits>
#include <iostream>
#include <algorithm>

#define int long long
using namespace std;

void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> shops(m+1), res(m+1);
    int total = 1;
    shops[0] = 1;
    for(int i = 1; i <= m; i++){
        cin >> shops[i];
        if(shops[i] == shops[i-1]){
            res[i] = 0;
        }
        else res[i] = (shops[i] - shops[i-1] - 1)/d + 1;
        total += res[i];
    }
    vector<int> dp(m+1);
    int mn = INT64_MAX;
    for(int i = 1; i < m; i++){
        dp[i] = total - res[i] - res[i+1] + (shops[i+1] - shops[i-1] - 1)/d + 1;
        dp[i] += (n - shops[m])/d;
        mn = min(mn, dp[i]);
    }
    dp[m] = total - res[m];
    dp[m] += (n - shops[m-1])/d;
    mn = min(mn, dp[m]);
    int count = 0;
    for(int i = 1; i <= m; i++){
        if(mn != dp[i]) continue;
        count++;
    }
    cout << mn << " " << count << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}