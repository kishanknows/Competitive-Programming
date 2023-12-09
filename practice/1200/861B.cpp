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
    int n, m;
    cin >> n >> m;
    vector<vector<int> > chips(m, vector<int> (n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            cin >> chips[j][i];
        }
    }
    int res = 0;
    for(int i = 0; i < m; i++) sort(chips[i].begin(), chips[i].end());
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++) 
            res += j*chips[i][j] - (n-1-j)*chips[i][j];
    }
    cout << res << endl;

}