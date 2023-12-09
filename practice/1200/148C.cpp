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
    for(int i = 0; i < n; i++) cin >> v[i];
    n = unique(v.begin(), v.end()) - v.begin();
    int res = n;
    for(int i = 1; i < n-1; i++){
        res -= v[i] < v[i+1] && v[i] > v[i-1];
        res -= v[i] > v[i+1] && v[i] < v[i-1];
    }
    cout << res << endl;
}