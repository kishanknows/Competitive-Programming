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
    int res = 0, i = 1;
    while(i <= n/2){
        res += i * i;
        i++;
    }
    int maxi = 0;
    while(i < n){
        res += 2*i*(i+1);
        maxi = max(maxi , i*(i+1));
        i+=2;
    }
    cout << res-maxi << endl;
}