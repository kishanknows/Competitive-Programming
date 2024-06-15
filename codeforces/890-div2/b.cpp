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
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i =0; i < n; i++) cin>>v[i];
    if(n == 1){ cout<<"NO"<<endl; return;}
    int x = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(v[i] == 1) x++;
        sum += v[i];
    }
    if(sum - n >= x) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}