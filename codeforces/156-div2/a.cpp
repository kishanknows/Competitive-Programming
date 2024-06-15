#include <vector>
#include <iostream>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    if(n < 7) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}


int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}