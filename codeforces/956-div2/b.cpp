#include <bits/stdc++.h>

#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m)), b(n, vector<int> (m));
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) a[i][j] = s[j] - '0'; 
    }
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < m; j++) b[i][j] = s[j] - '0'; 
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == b[i][j]) continue;
            if(a[i][j] == 0 && b[i][j] == 2 || a[i][j] == 2 && b[i][j] == 1 || a[i][j] == 1 && b[i][j] == 0){
                
            }
            else if(a[i][j] == 1 && b[i][j] == 2 || a[i][j] == 0 && b[i][j] == 1 || a[i][j] == 2 && b[i][j] == 0){

            }
        }
    }
    
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t = 1; 
    int t; cin >> t;
    while(t--) solve();
    return 0;
}