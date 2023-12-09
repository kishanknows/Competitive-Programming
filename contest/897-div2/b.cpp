#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int minop = 0;
    for(int i = 0; i < n; i++){
        if(s[i] != s[n-i-1]) minop++;
    }
    minop = minop/2;
    string res = "";
    vector<int> chars(n+1, '0');
    if(n%2 == 0){
        bool flag = true;
        for(int i = minop; i < n+1-minop; i++){
            if(flag) chars[i] = '1';
            flag = !flag;
        }
    }
    else{
        for(int i = minop; i < n+1-minop; i++) chars[i] = '1';
    }
    for(int i = 0; i < n + 1; i++) res += chars[i];
    cout << res << endl;

}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}