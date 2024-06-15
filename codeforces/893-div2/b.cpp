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
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> v(m);
    for(int i = 0; i < m ;i++) cin >> v[i];
    int res = 0;
    int prev = 0;
    for(int i = 0; i < m; i++){
        res += (v[i] - prev)/d;
        prev = v[i];
    }
    cout << res <<" "<< 1 << endl;

}