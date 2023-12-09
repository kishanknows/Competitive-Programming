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
    vector<int> vec(n);
    for(int i = 0; i < n; i++) cin>>vec[i];
    int i = n-1;
    while(vec[i] >= vec[i-1]) i--;
    int maxi = 0;
    for(int j = 0; j < i; j++) maxi = max(maxi, vec[j]);
    cout<<maxi<<endl;
}