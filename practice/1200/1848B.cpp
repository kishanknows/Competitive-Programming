#include <vector>
#include <iostream>
#define int long long
using namespace std;

void solve(void);
int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}

void solve(){
    int n, k, res = 1e9;
    cin >> n >> k;
    vector<int> colors(n);
    for(int i = 0; i < n; i++) cin >> colors[i];

    vector<int> prev(k + 1, -1);
    vector<vector<int> > len(k + 1, vector<int> (2, 0));

    for(int i = 0; i < n ; i++){
        int cur = i - prev[colors[i]]; prev[colors[i]] = i;
        if(cur > len[colors[i]][0]){
            len[colors[i]][1] = len[colors[i]][0];
            len[colors[i]][0] = cur;
        }
        else if(cur > len[colors[i]][1]) len[colors[i]][1] = cur;
    }

    for(int i = 1; i <= k; i++){
        int cur = n - prev[i];
        if(cur > len[i][0]){
            len[i][1] = len[i][0];
            len[i][0] = cur;
        }
        else if(cur > len[i][1]) len[i][1] = cur;
    }

    for(int i = 1; i <= k ; i++){
        int maxi = max((len[i][0]+1)/2, len[i][1]);
        res = min(res, maxi);
    }
    cout<<res-1<<endl;
}