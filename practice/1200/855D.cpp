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
    string s;
    cin >> s;
    int res = n-1;
    for(int i = 1; i < n-1; i++) res -= s[i+1] == s[i-1];
    cout << res << endl;
}