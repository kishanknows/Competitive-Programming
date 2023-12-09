#include <vector>
#include <iostream>
#define int long long
using namespace std;

void solve(void);
int32_t main(){
    int t; 
    cin >> t;
    cout << endl;
    while(t--) solve();
    return 0;
}

void solve(){
    int n;
    cin >> n;
    vector<bool> vis(n+1);
    for(int i = 2; 2*i <= n; i++ ){
        if(vis[i]) continue;
        int num = i;
        while(num <= n){
            vis[num] = true;
            cout << num << " ";
            num += num;
        }
    } 
    for(int i = 1; i <= n ;i++){
        if(!vis[i]) cout << i << " ";
    }
    cout << endl;
}