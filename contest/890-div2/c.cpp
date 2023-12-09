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
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin>>v[i];
    int res = 0;
    for(int i = n-1; i >= 0; i--){
        int cur = v[i], count = 0;
        for(int j = i-1; j >= 0; j--){
            if(v[j] <= cur && (count + cur - v[j] + 1) <= k){
                count += cur - v[j];
                cur++;
            }
            else break;
        }
        res = max(res, cur);
    }
    cout<<res<<endl;
}