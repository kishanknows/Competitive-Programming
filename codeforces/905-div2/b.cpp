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
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = INT_MAX;
    if(k == 4){
        int count = 0;
        for(int i = 0; i < n; i++){
            if(a[i]%2 == 0) count++;
        }
        if(count == 0) res = 2;
        else if(count == 1) res = 1;
        else res = 0;
    }
    for(int i = 0; i < n; i++){
        if(a[i] % k == 0){
            cout << 0 << endl;
            return;
        }
        res = min(res, k - a[i]%k);
    }
    cout << res << endl;
}

int32_t main(){
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}