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
#define mod 998244353
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<int> maxes(n+1);
    for(int i = 1; i <= n; i++){
        for(int j = i-1; j < n; j += i){
            maxes[i] = max(maxes[i], a[j]);
        }
    }
    sort(maxes.begin(), maxes.end());
    int res = 0;
    int cur = 1;
    for(int i = 1; i <= n; i++){
        res = (res + maxes[i]*cur) % mod;
        cur = (cur * 2) % mod;
    }
    cout << res << endl;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t; 
    // cin >> t;
    // while(t--) 
    solve();
    return 0;
}