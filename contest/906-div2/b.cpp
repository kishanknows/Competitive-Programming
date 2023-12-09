#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define int long long
using namespace std;

void solve(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    bool zero = false, one = false;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1] && s[i] == '0') zero = true;
        if(s[i] == s[i-1] && s[i] == '1') one = true;
    }
    if(!zero && !one){
        cout << "YES" << endl;
        return;
    }
    if(zero && one){
        cout << "NO" << endl;
        return;
    }
    for(int i = 1; i < m; i++){
        if(t[i] == t[i-1]){
            cout << "NO" << endl;
            return;
        }
    }
    if(zero && t.front() == '1' && t.back() == '1'){
        cout << "YES" << endl;
        return;
    }
    if(one && t.front() == '0' && t.back() == '0'){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}