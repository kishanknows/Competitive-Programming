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
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        a[i] = {num, i};
    }
    sort(a.begin(), a.end());
    vector<int> res(n);
    for(int i = 0; i < n; i++){
        res[a[i].second] = i+1;
    }
    for(int i = 0; i < n; i++) cout << res[i] << " ";
    cout << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}