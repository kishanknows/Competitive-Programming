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
    if(n%2){
        cout << (n == 1 ? 1 : -1) << endl;
        return;
    }
    for(int i = 0; i < n; i+=2){
        cout << n-i << " " << i+1 << " ";
    }
    cout << endl;
}