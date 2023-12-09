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
    int n;
    cin >> n;
    vector<int> a(n);
    unordered_map<int,int> mp;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
        if(mp.size() > 2){
            cout << "NO" << endl;
            return;
        }
    }
    if(mp.size() == 1) cout << "YES" << endl;
    else{
        int diff = abs(mp.begin()->second - next(mp.begin())->second);
        if(diff > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
    }

}

int32_t main(){
    int t; 
    cin >> t;
    cout << endl;
    while(t--) solve();
    return 0;
}